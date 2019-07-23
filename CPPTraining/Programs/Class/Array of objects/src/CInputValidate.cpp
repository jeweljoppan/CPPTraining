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
int CInputValidate::Integer( /*IN*/ const int nLow ,
                             /*IN*/ const int nHigh )
{
    string szData;
    int nTemp;
    string szTemp;

    again:
    getline( cin, szData );
    szTemp = szData;
    nTemp = atoi( szData.c_str() );
    szTemp = to_string( nTemp );
    if( szTemp == szData )
    {
        if( ( nTemp >= nLow ) && ( nTemp <= nHigh ) )
        {
            return nTemp;
        }
        else
        {
            cout<<"Invalid data. Try again."<<endl;
            goto again;
        }
    }
    else
    {
        cout<<"Invalid data. Try again."<<endl;
        goto again;
    }
}

// ------------------------------------------------------------------
// Method      : Float
// Parameters  : Nil
// Returns     : int
// Description : Checks and validates whether user input is an integer
// ------------------------------------------------------------------
float CInputValidate::Float( /*IN*/ const float fLow ,
                             /*IN*/ const float fHigh )
{
    string szData;
    int nTemp;
    string szTemp;

    again:
    getline( cin, szData );
    szTemp = szData;
    nTemp = stof( szData.c_str() );
    szTemp = to_string( nTemp );
    if( szTemp == szData )
    {
        if( ( nTemp >= fLow ) && ( nTemp <= fHigh ) )
        {
            return nTemp;
        }
        else
        {
            cout<<"Invalid data. Try again."<<endl;
            goto again;
        }
    }
    else
    {
        cout<<"Invalid data. Try again."<<endl;
        goto again;
    }
}

// ------------------------------------------------------------------
// Method      : Double
// Parameters  : Nil
// Returns     : int
// Description : Checks and validates whether user input is an integer
// ------------------------------------------------------------------
double CInputValidate::Double( /*IN*/ const double dLow ,
                             /*IN*/ const double dHigh )
{
    string szData;
    int nTemp;
    string szTemp;

    again:
    getline( cin, szData );
    szTemp = szData;
    nTemp = stod( szData.c_str() );
    szTemp = to_string( nTemp );
    if( szTemp == szData )
    {
        if( ( nTemp >= dLow ) && ( nTemp <= dHigh ) )
        {
            return nTemp;
        }
        else
        {
            cout<<"Invalid data. Try again."<<endl;
            goto again;
        }
    }
    else
    {
        cout<<"Invalid data. Try again."<<endl;
        goto again;
    }
}

// ------------------------------------------------------------------
// Method      : Character
// Parameters  : Nil
// Returns     : int
// Description : Checks and validates whether user input is a character
// ------------------------------------------------------------------
int CInputValidate::Character( /*IN*/ char szData )
{
    if( ( ( int )szData > 65 ) && ( ( int )szData < 90 ) )
    {
        return 1;
    }
    else if( ( ( int )szData > 97 ) && ( ( int )szData < 122 ) )
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
char* CInputValidate::CharArray( /*IN*/ char *szData,
                               /*IN*/ const int nLength )
{
    int i;

    again:
    i = 0;
    while( i < nLength )
	{
	    szData[i]=getchar();
		if ( Character( szData[i] ) != 0 )
		{
            i++;
		}
		else if( szData[i] == '\n' )
        {
            szData[i]='\0';
            return szData;
        }
        else
        {
            cout<<"Invalid data. Try Again"<<endl;
            goto again;
        }
	}
}

// ------------------------------------------------------------------
// Method      : Stringg
// Parameters  : Nil
// Returns     : int
// Description : Checks and validates whether user inputs are character
// ------------------------------------------------------------------
string CInputValidate::Stringg()
{
    int i = 0;
    string szData;

    again:
    szData ="\0";
    getline( cin,szData );
    while( ( szData[i] != '\0' ) )
	{
	    cout<<szData[i];
		if ( Character( szData[i] ) != 0 )
		{
		    cout<<"he;";
            i++;
		}
		else
        {
            cout<<"Invalid Data. Try again."<<endl;
            goto again;
        }
	}
	return szData;
}

// ------------------------------------------------------------------
// Method      : Date
// Parameters  : Nil
// Returns     : int
// Description : Checks and validates whether user inputs is a date
//               in valid format
// ------------------------------------------------------------------
string CInputValidate::Date( /*IN*/ const int nYearUpper,
                          /*IN*/ const int nYearLower,
                          /*IN*/ const char szFormat[] )
{
    int i = 0;
    int nTemp;
    string szTemp;
    string szData;

    again:
    szData = "\0";
    getline( cin, szData );
    while( szFormat[i] != '\0' )
    {
        if( ( szFormat[i] == 'D' ) && ( szFormat[i+1] == 'D' ) )
        {
            szTemp =szData[i];
            nTemp = atoi(szTemp.c_str()) * 10 ;
            szTemp = szData[i+1];
            nTemp = nTemp + atoi(szTemp.c_str());
            cout<<nTemp;
            if( ( nTemp >= 1 ) && ( nTemp <= 31 ) )
            {
                i = i + 2;
            }
            else
            {
                cout<<"Invalid Data.Try again."<<endl;
                goto again;
            }
        }
        if( ( szFormat[i] == 'M' ) && ( szFormat[i+1] == 'M' ) )
        {
            szTemp =szData[i];
            nTemp = atoi(szTemp.c_str()) * 10 ;
            szTemp = szData[i+1];
            nTemp = nTemp + atoi(szTemp.c_str());
            if( ( nTemp >= 1 ) && ( nTemp <= 12 ) )
            {
                i = i + 2;
            }
            else
            {
                cout<<"Invalid Data.Try again."<<endl;
                goto again;
            }
        }
        if( ( szFormat[i] == 'Y' ) && ( szFormat[i+1] == 'Y' ) &&
            ( szFormat[i+2] == 'Y' ) && ( szFormat[i+3] == 'Y' ) )
        {
            szTemp =szData[i];
            nTemp = atoi(szTemp.c_str()) * 1000 ;
            szTemp = szData[i+1];
            nTemp = nTemp + atoi(szTemp.c_str())*100;
            szTemp = szData[i+2];
            nTemp = nTemp + atoi(szTemp.c_str())*10;
            szTemp = szData[i+3];
            nTemp = nTemp + atoi(szTemp.c_str());
            if( ( nTemp >= nYearLower ) && ( nTemp <= nYearUpper ) )
            {
                i = i + 4;
            }
            else
            {
                cout<<"Invalid Data.Try again."<<endl;
                goto again;
            }
        }
        if( ( szFormat[i] == '/' ) || ( szFormat[i] == '-' ) || ( szFormat[i] == '.' ) || (szFormat[i] == '\0') )
        {
            ++i;
        }
        else
        {
                cout<<"Invalid Data.Try again."<<endl;
                goto again;
        }
    }
    return szData;
}
