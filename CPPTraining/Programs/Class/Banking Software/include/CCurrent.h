/**
 * File CCurrent.h - Copyright (C) <2019>
 * <Triassic Solutions Private Limited>. All rights reserved.
 * This file contains the declarations member functions of  class "CCurrent".
 *
 *
 * Author   : Jewel Jo Prince
 * Version  : 1.0.0
 * Date     : 16-07-2019
 *
 */

#ifndef CCURRENT_H
#define CCURRENT_H

#define ACCOUNT_MINIMUM 2000.0
#define PENALITY 20

#include <CAccount.h>

/*
 * Class <CCurrent>
 * <A class which handle Current type of accounts.>
 * Author : Jewel Jo Prince
 * Version : 1.0.0
 * Date : 17-07-2019
 *
 */

class CCurrent : public CAccount
{
    private:
        static int m_nAccountCount;
    public:
        void AddUser( string,float );
        void WithDraw( float );
        void CalculateInterest( void);
        void CheckMin( void );
        CCurrent( void );
        virtual ~CCurrent( void );

};

#endif // CCURRENT_H
