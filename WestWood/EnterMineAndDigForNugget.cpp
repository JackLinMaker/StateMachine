//
//  EnterMineAndDigForNugget.cpp
//  WestWood
//
//  Created by 林光海 on 13-10-26.
//  Copyright (c) 2013年 林光海. All rights reserved.
//

#include "EnterMineAndDigForNugget.h"
#include "VisitBankAndDepositGold.h"
#include "QuenchThirst.h"
EnterMineAndDigForNugget::EnterMineAndDigForNugget()
{

}

EnterMineAndDigForNugget* EnterMineAndDigForNugget::Instance()
{
    static EnterMineAndDigForNugget instance;
    return &instance;
}

void EnterMineAndDigForNugget::Enter(Miner *pMiner)
{
    if(pMiner->Location() != goldmine)
    {
        cout << "\n" << GetNameOfEntity(pMiner->ID()) << ": " << "Walkin' to the gold mine";
        pMiner->ChangeLocation(goldmine);
        
    }
}

void EnterMineAndDigForNugget::Execute(Miner *pMiner)
{
    pMiner->AddToGoldCarried(1);
    pMiner->IncreaseFatigue();
    cout << "\n" << GetNameOfEntity(pMiner->ID()) << ": " << "Pickin' up a nugget.";
    if(pMiner->PocketsFull())
    {
        pMiner->GetFSM()->ChangeState(VisitBankAndDepositGold::Instance());
    }
    
    if(pMiner->Thirsty())
    {
        pMiner->GetFSM()->ChangeState(QuenchThirst::Instance());
    }
}

void EnterMineAndDigForNugget::Exit(Miner *pMiner)
{
    cout << "\n" << GetNameOfEntity(pMiner->ID()) << ": " << "Ah'm leavin' the gold with mah pockets full of sweet gold!";
}

bool EnterMineAndDigForNugget::OnMessage(Miner *agent, const Telegram &msg)
{
    return false;
}