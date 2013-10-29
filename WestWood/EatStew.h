//
//  EatStew.h
//  WestWood
//
//  Created by 林光海 on 13-10-29.
//  Copyright (c) 2013年 林光海. All rights reserved.
//

#ifndef __WestWood__EatStew__
#define __WestWood__EatStew__

#include <iostream>

#include "State.h"
using namespace std;

class Miner;

class EatStew : public State<Miner> {
public:
    static EatStew* Instance();
    
    virtual void Enter(Miner* pMiner);
    
    virtual void Execute(Miner* pMiner);
    
    virtual void Exit(Miner* pMiner);
    
    virtual bool OnMessage(Miner* agent, const Telegram& msg);
    
private:
    EatStew();
    
    EatStew(const EatStew&);
    
    EatStew& operator=(const EatStew&);
    
};

#endif /* defined(__WestWood__EatStew__) */
