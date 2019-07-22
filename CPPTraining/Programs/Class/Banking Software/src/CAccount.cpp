/**
 * File CAccount.cpp - Copyright (C) <2019>
 * <Triassic Solutions Private Limited>. All rights reserved.
 * This file contains definitions of the member functions of  class "CAccount".
 *
 *
 * Author   : Jewel Jo Prince
 * Version  : 1.0.0
 * Date     : 16-07-2019
 *
 */

 #include "CAccount.h"

// ------------------------------------------------------------------
// Method      : AddBalance
// Parameters  :
//   <param 1> - <float fAmount> - The amount that has to be credited.
// Returns     : Nil
// Description : Adds and updates the balance of account.
// ------------------------------------------------------------------
void CAccount::AddBalance( /*IN*/ float fAmount )
{
    m_fBalance = m_fBalance + fAmount;
    cout<<endl;
    ViewBalance();
}

// ------------------------------------------------------------------
// Method      : ViewBalance
// Parameters  : Nil
// Returns     : Nil
// Description : Displays the balance.
// ------------------------------------------------------------------
void CAccount::ViewBalance( void )
{
    cout<<"Balance: "<<this->m_fBalance;
}

// ------------------------------------------------------------------
// Method      : DisplayType
// Parameters  : Nil
// Returns     : Nil
// Description : Displays the type of account.
// ------------------------------------------------------------------
void CAccount::DisplayType( void )
{
    if( this->m_szAccType == 'C')
    {
        cout<<"Current";
    }
    else
    {
        cout<<"Savings";
    }
}

// ------------------------------------------------------------------
// Method      : DisplayDetails
// Parameters  : Nil
// Returns     : Nil
// Description : Displays the details of the account.
// ------------------------------------------------------------------
void CAccount::DisplayDetails( void )
{
    cout<<"NAME\t\t: "<<m_szName<<endl;
    cout<<"ACCOUNT NUMBER\t: "<<m_szAccountno<<endl;
    cout<<"ACCOUNT TYPE\t: ";
    DisplayType();
    cout<<"\nBALANCE\t\t: "<<m_fBalance;
    cout<<"\n\n\nPress any key to continue.";
    getch();
}

void CAccount::DisplayTab( void )
{
    cout<<"\t"<<m_szName;
    cout<<"\t\t"<<m_szAccountno;
    cout<<"\t\t";
    DisplayType();
    cout<<"\t\t"<<m_fBalance<<endl;
}

// ------------------------------------------------------------------
// Method      : GetAccountNo
// Parameters  : Nil
// Returns     : string
// Description : Returns the account number.
// ------------------------------------------------------------------
string CAccount::GetAccountNo( void )
{
    return m_szAccountno;
}

// ------------------------------------------------------------------
// Method      : Destructor
// Parameters  : Nil
// Returns     : Nil
// Description : Deallocates the memory.
// ------------------------------------------------------------------
CAccount::~CAccount( void )
{
    //dtor
}
