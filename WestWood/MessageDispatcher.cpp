//
//  MessageDispatcher.cpp
//  WestWood
//
//  Created by 林光海 on 13-10-29.
//  Copyright (c) 2013年 林光海. All rights reserved.
//

#include "MessageDispatcher.h"
#include "BaseGameEntity.h"
#include "EntityManager.h"
#include "EntityNames.h"
#include "Location.h"
#include "MessageTypes.h"

#include <iostream>
using namespace std;

MessageDispatcher* MessageDispatcher::Instance()
{
    static MessageDispatcher instance;
    return &instance;
}

void MessageDispatcher::Discharge(BaseGameEntity *pReceiver, const Telegram &msg)
{
    if(!pReceiver->HandleMessage(msg))
    {
        cout << "Message not handled";
    }
}

void MessageDispatcher::DispatchMessage(double delay, int sender, int receiver, int msg, void *ExtraInfo)
{
    BaseGameEntity* pSender = EntityMgr->GetEntityFromID(sender);
    BaseGameEntity* pReceiver = EntityMgr->GetEntityFromID(receiver);
    
    if(pReceiver == NULL)
    {
        cout << "\nWarning! No Receiver with ID of" << receiver << "found!";
        return;
    }
    Telegram telegram(0, sender, receiver, msg, ExtraInfo);
    if(delay <= 0.0f)
    {
        cout << "\nInstant telegrame dispacted at time:" << time(NULL) << " by " << GetNameOfEntity(pSender->ID()) << " for " << GetNameOfEntity(pReceiver->ID()) << ". Msg is " << MsgToStr(msg);
        Discharge(pReceiver, telegram);
    }else{
        unsigned long int currentTime = time(NULL);
        telegram.DispatchTime = currentTime + delay;
        PriorityQ.insert(telegram);
        cout << "\nDelayed telegram from " << GetNameOfEntity(pSender->ID()) << " recorded at time "
            << time(NULL) << " for " << GetNameOfEntity(pReceiver->ID())
            << ". Msg is "<< MsgToStr(msg);
    }
    
}

void MessageDispatcher::DispatchDelayedMessage()
{
    double CurrentTime = time(NULL);
    
    while(!PriorityQ.empty() && (PriorityQ.begin()->DispatchTime < CurrentTime) && (PriorityQ.begin()->DispatchTime > 0))
    {
        const Telegram& telegram = *PriorityQ.begin();
        
        BaseGameEntity* pReceiver = EntityMgr->GetEntityFromID(telegram.Receiver);
        
        cout << "\nQueued telegram ready for dispatch: Sent to "
            << GetNameOfEntity(pReceiver->ID()) << ". Msg is " << MsgToStr(telegram.Msg);
        
        Discharge(pReceiver, telegram);
        
        PriorityQ.erase(PriorityQ.begin());
    }
}


