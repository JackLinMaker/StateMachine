//
//  GoHomeAndSleepTilRested.cpp
//  WestWood
//
//  Created by 林光海 on 13-10-26.
//  Copyright (c) 2013年 林光海. All rights reserved.
//

#include "GoHomeAndSleepTillRested.h"
#include "EnterMineAndDigForNugget.h"

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