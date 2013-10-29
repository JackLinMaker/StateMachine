//
//  QuenchThirst.cpp
//  WestWood
//
//  Created by 林光海 on 13-10-26.
//  Copyright (c) 2013年 林光海. All rights reserved.
//

#include "QuenchThirst.h"
#include "EnterMineAndDigForNugget.h"

QuenchThirst::QuenchThirst()
{

}

QuenchThirst* QuenchThirst::Instance()
{
    static QuenchThirst instance;
    return &instance;
}

void QuenchThirst::Enter(Miner *pMiner)
{
    if(pMiner->Location() != saloon)
    {
        pMiner->ChangeLocation(saloon);
        
        cout << "\n" << GetNameOfEntity(pMiner->ID()) << ": " << "Boy, ah sure is thusty! Walking to the saloon";
    }
}

void QuenchThirst::Execute(Miner *pMiner)
{
    if(pMiner->Thirsty())
    {
        pMiner->BuyAndDrinkAWhiskey();
        
        cout << "\n" << GetNameOfEntity(pMiner->ID()) << ": " << "That's mighty fine sippin liquer";
        
        pMiner->GetFSM()->ChangeState(EnterMineAndDigForNugget::Instance());
    }
    else
    {
        cout << "\nERROR!\nERROR!\nERROR!";
    }
}

void QuenchThirst::Exit(Miner *pMiner)
{
    cout << "\n" << GetNameOfEntity(pMiner->ID()) << ": " << "Leaving the saloon, feelin' good";
}

bool QuenchThirst::OnMessage(Miner *agent, const Telegram &msg)
{
    return false;
}