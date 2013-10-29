//
//  WifesGlobalState.h
//  WestWood
//
//  Created by 林光海 on 13-10-29.
//  Copyright (c) 2013年 林光海. All rights reserved.
//

#ifndef __WestWood__WifesGlobalState__
#define __WestWood__WifesGlobalState__

#include <iostream>
#include "State.h"
using namespace std;

class MinersWife;

class WifesGlobalState : public State<MinersWife> {
public:
    static WifesGlobalState* Instance();
    
    virtual void Enter(MinersWife* wife){};
    
    virtual void Execute(MinersWife* wife);
    
    virtual void Exit(MinersWife* wife){};
    
    virtual bool OnMessage(MinersWife* wife, const Telegram& msg);
private:
    WifesGlobalState(){};
    
    WifesGlobalState(const WifesGlobalState&);
    
    WifesGlobalState& operator=(const WifesGlobalState&);
};

#endif /* defined(__WestWood__WifesGlobalState__) */
