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

//Static variable that keep tracks of the Current account number.
int CCurrent::m_nAccountCount = 1000;

// ------------------------------------------------------------------
// Method      : AddUser
// Parameters  :
//    <param1> - <string szName> - Name of the customer.
//    <param2> - <float fBalance> - Inital balance of the account.
// Returns     : Nil
// Description : Initializes the basic details by user input.
// ------------------------------------------------------------------
void CCurrent::AddUser( /*IN*/ string szName,
                        /*IN*/ float fBalance )
{
    m_szName = szName;
    m_fBalance = fBalance;
    m_szAccountno = "C" + to_string( m_nAccountCount );
    m_nAccountCount++;
    CheckMin();
    cout<<"Account created."<<endl;
    sleep_for( seconds( 2 ) );
}

// ------------------------------------------------------------------
// Method      : WithDraw
// Parameters  :
//   <param 1> - <float fAmount> - Amount to be withdrawn.
// Returns     : Nil
// Description : Deducts amount from account.
// ------------------------------------------------------------------
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

// ------------------------------------------------------------------
// Method      : CalculateInterest
// Parameters  : Nil
// Returns     : Nil
// Description : Display the nonavailability of the feature.
// ------------------------------------------------------------------
void CCurrent::CalculateInterest( void )
{
    cout<<"\nThis feature is not available for Current account type."<<endl;
}

// ------------------------------------------------------------------
// Method      : CheckMin
// Parameters  : Nil
// Returns     : Nil
// Description : Ensures minimum balance, if not penalty taken.
// ------------------------------------------------------------------
void CCurrent::CheckMin()
{
    if( m_fBalance < ACCOUNT_MINIMUM )
    {
        cout<<"\nBALANCE BELOW LIMIT!!"<<endl;
        cout<<"Rs 20 will be deducted from account."<<endl;
        m_fBalance = m_fBalance - PENALITY;
    }
    else
    {
        cout<<"\nBalance Above Limit"<<endl;
    }

}

// ------------------------------------------------------------------
// Method      : Constructor
// Parameters  : Nil
// Returns     : Nil
// Description : Initializes the data members with default value.
// ------------------------------------------------------------------
CCurrent::CCurrent( void )
{
    m_szAccountno = "\0";
    m_szAccType = 'C';
    m_szName = "\0";
    m_fBalance = 0;
}

// ------------------------------------------------------------------
// Method      : Destructor
// Parameters  : Nil
// Returns     : Nil
// Description : Deallocates memory.
// ------------------------------------------------------------------
CCurrent::~CCurrent( void )
{
    //dtor
}
