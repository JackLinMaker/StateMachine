//
//  DoHouseWork.h
//  WestWood
//
//  Created by 林光海 on 13-10-29.
//  Copyright (c) 2013年 林光海. All rights reserved.
//

#ifndef __WestWood__DoHouseWork__
#define __WestWood__DoHouseWork__

#include <iostream>
#include "State.h"
using namespace std;
class MinersWife;

class DoHouseWork : public State<MinersWife> {
public:
    static DoHouseWork* Instance();
    
    virtual void Enter(MinersWife* wife);
    
    virtual void Execute(MinersWife* wife);
    
    virtual void Exit(MinersWife* wife);
private:
    DoHouseWork(){}
    
    DoHouseWork(const DoHouseWork&);
    
    DoHouseWork& operator=(const DoHouseWork&);
};



#endif /* defined(__WestWood__DoHouseWork__) */
