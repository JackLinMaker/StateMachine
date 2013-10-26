//
//  State.h
//  WestWood
//
//  Created by 林光海 on 13-10-26.
//  Copyright (c) 2013年 林光海. All rights reserved.
//

#ifndef __WestWood__State__
#define __WestWood__State__

#include <iostream>
#include "Miner.h"

class State {
public:
    virtual ~State();
    virtual void Enter(Miner*) = 0;
    virtual void Execute(Miner*) = 0;
    virtual void Exit(Miner*) = 0;
};

#endif /* defined(__WestWood__State__) */
