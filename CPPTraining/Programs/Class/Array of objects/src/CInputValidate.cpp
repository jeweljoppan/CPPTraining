/**
 * File CInputValidate.cpp - Copyright (C) <2019>
 * <Triassic Solutions Private Limited>. All rights reserved.
 * This file contains the member functions of  class "CInputValidate".
 *
 *
 * Author   : Jewel Jo Prince
 * Version  : 1.0.0
 * Date     : 23-07-2019
 *
 */


#include "CInputValidate.h"

// ------------------------------------------------------------------
// Method      : Integer
// Parameters  : Nil
// Returns     : int
// Description : Checks and validates whether user input is an integer
// ------------------------------------------------------------------
int CInputValidate::Integer( /*IN*/ int data,
                              /*IN*/ const int nLow ,
                              /*IN*/ const int nHigh )
{
    char nTemp =data;
    std::cout<<nTemp;

        if( ( nLow <= data ) && ( data <= nHigh ) )
        {
            return 1;
        }
        else
        {
            return 0;
        }

}

// ------------------------------------------------------------------
// Method      : Character
// Parameters  : Nil
// Returns     : int
// Description : Checks and validates whether user input is a character
// ------------------------------------------------------------------
template<typename T>
int CInputValidate::Character( /*IN*/ T data )
{
    if( ( ( int )data > 65 ) && ( ( int )data < 90 ) )
    {
        return 1;
    }
    else if( ( ( int )data > 97 ) && ( ( int )data < 122 ) )
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// ------------------------------------------------------------------
// Method      : CharacterArray
// Parameters  : Nil
// Returns     : int
// Description : Checks and validates whether user inputs are characters
// ------------------------------------------------------------------
template<typename T>
int CInputValidate::CharArray( /*IN*/ T data,
                               /*IN*/ const int nLength )
{
    int i =0;

    while( ( data[i] != '\0' ) && ( i < nLength ) )
	{
		if ( Character( data[i] ) != 0 )
		{
            i++;
		}
		else
        {
            return 0;
        }
	}
}

// ------------------------------------------------------------------
// Method      : Stringg
// Parameters  : Nil
// Returns     : int
// Description : Checks and validates whether user inputs are character
// ------------------------------------------------------------------
template<typename T>
int CInputValidate::Stringg( /*IN*/ T data )
{
    int i =0;

    while( ( data[i] != '\0' ) )
	{
		if ( Character( data[i] ) != 0 )
		{
            i++;
		}
		else
        {
            return 0;
        }
	}
}

// ------------------------------------------------------------------
// Method      : Date
// Parameters  : Nil
// Returns     : int
// Description : Checks and validates whether user inputs is a date
//               in valid format
// ------------------------------------------------------------------
template<typename T>
int CInputValidate::Date( /*IN*/ T data,
                          /*IN*/ const int nYearUpper,
                          /*IN*/ const int nYearLower,
                          /*IN*/ const char szFormat[] )
{
    int i = 0;
    int nTemp;

    while( szFormat[i+1] != '\0' )
    {
        if( ( szFormat[i] == 'D' ) && ( szFormat[i+1] == 'D' ) )
        {
            nTemp = ( int )data[i] * 10 + ( int )data[i+1];
            if( ( nTemp >= 1 ) && ( nTemp <= 31 ) )
            {
                i = i + 2;
            }
            else
            {
                return 0;
            }
        }
        if( ( szFormat[i] == 'M' ) && ( szFormat[i+1] == 'M' ) )
        {
            nTemp = ( int )data[i] * 10 + ( int )data[i+1];
            if( ( nTemp >= 1 ) && ( nTemp <= 12 ) )
            {
                i = i + 2;
            }
            else
            {
                return 0;
            }
        }
        if( ( szFormat[i] == 'Y' ) && ( szFormat[i+1] == 'Y' ) &&
            ( szFormat[i+2] == 'Y' ) && ( szFormat[i+3] == 'Y' ) )
        {
            nTemp = ( int )data[i] * 1000 + ( int )data[i+1] * 100 + ( int )data[i+2] * 10 + ( int )data[i+3];
            if( ( nTemp >= nYearLower ) && ( nTemp <= nYearUpper ) )
            {
                i = i + 4;
            }
            else
            {
                return 0;
            }
        }
        if( ( szFormat[i] == '/' ) || ( szFormat[i] == '-' ) || ( szFormat[i] == '.' ) || (szFormat[i] == '\0') )
        {
            ++i;
        }
        else
        {
            return 0;
        }
    }
    return 1;
}
