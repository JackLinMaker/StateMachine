//
//  WifesGlobalState.cpp
//  WestWood
//
//  Created by 林光海 on 13-10-29.
//  Copyright (c) 2013年 林光海. All rights reserved.
//

#include "WifesGlobalState.h"
#include "MinersWife.h"
#include "EntityNames.h"
#include "Location.h"
#include "VisitBathroom.h"
#include "Common.h"
#include "MessageTypes.h"
#include "CookStew.h"
WifesGlobalState* WifesGlobalState::Instance()
{
    static WifesGlobalState instance;
    return &instance;
}

void WifesGlobalState::Execute(MinersWife *wife)
{
    if(RandFloat() < 0.1)
    {
        wife->GetFSM()->ChangeState(VisitBathroom::Instance());
    }
}

bool WifesGlobalState::OnMessage(MinersWife *wife, const Telegram &msg)
{
    switch (msg.Msg) {
        case Msg_HiHoneyImHome:
        {
            cout << "\nMessage handled by " << GetNameOfEntity(wife->ID()) << " at time: " << time(NULL);
            cout << "\n" << GetNameOfEntity(wife->ID()) <<
            ": Hi honey. Let me make you some of mah fine country stew";
            wife->GetFSM()->ChangeState(CookStew::Instance());
        }
        return true;
         
    }
    return false;
}