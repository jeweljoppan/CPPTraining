/**
 * File CSaving.h - Copyright (C) <2019>
 * <Triassic Solutions Private Limited>. All rights reserved.
 * This file contains the declarations member functions of  class "CSaving".
 *
 *
 * Author   : Jewel Jo Prince
 * Version  : 1.0.0
 * Date     : 16-07-2019
 *
 */

#ifndef CSAVING_H
#define CSAVING_H

#define CIRATE .06

#include <CAccount.h>

/*
 * Class <CSaving>
 * <A class which stores Savings type of accounts.>
 * Author : Jewel Jo Prince
 * Version : 1.0.0
 * Date : 17-07-2019
 *
 */

class CSaving : public CAccount
{
    private:
        static int m_nAccountCount;
    public:
        void AddUser( string,float );
        void WithDraw( float );
        void CalculateInterest( void );
        CSaving( void );
        virtual ~CSaving( void );
};

#endif // CSAVING_H
