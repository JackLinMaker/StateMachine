//
//  StateMachine.h
//  WestWood
//
//  Created by 林光海 on 13-10-27.
//  Copyright (c) 2013年 林光海. All rights reserved.
//

#ifndef __WestWood__StateMachine__
#define __WestWood__StateMachine__

#include <iostream>
#include <cassert>
#include <string>

#include "State.h"
#include "Telegram.h"

template <class entity_type>
class StateMachine
{
public:
    StateMachine(entity_type* owner):m_pOwner(owner),
                                    m_pCurrentState(NULL),
                                    m_pPreviousState(NULL),
                                    m_pGlobalState(NULL)
    {}
    
    virtual ~StateMachine(){};
    
    void SetCurrentState(State<entity_type>* s)
    {
        m_pCurrentState = s;
    }
    
    void SetGlobalState(State<entity_type>* s)
    {
        m_pGlobalState = s;
    }
    
    void SetPreviousState(State<entity_type>* s)
    {
        m_pPreviousState = s;
    }
    
    void Update() const
    {
        if(m_pGlobalState) m_pGlobalState->Execute(m_pOwner);
        if(m_pCurrentState) m_pCurrentState->Execute(m_pOwner);
    }
    
    bool HandleMessage(const Telegram& msg) const
    {
        if(m_pCurrentState && m_pCurrentState->OnMessage(m_pOwner, msg))
        {
            return true;
        }
        
        if(m_pGlobalState && m_pGlobalState->OnMessage(m_pOwner, msg))
        {
            return true;
        }
        
        return false;
    }
    
    void ChangeState(State<entity_type>* pNewState)
    {
        assert(pNewState && "<StateMachine::ChangeState>: trying to change to NULL state");
        m_pPreviousState = m_pCurrentState;
        m_pCurrentState->Exit(m_pOwner);
        m_pCurrentState = pNewState;
        m_pCurrentState->Enter(m_pOwner);
    }
    
    void RevertToPreviousState()
    {
        ChangeState(m_pPreviousState);
    }
    
    bool isInState(const State<entity_type>& st) const
    {
        return typeid(*m_pCurrentState) == typeid(st);
    }
    
    State<entity_type>* CurrentState() const
    {
        return m_pCurrentState;
    }
    
    State<entity_type>* GlobalState() const
    {
        return m_pGlobalState;
    }
    
    State<entity_type>* PreviousState() const
    {
        return m_pPreviousState;
    }
    
private:
    entity_type* m_pOwner;
    State<entity_type>* m_pCurrentState;
    State<entity_type>* m_pPreviousState;
    State<entity_type>* m_pGlobalState;
    
};


#endif /* defined(__WestWood__StateMachine__) */
