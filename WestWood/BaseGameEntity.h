//
//  BaseGameEntity.h
//  WestWood
//
//  Created by 林光海 on 13-10-26.
//  Copyright (c) 2013年 林光海. All rights reserved.
//

#ifndef __WestWood__BaseGameEntity__
#define __WestWood__BaseGameEntity__

#include <iostream>
#include <assert.h>
using namespace std;

class BaseGameEntity {
public:
    BaseGameEntity(int id);
    
    virtual ~BaseGameEntity();
    
    virtual void Update() = 0;
    
    int ID() const;
    
    
    
private:
    int m_ID;
    static int m_iNextValidID;
    void SetID(int val);
    
};

#endif /* defined(__WestWood__BaseGameEntity__) */
