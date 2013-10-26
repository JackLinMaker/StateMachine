//
//  GoHomeAndSleepTilRested.h
//  WestWood
//
//  Created by 林光海 on 13-10-26.
//  Copyright (c) 2013年 林光海. All rights reserved.
//

#ifndef __WestWood__GoHomeAndSleepTilRested__
#define __WestWood__GoHomeAndSleepTilRested__

#include <iostream>
#include "State.h"
#include "Miner.h"
#include "Location.h"
#include "EntityNames.h"
using namespace std;

class GoHomeAndSleepTillRested : public State {
public:
    static GoHomeAndSleepTillRested* Instance();
    
    virtual void Enter(Miner* pMiner);
    
    virtual void Execute(Miner* pMiner);
    
    virtual void Exit(Miner* pMiner);
private:
    GoHomeAndSleepTillRested();
    
    GoHomeAndSleepTillRested(const GoHomeAndSleepTillRested&);
    
    GoHomeAndSleepTillRested& operator=(const GoHomeAndSleepTillRested&);
};


#endif /* defined(__WestWood__GoHomeAndSleepTilRested__) */
