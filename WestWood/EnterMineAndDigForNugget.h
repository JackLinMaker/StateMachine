//
//  EnterMineAndDigForNugget.h
//  WestWood
//
//  Created by 林光海 on 13-10-26.
//  Copyright (c) 2013年 林光海. All rights reserved.
//

#ifndef __WestWood__EnterMineAndDigForNugget__
#define __WestWood__EnterMineAndDigForNugget__

#include <iostream>
#include "State.h"
using namespace std;

class Miner;

class EnterMineAndDigForNugget : public State<Miner> {
public:
    static EnterMineAndDigForNugget* Instance();
    
    virtual void Enter(Miner* pMiner);
    
    virtual void Execute(Miner* pMiner);
    
    virtual void Exit(Miner* pMiner);
    
private:
    EnterMineAndDigForNugget();
    
    EnterMineAndDigForNugget(const EnterMineAndDigForNugget&);
    
    EnterMineAndDigForNugget& operator=(const EnterMineAndDigForNugget&);
    
};

#endif /* defined(__WestWood__EnterMineAndDigForNugget__) */
