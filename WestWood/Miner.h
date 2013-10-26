//
//  Miner.h
//  WestWood
//
//  Created by 林光海 on 13-10-26.
//  Copyright (c) 2013年 林光海. All rights reserved.
//

#ifndef __WestWood__Miner__
#define __WestWood__Miner__

#include <iostream>
#include <assert.h>
#include "BaseGameEntity.h"
#include "Location.h"

class State;

const int ComfortLevel = 5;
const int MaxNuggets = 3;
const int ThirstLevel = 5;
const int TirednessThreshold = 5;



class Miner : public BaseGameEntity {
public:
    Miner(int ID);
    
    void Update();
    
    void ChangeState(State* pNewState);
    
    location_type Location() const;
    
    void ChangeLocation(const location_type newLocation);
    
    int GoldCarried() const;
    
    void SetGoldCarried(const int val);
    
    void AddToGoldCarried(const int val);
    
    bool PocketsFull() const;
    
    bool Fatigued() const;
    
    void DecreaseFatigue();
    
    void IncreaseFatigue();
    
    int Wealth() const;
    
    void SetWealth(const int val);
    
    void AddToWealth(const int val);
    
    bool Thirsty() const;
    
    void BuyAndDrinkAWhiskey();
private:
    State* m_pCurrentState;
    location_type m_Location;
    int m_iGoldCarried;
    int m_iMoneyInBank;
    int m_iThirst;
    int m_iFatigue;
    
};

#endif /* defined(__WestWood__Miner__) */
