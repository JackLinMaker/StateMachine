//
//  EatStew.cpp
//  WestWood
//
//  Created by 林光海 on 13-10-29.
//  Copyright (c) 2013年 林光海. All rights reserved.
//

#include "EatStew.h"
#include "Miner.h"
#include "EntityNames.h"
EatStew::EatStew()
{
    
}

EatStew* EatStew::Instance()
{
    static EatStew instance;
    return &instance;
}

void EatStew::Enter(Miner *pMiner)
{
    cout << "\n" << GetNameOfEntity(pMiner->ID()) << ": " << "Smells Reaaal goood Elsa!";
}

void EatStew::Execute(Miner *pMiner)
{
    cout << "\n" << GetNameOfEntity(pMiner->ID()) << ": " << "Tastes real good too!";
    
    pMiner->GetFSM()->RevertToPreviousState();
}

void EatStew::Exit(Miner *pMiner)
{
    cout << "\n" << GetNameOfEntity(pMiner->ID()) << ": " << "Thankya li'lle lady. Ah better get back to whatever ah wuz doin'";
}

bool EatStew::OnMessage(Miner *agent, const Telegram &msg)
{
    return false;
}