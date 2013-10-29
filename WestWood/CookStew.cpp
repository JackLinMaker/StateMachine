//
//  CookStew.cpp
//  WestWood
//
//  Created by 林光海 on 13-10-29.
//  Copyright (c) 2013年 林光海. All rights reserved.
//

#include "CookStew.h"
#include "MinersWife.h"
#include "EntityNames.h"
#include "MessageDispatcher.h"
#include "MessageTypes.h"
#include "DoHouseWork.h"

CookStew* CookStew::Instance()
{
    static CookStew instance;
    return &instance;
}

void CookStew::Enter(MinersWife *wife)
{
    if(!wife->Cooking())
    {
        cout << "\n" << GetNameOfEntity(wife->ID()) << ": Putting the stew in the oven";
        Dispatch->DispatchMessage(1.5,                  //time delay
                                  wife->ID(),           //sender ID
                                  wife->ID(),           //receiver ID
                                  Msg_StewReady,        //msg
                                  NO_ADDITIONAL_INFO);
        wife->SetCooking(true);
    }
}

void CookStew::Execute(MinersWife *wife)
{
    cout << "\n" << GetNameOfEntity(wife->ID()) << ": Fussin' over food";
}

void CookStew::Exit(MinersWife *wife)
{
    cout << "\n" << GetNameOfEntity(wife->ID()) << ": Puttin' the stew on the table";
}

bool CookStew::OnMessage(MinersWife *wife, const Telegram &msg)
{
    switch (msg.Msg) {
        case Msg_StewReady:
        {
            cout << "\nMessage received by " << GetNameOfEntity(wife->ID()) << " at time: " << time(NULL);
            Dispatch->DispatchMessage(SEND_MSG_IMMEDIATELY,
                                      wife->ID(),
                                      ent_Miner_Bob,
                                      Msg_StewReady,
                                      NO_ADDITIONAL_INFO);
            
            wife->SetCooking(false);
            
            wife->GetFSM()->ChangeState(DoHouseWork::Instance());
        }
        return true;
            
            
    }
    return false;
}