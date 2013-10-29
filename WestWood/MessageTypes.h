//
//  MessageTypes.h
//  WestWood
//
//  Created by 林光海 on 13-10-29.
//  Copyright (c) 2013年 林光海. All rights reserved.
//

#ifndef WestWood_MessageTypes_h
#define WestWood_MessageTypes_h
#include <string>

enum message_type
{
    Msg_HiHoneyImHome,
    Msg_StewReady,
};

inline std::string MsgToStr(int msg)
{
    switch (msg) {
        case Msg_HiHoneyImHome:
            return "HiHoneyImHome";
            break;
        case Msg_StewReady:
            return "StewReady";
            break;
            
        default:
            return "Not recognized!";
    }
}


#endif
