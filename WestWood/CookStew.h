//
//  CookStew.h
//  WestWood
//
//  Created by 林光海 on 13-10-29.
//  Copyright (c) 2013年 林光海. All rights reserved.
//

#ifndef __WestWood__CookStew__
#define __WestWood__CookStew__

#include <iostream>
#include "State.h"
using namespace std;
class MinersWife;
class CookStew : public State<MinersWife>
{
private:
    
    CookStew(){}
    
    //copy ctor and assignment should be private
    CookStew(const CookStew&);
    CookStew& operator=(const CookStew&);
    
public:
    
    //this is a singleton
    static CookStew* Instance();
    
    virtual void Enter(MinersWife* wife);
    
    virtual void Execute(MinersWife* wife);
    
    virtual void Exit(MinersWife* wife);
    
    virtual bool OnMessage(MinersWife* wife, const Telegram& msg);
};
#endif /* defined(__WestWood__CookStew__) */
