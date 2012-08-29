//
//  decoder.m
//  funxmpp
//  Decoding is done in a hackish way.
//  Instead of manually creating a string,
//  a xml doc or node should be created
//
//  Created by Leif Middelschulte on 29.08.12.
//  Copyright (c) 2012 Leif Middelschulte. All rights reserved.
//

#import "decoder.h"
#import "funxmpp_types.h"

#define FUNXMPP_LIST_TAG(m,i) ([m characterAtIndex:i] == FUNXMPP_LIST_8)
#define FUNXMPP_IS_LIST(m) FUNXMPP_LIST_TAG(m,2)
#define FUNXMPP_HAS_VALID_OPEN_TAG(m) FUNXMPP_IS_LIST(m)
#define FUNXMPP_IS_STREAM_OPEN(m) ([m characterAtIndex:2] == FUNXMPP_STREAM_STREAM)
#define FUNXMPP_GET_MESSAGE_LENGTH(m) ((NSInteger)[m characterAtIndex:1])

@implementation decoder

NSString *get_val_decode(NSString *message, NSInteger *ret_length)
{
    /*
     Returns a single item for the decoding process, including it's length
     in bytes
     Possible items include: JID pair, string, long string and a keyword byte
     */
    NSInteger vallen, vallen1, vallen2, ind;
    NSString *val, *val1, *val2;
    switch ([message characterAtIndex:0]) {
        case FUNXMPP_JID_PAIR:
            val1 = get_val_decode([message substringFromIndex:1], &vallen1);
            val2 = get_val_decode([message substringFromIndex:(1 + vallen1)], &vallen2);
            if (ret_length)
                *ret_length = (vallen1 + vallen2 + 1);
            return [NSString stringWithFormat:@"%@@%@", val1, val2];
            break;
        case FUNXMPP_BINARY_8:
            //It's a string
            vallen = FUNXMPP_GET_MESSAGE_LENGTH(message);
            val = [message substringWithRange:NSMakeRange(2, vallen)];
            
            if (ret_length)
                *ret_length = (vallen + 2);
            return val;
            break;
        case FUNXMPP_BINARY_24:
            // String, length is encoded in the next three bytes
            vallen = ([message characterAtIndex:1] << 16) | \
                      ([message characterAtIndex:2] << 8) | \
                      ([message characterAtIndex:3] << 0);
            val = [message substringWithRange:NSMakeRange(4, vallen)];
            
            if (ret_length)
                *ret_length = (vallen + 2);
            return val1;
            break;
        default:
            ind = [message characterAtIndex:0];
            if ((ind < 0x05) && (ind != 0x01)) {
                NSLog(@"WARNING, get_val enc reading %lx", ind);
                if (ret_length)
                    *ret_length = 1;
                return @"0";
            }
            if (ind > 0xf2) {
                NSLog(@"Structure char not implemented: %lx", ind);
                exit(-1);
            }
            if (ret_length)
                *ret_length = 1;
            return funxmpp_enc[ind];
            break;
    }
}

// Returns a decoded version of a given message 'message'
// optionally returns the number of decoded bytes
NSString *decode_with_len(NSString *message, NSInteger *ret_length)
{
    NSString *ret = [[NSString alloc] init];

    if (FUNXMPP_HAS_VALID_OPEN_TAG(message))
    {
        NSLog(@"The opening tag is missing a list declarator."
              "Found %x instead of %x.", [message characterAtIndex:0], FUNXMPP_LIST_8);
        exit(-1);
    }
    NSInteger size = FUNXMPP_GET_MESSAGE_LENGTH(message);
    NSInteger l, pos;
    if ([message characterAtIndex:2 == FUNXMPP_LIST_8])
    {
        /*
         This node is a virtual, only there for bookkeeping
         about the number of following tags.
         Its content will be converted recursively
         */
        pos = 2;
        
        for (unsigned int i = 0; i < size; i++)
        {
            NSString *decoded_sub_message = decode_with_len([message substringFromIndex:pos], &l);
            [ret stringByAppendingString:decoded_sub_message];
            pos += l;
        }
        if (ret_length)
            *ret_length = pos;
        return ret;
    }
    
    ret = @"<";

    NSString *tagname = get_val_decode([message substringFromIndex:2], &l);
    
    ret = [ret stringByAppendingString:tagname];
    
    NSInteger attribs = (size - 2 + (size & 1)) / 2;
    
    pos = 2 + l;
    
    for (unsigned i = 0; i < attribs; i++)
    {
        NSString *val;
        NSInteger valbytes;
        ret = [ret stringByAppendingString:@" "];
        val = get_val_decode([message substringFromIndex:pos], &valbytes);
        ret = [ret stringByAppendingString:val];
        pos += valbytes;
        
        val = get_val_decode([message substringFromIndex:pos], &valbytes);
        ret = [ret stringByAppendingFormat:@"=\"%@\"", val];
        pos += valbytes;
    }

    
    if ((size % 2) == 0) {
        ret = [ret stringByAppendingString:@">"];
        if ([message characterAtIndex:pos] == FUNXMPP_LIST_8) {
            NSString *m = decode_with_len([message substringFromIndex:pos], &l);
            ret = [ret stringByAppendingString:m];
        } else {
            NSString *val = get_val_decode([message substringFromIndex:pos], &l);
            ret = [ret stringByAppendingString:val];
        }
        pos += l;
        ret = [ret stringByAppendingFormat:@"</%@>", tagname];
    } else {
        
        ret = [ret stringByAppendingString:@" />"];
    }
    if (ret_length)
        *ret_length = pos;
    return ret;
}

NSString *decode(NSString *message)
{
    NSString *decoded_message = decode_with_len(message, nil);
    /*
     Usually FunXMPP uses a list(length,contents) schemata
     to encode nodes implying every node is closed.
     This shall not apply for the opening tag (<stream:stream ...>),
     since the entire conversation is embedded into it.
     Therfore we need to replace the generated "/>" by a ">" for
     this special tag.
     */
    if (FUNXMPP_IS_STREAM_OPEN(message))
    {
        decoded_message = [decoded_message substringToIndex:([decoded_message length] - 3)];
        decoded_message = [decoded_message stringByAppendingString:@">"];
    }
    
    return decoded_message;
}
@end
