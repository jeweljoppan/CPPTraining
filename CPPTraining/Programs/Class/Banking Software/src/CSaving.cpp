/**
 * File CSsving.h - Copyright (C) <2019>
 * <Triassic Solutions Private Limited>. All rights reserved.
 * This file contains the definition member functions of  class "CSaving".
 *
 *
 * Author   : Jewel Jo Prince
 * Version  : 1.0.0
 * Date     : 16-07-2019
 *
 */

#include "CSaving.h"

//Static variable that keep track of Savings account number.
int CSaving::m_nAccountCount = 1000;

// ------------------------------------------------------------------
// Method      : AddUser
// Parameters  :
//   <param 1> - <string szName> - Name of the customer.
//   <param 2> - <float fBalance> - Balance of the account.
// Returns     : Nil
// Description : Updates the data members with user input.
// ------------------------------------------------------------------
void CSaving::AddUser( /*IN*/ string szName,
                       /*IN*/ float fBalance )
{
    m_szName = szName;
    m_fBalance = fBalance;
    m_szAccountno = "S"+ to_string(m_nAccountCount);
    m_nAccountCount++;
    cout<<"Account created."<<endl;
    sleep_for( seconds( 2 ) );
}

// ------------------------------------------------------------------
// Method      : WithDraw
// Parameters  :
//   <param 1> - <float fAmount< - Amount to be deducted.
// Returns     : Nil
// Description : Deducts the withdrawn amount.
// ------------------------------------------------------------------
void CSaving::WithDraw( /*IN*/ float fAmount )
{
        if( m_fBalance < fAmount )
        {
            cout<<"No sufficient balance."<<endl;
        }
        else
        {
            m_fBalance = m_fBalance - fAmount;
        }
        ViewBalance();
}

// ------------------------------------------------------------------
// Method      : calculateInterest
// Parameters  : Nil
// Returns     : Nil
// Description : Calculates and displays the interest.
// ------------------------------------------------------------------
void CSaving::CalculateInterest( void )
{
    int nYears;
    float fInterest;
    float fBalance = m_fBalance;

    cout<<"To calculate interest input the time span of deposit.\n\n";
    cout<<"number of years:";
    cin>>nYears;
    while( nYears > 0 )
    {
        fInterest = fBalance * CIRATE;
        fBalance = fBalance + fInterest;
    }
    cout<<"Interest: "<<fInterest;
}

// ------------------------------------------------------------------
// Method      : Constructor
// Parameters  : Nil
// Returns     : Nil
// Description : Initializes data members with default values.
// ------------------------------------------------------------------
CSaving::CSaving( void )
{
    m_szAccountno = "\0";
    m_szAccType = 'S';
    m_szName = "\0";
    m_fBalance = 0;
}

// ------------------------------------------------------------------
// Method      : Destructor
// Parameters  : Nil
// Returns     : Nil
// Description : Deallocates the memory.
// ------------------------------------------------------------------
CSaving::~CSaving( void )
{
    //dtor
}
