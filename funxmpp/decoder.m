//
//  decoder.m
//  funxmpp
//
//  Created by Leif Middelschulte on 29.08.12.
//  Copyright (c) 2012 Leif Middelschulte. All rights reserved.
//

#import "decoder.h"
#import "Foundation/NSXMLDocument.h"
#import "funxmpp_types.h"

@implementation decoder

NSString *decode_with_len(NSString *message)
{
    if ([message characterAtIndex:0] != FUNXMPP_LC) {
        NSLog(@"The opening tag is missing a list declarator."
              "Found %x instead of %x.", [message characterAtIndex:0], FUNXMPP_LC);
    }
    
    return nil;
}

NSString *decode(NSString *message)
{
    NSString *decoded_message = decode_with_len(message);
    /*
     Usually FunXMPP uses a list(length,contents) schemata
     to encode nodes implying every node is closed.
     This shall not apply for the opening tag (<stream:stream ...>),
     since the entire conversation is embedded into it.
     Therfore we need to replace the generated "/>" by a ">" for
     this special tag.
     */
    if ([message characterAtIndex:2] == FUNXMPP_STREAM_STREAM)
    {
        decoded_message = [decoded_message substringToIndex:([decoded_message length] - 3)];
        decoded_message = [decoded_message stringByAppendingString:@">"];
    }
    
    return decoded_message;
}
@end
