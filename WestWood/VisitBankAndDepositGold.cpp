//
//  VisitBankAndDepositGold.cpp
//  WestWood
//
//  Created by 林光海 on 13-10-26.
//  Copyright (c) 2013年 林光海. All rights reserved.
//

#include "VisitBankAndDepositGold.h"
#include "GoHomeAndSleepTillRested.h"
#include "EnterMineAndDigForNugget.h"

VisitBankAndDepositGold::VisitBankAndDepositGold()
{

}

VisitBankAndDepositGold* VisitBankAndDepositGold::Instance()
{
    static VisitBankAndDepositGold instance;
    return &instance;
}

void VisitBankAndDepositGold::Enter(Miner *pMiner)
{
    if(pMiner->Location() != bank)
    {
        cout << "\n" << GetNameOfEntity(pMiner->ID()) << ": " << "Goin' to the bank. Yes siree";
        
        pMiner->ChangeLocation(bank);
    }
}

void VisitBankAndDepositGold::Execute(Miner *pMiner)
{
    pMiner->AddToWealth(pMiner->GoldCarried());
    
    pMiner->SetGoldCarried(0);
    
    cout << "\n" << GetNameOfEntity(pMiner->ID()) << ": "
    << "Depositing gold. Total savings now: "<< pMiner->Wealth();
    
    if(pMiner->Wealth() >= ComfortLevel)
    {
        cout << "\n" << GetNameOfEntity(pMiner->ID()) << ": "
        << "WooHoo! Rich enough for now. Back home to mah li'lle lady";
        
        pMiner->GetFSM()->ChangeState(GoHomeAndSleepTillRested::Instance());
    }
    else
    {
        pMiner->GetFSM()->ChangeState(EnterMineAndDigForNugget::Instance());
    }
}

void VisitBankAndDepositGold::Exit(Miner *pMiner)
{
    cout << "\n" << GetNameOfEntity(pMiner->ID()) << ": " << "Leavin' the bank";
}

bool VisitBankAndDepositGold::OnMessage(Miner *agent, const Telegram &msg)
{
    return false;
}