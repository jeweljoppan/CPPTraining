/**
 * File CCurrent.cpp - Copyright (C) <2019>
 * <Triassic Solutions Private Limited>. All rights reserved.
 * This file contains the definition member functions of  class "CCurrent".
 *
 *
 * Author   : Jewel Jo Prince
 * Version  : 1.0.0
 * Date     : 17-07-2019
 *
 */


#include "CCurrent.h"

int CCurrent::m_nAccountCount = 1000;

void CCurrent::AddUser( /*IN*/ string szName,
                        /*IN*/ float fBalance )
{
    m_szName = szName;
    m_fBalance = fBalance;
    m_szAccountno = "C" + to_string( m_nAccountCount );
    m_nAccountCount++;
    CheckMin();
    sleep_for( seconds( 2 ) );
}

void CCurrent::WithDraw( /*IN*/ float fAmount )
{
        if( m_fBalance < fAmount )
        {
            cout<<"No sufficient balance."<<endl;
        }
        else
        {
            m_fBalance = m_fBalance - fAmount;
            CheckMin();
            ViewBalance();
        }
}

void CCurrent::CalculateInterest( void )
{
    cout<<"\nThis feature is not available for Current account type."<<endl;
}

void CCurrent::CheckMin()
{
    if( m_fBalance < ACCOUNT_MINIMUM )
    {
        cout<<"BALANCE BELOW LIMIT!!"<<endl;
        cout<<"Rs 20 will be deducted from account."<<endl;
        m_fBalance = m_fBalance - PENALITY;
    }
    else
    {
        cout<<"Balance Above Limit"<<endl;
    }

}

CCurrent::CCurrent( void )
{
    m_szAccountno = "\0";
    m_szAccType = 'C';
    m_szName = "\0";
    m_fBalance = 0;
}

CCurrent::~CCurrent( void )
{
    //dtor
}
