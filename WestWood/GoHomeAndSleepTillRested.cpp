//
//  GoHomeAndSleepTilRested.cpp
//  WestWood
//
//  Created by 林光海 on 13-10-26.
//  Copyright (c) 2013年 林光海. All rights reserved.
//

#include "GoHomeAndSleepTillRested.h"
#include "EnterMineAndDigForNugget.h"
#include "EatStew.h"
#include "MessageTypes.h"
#include "MessageDispatcher.h"

GoHomeAndSleepTillRested::GoHomeAndSleepTillRested()
{

}

GoHomeAndSleepTillRested* GoHomeAndSleepTillRested::Instance()
{
    static GoHomeAndSleepTillRested instance;
    return &instance;
}

void GoHomeAndSleepTillRested::Enter(Miner *pMiner)
{
    if(pMiner->Location() != shack)
    {
        cout << "\n" << GetNameOfEntity(pMiner->ID()) << ": " << "Walkin' home";
        
        pMiner->ChangeLocation(shack);
        
        Dispatch->DispatchMessage(SEND_MSG_IMMEDIATELY, //time delay
                                  pMiner->ID(),        //ID of sender
                                  ent_Elsa,            //ID of recipient
                                  Msg_HiHoneyImHome,   //the message
                                  NO_ADDITIONAL_INFO);
    }
}

void GoHomeAndSleepTillRested::Execute(Miner *pMiner)
{
    if(!pMiner->Fatigued())
    {
        cout << "\n" << GetNameOfEntity(pMiner->ID()) << ": "
        << "What a God darn fantastic nap! Time to find more gold";
        
        pMiner->GetFSM()->ChangeState(EnterMineAndDigForNugget::Instance());
    }else
    {
        pMiner->DecreaseFatigue();
        cout << "\n" << GetNameOfEntity(pMiner->ID()) << ": " << "ZZZZ... ";
    }
}

void GoHomeAndSleepTillRested::Exit(Miner *pMiner)
{
    cout << "\n" << GetNameOfEntity(pMiner->ID()) << ": " << "Leaving the house";
}

bool GoHomeAndSleepTillRested::OnMessage(Miner *agent, const Telegram &msg)
{
    switch (msg.Msg) {
        case Msg_StewReady:
            cout << "\nMessage handled by " << GetNameOfEntity(agent->ID())
                << " at time: " << time(NULL);
            cout << "\n" << GetNameOfEntity(agent->ID()) << ": okay , i'm comin!";
            agent->GetFSM()->ChangeState(EatStew::Instance());
            return true;
    }
    return false;
}