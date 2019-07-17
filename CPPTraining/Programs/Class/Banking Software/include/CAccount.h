/**
 * File CAccount.h - Copyright (C) <2019>
 * <Triassic Solutions Private Limited>. All rights reserved.
 * This file contains declaration the member functions of  class "CAccount".
 *
 *
 * Author   : Jewel Jo Prince
 * Version  : 1.0.0
 * Date     : 16-07-2019
 *
 */

#ifndef CACCOUNT_H
#define CACCOUNT_H

#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<vector>
#include<string>

using namespace std;

class CAccount
{
    protected:
        string m_szAccountno;
        string m_szName;
        char m_szAccType;
        float m_fBalance;
    public:
        void AddBalance( float );
        virtual void AddUser( string,float ) = 0;
        virtual void WithDraw( float ) = 0;
        virtual void CalculateInterest( void ) = 0;
        void DisplayType( void );
        void ViewBalance( void );
        void DisplayDetails( void );
        string GetAccountNo( void );
        virtual ~CAccount( void );

};

#endif // CACCOUNT_H
