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


void CAccount::AddBalance( /*IN*/ float fAmount )
{
    m_fBalance = m_fBalance + fAmount;
    cout<<endl;
    ViewBalance();
}

void CAccount::ViewBalance( void )
{
    cout<<"Balance: "<<this->m_fBalance;
}

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

void CAccount::DisplayDetails( void )
{
    cout<<"NAME: "<<m_szName<<endl;
    cout<<"ACCOUNT NUMBER: "<<m_szAccountno<<endl;
    cout<<"ACCOUNT TYPE: ";
    DisplayType();
    cout<<"\nBALANCE: "<<m_fBalance;
    sleep_for( seconds( 2 ) );
}

string CAccount::GetAccountNo( void )
{
    return m_szAccountno;
}

CAccount::~CAccount( void )
{
    //dtor
}
