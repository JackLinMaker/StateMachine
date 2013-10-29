//
//  VisitBankAndDepositGold.h
//  WestWood
//
//  Created by 林光海 on 13-10-26.
//  Copyright (c) 2013年 林光海. All rights reserved.
//

#ifndef __WestWood__VisitBankAndDepositGold__
#define __WestWood__VisitBankAndDepositGold__

#include <iostream>
#include "State.h"
#include "Miner.h"
#include "Location.h"
#include "EntityNames.h"
using namespace std;

class VisitBankAndDepositGold : public State<Miner> {
public:
    static VisitBankAndDepositGold* Instance();
    
    virtual void Enter(Miner* pMiner);
    
    virtual void Execute(Miner* pMiner);
    
    virtual void Exit(Miner* pMiner);
private:
    VisitBankAndDepositGold();
    
    VisitBankAndDepositGold(const VisitBankAndDepositGold&);
    
    VisitBankAndDepositGold& operator=(const VisitBankAndDepositGold&);
};

#endif /* defined(__WestWood__VisitBankAndDepositGold__) */
