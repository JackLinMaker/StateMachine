//
//  QuenchThirst.h
//  WestWood
//
//  Created by 林光海 on 13-10-26.
//  Copyright (c) 2013年 林光海. All rights reserved.
//

#ifndef __WestWood__QuenchThirst__
#define __WestWood__QuenchThirst__

#include <iostream>
#include "State.h"
#include "Miner.h"
#include "Location.h"
#include "EntityNames.h"
using namespace std;

class QuenchThirst : public State {
public:
    static QuenchThirst* Instance();
    
    virtual void Enter(Miner* pMiner);
    
    virtual void Execute(Miner* pMiner);
    
    virtual void Exit(Miner* pMiner);
private:
    QuenchThirst();
    
    QuenchThirst(const QuenchThirst&);
    
    QuenchThirst& operator=(const QuenchThirst&);

};
#endif /* defined(__WestWood__QuenchThirst__) */
