//
//  funxmpp_types.h
//  funxmpp
//
//  Created by Leif Middelschulte on 29.08.12.
//  Copyright (c) 2012 Leif Middelschulte. All rights reserved.
//

#ifndef funxmpp_types_h
#define funxmpp_types_h

typedef enum {FUNXMPP_UNKOWN_ZERO, FUNXMPP_STREAM_STREAM, FUNXMPP_UNKOWN_TWO, FUNXMPP_UNKOWN_THREE, FUNXMPP_UNKOWN_FOUR, FUNXMPP_ONE, FUNXMPP_ONE_DOT_ZERO, FUNXMPP_ACK, FUNXMPP_ACTION, FUNXMPP_ACTIVE, FUNXMPP_ADD, FUNXMPP_ALL, FUNXMPP_ALLOW, FUNXMPP_APPLE, FUNXMPP_AUDIO, FUNXMPP_AUTH, FUNXMPP_AUTHOR, FUNXMPP_AVAILABLE, FUNXMPP_BAD_REQUEST, FUNXMPP_BASE64, FUNXMPP_BELL_DOT_CAF, FUNXMPP_BIND, FUNXMPP_BODY, FUNXMPP_BOING_DOT_CAF, FUNXMPP_CANCEL, FUNXMPP_CATEGORY, FUNXMPP_CHALLENGE, FUNXMPP_CHAT, FUNXMPP_CLEAN, FUNXMPP_CODE, FUNXMPP_COMPOSING, FUNXMPP_CONFIG, FUNXMPP_CONFLICT, FUNXMPP_CONTACTS, FUNXMPP_CREATE, FUNXMPP_CREATION, FUNXMPP_DEFAULT, FUNXMPP_DELAY, FUNXMPP_DELETE, FUNXMPP_DELIVERED, FUNXMPP_DENY, FUNXMPP_DIGEST_MD5, FUNXMPP_DIGEST_MD5_1, FUNXMPP_DIRTY, FUNXMPP_EN, FUNXMPP_ENABLE, FUNXMPP_ENCODING, FUNXMPP_ERROR, FUNXMPP_EXPIRATION, FUNXMPP_EXPIRED, FUNXMPP_FAILURE, FUNXMPP_FALSE, FUNXMPP_FAVORITES, FUNXMPP_FEATURE, FUNXMPP_FIELD, FUNXMPP_FREE, FUNXMPP_FROM, FUNXMPP_G_DOT_US, FUNXMPP_GET, FUNXMPP_GLASS_DOT_CAF, FUNXMPP_GOOGLE, FUNXMPP_GROUP, FUNXMPP_GROUPS, FUNXMPP_G_SOUND, FUNXMPP_HARP_DOT_CAF, FUNXMPP_HTTP_SLASH_SLASH_ETHERX_DOT_JABBER_DOT_ORG_SLASH_STREAMS, FUNXMPP_HTTP_SLASH_SLASH_JABBER_DOT_ORG_SLASH_PROTOCOL_SLASH_CHATSTATES, FUNXMPP_ID, FUNXMPP_IMAGE, FUNXMPP_IMG, FUNXMPP_INACTIVE, FUNXMPP_INTERNAL_SERVER_ERROR, FUNXMPP_IQ, FUNXMPP_ITEM, FUNXMPP_ITEM_NOT_FOUND, FUNXMPP_JABBER_CLIENT, FUNXMPP_JABBER_IQ_LAST, FUNXMPP_JABBER_IQ_PRIVACY, FUNXMPP_JABBER_X_DELAY, FUNXMPP_JABBER_X_EVENT, FUNXMPP_JID, FUNXMPP_JID_MALFORMED, FUNXMPP_KIND, FUNXMPP_LEAVE, FUNXMPP_LEAVE_ALL, FUNXMPP_LIST, FUNXMPP_LOCATION, FUNXMPP_MAX_GROUPS, FUNXMPP_MAX_PARTICIPANTS, FUNXMPP_MAX_SUBJECT, FUNXMPP_MECHANISM, FUNXMPP_MECHANISMS, FUNXMPP_MEDIA, FUNXMPP_MESSAGE, FUNXMPP_MESSAGE_ACKS, FUNXMPP_MISSING, FUNXMPP_MODIFY, FUNXMPP_NAME, FUNXMPP_NOT_ACCEPTABLE, FUNXMPP_NOT_ALLOWED, FUNXMPP_NOT_AUTHORIZED, FUNXMPP_NOTIFY, FUNXMPP_OFFLINE_STORAGE, FUNXMPP_ORDER, FUNXMPP_OWNER, FUNXMPP_OWNING, FUNXMPP_PAID, FUNXMPP_PARTICIPANT, FUNXMPP_PARTICIPANTS, FUNXMPP_PARTICIPATING, FUNXMPP_FAIL, FUNXMPP_PAUSED, FUNXMPP_PICTURE, FUNXMPP_PING, FUNXMPP_PLAIN, FUNXMPP_PLATFORM, FUNXMPP_PRESENCE, FUNXMPP_PREVIEW, FUNXMPP_PROBE, FUNXMPP_PROP, FUNXMPP_PROPS, FUNXMPP_P_O, FUNXMPP_P_T, FUNXMPP_QUERY, FUNXMPP_RAW, FUNXMPP_RECEIPT, FUNXMPP_RECEIPT_ACKS, FUNXMPP_RECEIVED, FUNXMPP_RELAY, FUNXMPP_REMOVE, FUNXMPP_REPLACED_BY_NEW_CONNECTION, FUNXMPP_REQUEST, FUNXMPP_RESOURCE, FUNXMPP_RESOURCE_CONSTRAINT, FUNXMPP_RESPONSE, FUNXMPP_RESULT, FUNXMPP_RETRY, FUNXMPP_RIM, FUNXMPP_S_DOT_WHATSAPP_DOT_NET, FUNXMPP_SECONDS, FUNXMPP_SERVER, FUNXMPP_SESSION, FUNXMPP_SET, FUNXMPP_SHOW, FUNXMPP_SID, FUNXMPP_SOUND, FUNXMPP_STAMP, FUNXMPP_STARTTLS, FUNXMPP_STATUS, FUNXMPP_STREAM_ERROR, FUNXMPP_STREAM_FEATURES, FUNXMPP_SUBJECT, FUNXMPP_SUBSCRIBE, FUNXMPP_SUCCESS, FUNXMPP_SYSTEM_SHUTDOWN, FUNXMPP_S_O, FUNXMPP_S_T, FUNXMPP_T, FUNXMPP_TIMEPASSING_DOT_CAF, FUNXMPP_TIMESTAMP, FUNXMPP_TO, FUNXMPP_TRI_TONE_DOT_CAF, FUNXMPP_TYPE, FUNXMPP_UNAVAILABLE, FUNXMPP_URI, FUNXMPP_URL, FUNXMPP_URN_IETF_PARAMS_XML_NS_XMPP_BIND, FUNXMPP_URN_IETF_PARAMS_XML_NS_XMPP_SASL, FUNXMPP_URN_IETF_PARAMS_XML_NS_XMPP_SESSION, FUNXMPP_URN_IETF_PARAMS_XML_NS_XMPP_STANZAS, FUNXMPP_URN_IETF_PARAMS_XML_NS_XMPP_STREAMS, FUNXMPP_URN_XMPP_DELAY, FUNXMPP_URN_XMPP_PING, FUNXMPP_URN_XMPP_RECEIPTS, FUNXMPP_URN_XMPP_WHATSAPP, FUNXMPP_URN_XMPP_WHATSAPP_DIRTY, FUNXMPP_URN_XMPP_WHATSAPP_MMS, FUNXMPP_URN_XMPP_WHATSAPP_PUSH, FUNXMPP_VALUE, FUNXMPP_VCARD, FUNXMPP_VERSION, FUNXMPP_VIDEO, FUNXMPP_W, FUNXMPP_W_G, FUNXMPP_W_P_R, FUNXMPP_WAIT, FUNXMPP_X, FUNXMPP_XML_NOT_WELL_FORMED, FUNXMPP_XML_LANG, FUNXMPP_XMLNS, FUNXMPP_XMLNS_STREAM, FUNXMPP_XYLOPHONE_DOT_CAF, FUNXMPP_ACCOUNT, FUNXMPP_DIGEST, FUNXMPP_G_NOTIFY, FUNXMPP_METHOD, FUNXMPP_PASSWORD, FUNXMPP_REGISTRATION, FUNXMPP_STAT, FUNXMPP_TEXT, FUNXMPP_USER, FUNXMPP_USERNAME, FUNXMPP_EVENT, FUNXMPP_LATITUDE, FUNXMPP_LONGITUDE, FUNXMPP_TRUE, FUNXMPP_AFTER, FUNXMPP_BEFORE, FUNXMPP_BROADCAST, FUNXMPP_COUNT, FUNXMPP_FEATURES, FUNXMPP_FIRST, FUNXMPP_INDEX, FUNXMPP_INVALID_MECHANISM, FUNXMPP_LAST, FUNXMPP_MAX, FUNXMPP_OFFLINE, FUNXMPP_PROCEED, FUNXMPP_REQUIRED, FUNXMPP_SYNC, FUNXMPP_ELAPSED, FUNXMPP_IP, FUNXMPP_MICROSOFT, FUNXMPP_MUTE, FUNXMPP_NOKIA, FUNXMPP_OFF, FUNXMPP_PIN, FUNXMPP_POP_MEAN_TIME, FUNXMPP_POP_PLUS_MINUS, FUNXMPP_PORT, FUNXMPP_REASON, FUNXMPP_SERVER_ERROR, FUNXMPP_SILENT, FUNXMPP_TIMEOUT, FUNXMPP_LC, FUNXMPP_LG, FUNXMPP_BAD_PROTOCOL, FUNXMPP_NONE, FUNXMPP_REMOTE_SERVER_TIMEOUT, FUNXMPP_SERVICE_UNAVAILABLE, FUNXMPP_W_P, FUNXMPP_W_PROFILE_PICTURE, FUNXMPP_NOTIFICATION} FunXMPP_Enc_Byte_Values;

