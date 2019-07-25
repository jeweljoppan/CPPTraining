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
#include <string>
#include <limits>
#include <float.h>
#include <stdlib.h>
#include <conio.h>
#include <cstring>

using namespace std;

/*
 * Class <CInputValidate>
 * <A class which has methods to validate user input as per need.>
 * Author : Jewel Jo Prince
 * Version : 1.0.0
 * Date : 23-07-2019
 *
 */

class CInputValidate
{
    public:
        int Integer( const int nLow = INT_MIN, const int nHigh = INT_MAX );
        float Float( const float fLow = FLT_MIN, const float fHigh = FLT_MAX );
        double Double( const double dLow = DBL_MIN, const double dHigh = DBL_MAX );
        int Character( char );
        void CharArray( char *,const int, const int );
        string Stringg( const int nLength = INT_MAX );
        string Date(  const int nYearUpper = 2019, const int nYearLower = 1900, const char [] = "DD/MM/YYYY" );
        void Date(  char *, const int nYearUpper = 2019, const int nYearLower = 1900, const char [] = "DD/MM/YYYY" );
};

#endif // CINPUTVALIDATE_H
