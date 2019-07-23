/**
 * File CInputValidate.h - Copyright (C) <2019>
 * <Triassic Solutions Private Limited>. All rights reserved.
 * This file contains the declaration of class "CInputValidate" .
 *
 * Author   : Jewel Jo Prince
 * Version  : 1.0.0
 * Date     : 23-07-2019
 *
 */

#ifndef CINPUTVALIDATE_H
#define CINPUTVALIDATE_H

#include <iostream>
#include <ctype.h>
#include "typeinfo"

/*
 * Class <CInpuValidation>
 * <A class that holds methods to validate user inputs.>
 * Author : Jewel Jo Prince
 * Version : 1.0.0
 * Date : 23-07-2019
 *
 */

class CInputValidate
{
    public:
        int Integer( int T , const int nLow = -2147483648, const int nHigh = 2147483647 );
        template <class T>
        int Character( T );
        template <class T>
        int CharArray( T, const int );
        template <class T>
        int Stringg( T );
        template <class T>
        int Date( T, const int, const int, const char [] = { 'D','D','/','M','M','/','Y','Y','Y','Y' } );
};

#endif // CINPUTVALIDATE_H