NSString *funxmpp_enc[256] = {nil, @"stream:stream", nil, nil, nil, @"1", @"1.0", @"ack", @"action", @"active", @"add", @"all", @"allow", @"apple", @"audio", @"auth", @"author", @"available", @"bad-request", @"base64", @"Bell.caf", @"bind", @"body", @"Boing.caf", @"cancel", @"category", @"challenge", @"chat", @"clean", @"code", @"composing", @"config", @"conflict", @"contacts", @"create", @"creation", @"default", @"delay", @"delete", @"delivered", @"deny", @"DIGEST-MD5", @"DIGEST-MD5-1", @"dirty", @"en", @"enable", @"encoding", @"error", @"expiration", @"expired", @"failure", @"false", @"favorites", @"feature", @"field", @"free", @"from", @"g.us", @"get", @"Glass.caf", @"google", @"group", @"groups", @"g_sound", @"Harp.caf", @"http://etherx.jabber.org/streams", @"http://jabber.org/protocol/chatstates", @"id", @"image", @"img", @"inactive", @"internal-server-error", @"iq", @"item", @"item-not-found", @"jabber:client", @"jabber:iq:last", @"jabber:iq:privacy", @"jabber:x:delay", @"jabber:x:event", @"jid", @"jid-malformed", @"kind", @"leave", @"leave-all", @"list", @"location", @"max_groups", @"max_participants", @"max_subject", @"mechanism", @"mechanisms", @"media", @"message", @"message_acks", @"missing", @"modify", @"name", @"not-acceptable", @"not-allowed", @"not-authorized", @"notify", @"Offline Storage", @"order", @"owner", @"owning", @"paid", @"participant", @"participants", @"participating", @"fail", @"paused", @"picture", @"ping", @"PLAIN", @"platform", @"presence", @"preview", @"probe", @"prop", @"props", @"p_o", @"p_t", @"query", @"raw", @"receipt", @"receipt_acks", @"received", @"relay", @"remove", @"Replaced by new connection", @"request", @"resource", @"resource-constraint", @"response", @"result", @"retry", @"rim", @"s.whatsapp.net", @"seconds", @"server", @"session", @"set", @"show", @"sid", @"sound", @"stamp", @"starttls", @"status", @"stream:error", @"stream:features", @"subject", @"subscribe", @"success", @"system-shutdown", @"s_o", @"s_t", @"t", @"TimePassing.caf", @"timestamp", @"to", @"Tri-tone.caf", @"type", @"unavailable", @"uri", @"url", @"urn:ietf:params:xml:ns:xmpp-bind", @"urn:ietf:params:xml:ns:xmpp-sasl", @"urn:ietf:params:xml:ns:xmpp-session", @"urn:ietf:params:xml:ns:xmpp-stanzas", @"urn:ietf:params:xml:ns:xmpp-streams", @"urn:xmpp:delay", @"urn:xmpp:ping", @"urn:xmpp:receipts", @"urn:xmpp:whatsapp", @"urn:xmpp:whatsapp:dirty", @"urn:xmpp:whatsapp:mms", @"urn:xmpp:whatsapp:push", @"value", @"vcard", @"version", @"video", @"w", @"w:g", @"w:p:r", @"wait", @"x", @"xml-not-well-formed", @"xml:lang", @"xmlns", @"xmlns:stream", @"Xylophone.caf", @"account", @"digest", @"g_notify", @"method", @"password", @"registration", @"stat", @"text", @"user", @"username", @"event", @"latitude", @"longitude", @"true", @"after", @"before", @"broadcast", @"count", @"features", @"first", @"index", @"invalid-mechanism", @"last", @"max", @"offline", @"proceed", @"required", @"sync", @"elapsed", @"ip", @"microsoft", @"mute", @"nokia", @"off", @"pin", @"pop_mean_time", @"pop_plus_minus", @"port", @"reason", @"server-error", @"silent", @"timeout", @"lc", @"lg", @"bad-protocol", @"none", @"remote-server-timeout", @"service-unavailable", @"w:p", @"w:profile:picture", @"notification"};

#endif