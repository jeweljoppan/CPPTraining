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
// Parameters  :
//  <param 1>  - <int nLow>  - Lower bound for integer input.
//  <param 2>  - <int nHigh> - Higher bound for integer input.
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
// Parameters  :
//  <param 1>  - <int fLow>  - Lower bound for float input.
//  <param 2>  - <int fHigh> - Higher bound for float input.
// Returns     : int
// Description : Checks and validates whether user input is an integer
// ------------------------------------------------------------------
float CInputValidate::Float( /*IN*/ const float fLow ,
                             /*IN*/ const float fHigh )
{
    float  fInput = 0;
    bool bValid= false;
    do
    {
        cout << "Enter a number: " ;
        cin >> fInput;
        if ( cin.good() && ( fInput > fLow ) && ( fInput < fHigh ) )
    {
            bValid = true;
        }
        else
        {
            cin.clear();
            cin.ignore( numeric_limits<streamsize>::max(), '\n' );
            cout << "Invalid data. Try again." << endl;
        }
    } while ( !bValid );
    return ( fInput );
}

// ------------------------------------------------------------------
// Method      : Double
// Parameters  :
//  <param 1>  - <int dLow>  - Lower bound for double input.
//  <param 2>  - <int dHigh> - Higher bound for double input.
// Returns     : int
// Description : Checks and validates whether user input is an integer
// ------------------------------------------------------------------
double CInputValidate::Double( /*IN*/ const double dLow ,
                             /*IN*/ const double dHigh )
{
    double  dInput = 0;
    bool bValid= false;
    do
    {
        cout << "Enter a number: " ;
        cin >> dInput;
        if ( cin.good() && ( dInput > dLow ) && ( dInput < dHigh ) )
    {
            bValid = true;
        }
        else
        {
            cin.clear();
            cin.ignore( numeric_limits<streamsize>::max(), '\n' );
            cout << "Invalid data. Try again." << endl;
        }
    } while ( !bValid );
    return ( dInput );
}

// ------------------------------------------------------------------
// Method      : Character
// Parameters  :
//  <param 1>  - <char szData>  - character for validation
// Returns     : int
// Description : Checks and validates whether user input is a character
// ------------------------------------------------------------------
int CInputValidate::Character( /*IN*/ char szData )
{
    if( ( ( int )szData >= 65 ) && ( ( int )szData <= 90 ) )
    {
        return 1;
    }
    else if( ( ( int )szData >= 97 ) && ( ( int )szData <= 122 ) )
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
// Parameters  :
//  <param 1>  - <char *szData>  - Base pointer of the character array for validation/
//  <param 2>  - <int nLength> - Maximum length of character array.
// Returns     : int
// Description : Checks and validates whether user inputs are characters
// ------------------------------------------------------------------
void CInputValidate::CharArray( /*IN*/  char *szData,
                                /*IN*/ const int nLength,
                                /*IN*/ const int nPermittedLength )
{
    int nIndex;

    again:
    nIndex = 0;
    strcpy( szData,"\0" );
    cin.clear();
    cin.getline( szData,nLength );
    cin.sync();
    if( ( strlen( szData ) > nPermittedLength ) )
    {
        cout<<"Data length more than "<<nPermittedLength<<". Try again."<<endl;
        goto again;
    }
    else if ( strlen( szData ) == 0 )
    {
        cout<<"Invalid data. Try again."<<endl;
        goto again;
    }
    else
    {
        while( szData[nIndex] != '\0' )
        {
            if( szData[nIndex] == ' ' )
            {
                nIndex++;
            }
            else if ( Character( szData[nIndex] ) == 1 )
            {
                nIndex++;
            }
            else
            {
                cout<<"Invalid data. Try Again"<<endl;
                goto again;
            }
        }
    }
}

// ------------------------------------------------------------------
// Method      : Stringg
// Parameters  :
//  <param 1>  - <int nLow>  - Maximum length of the string input.
// Returns     : int
// Description : Checks and validates whether user inputs are character
// ------------------------------------------------------------------
string CInputValidate::Stringg( /*IN*/ const int nLength )
{
    string szData;

    again:
    szData.clear();
    getline( cin,szData );
    if( szData.size() == 0 )
    {
        cout<<"Invalid data. Try again."<<endl;
        goto again;
    }
    else if( szData.size() > nLength )
    {
        cout<<"Data length more than "<<nLength<<". Try again."<<endl;
        goto again;
    }
    else
    {
        for ( auto it = szData.begin(); it < szData.end();  )
        {
            if ( ( Character( *it ) == 1 ) || (*it == ' ') )
            {
                ++it;
            }
            else
            {
                cout<<"Invalid Data. Try again."<<endl;
                goto again;
            }
        }
    }
	return szData;
}

// ------------------------------------------------------------------
// Method      : Date
// Parameters  :
//  <param 1>  - <int nYearUpper>  - Upper bound for year input.
//  <param 2>  - <int nYeayLower>  - Lower bound for year input.
//  <param 3>  - <char szFormat[]> - Format of date input.
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
            nTemp = atoi( szTemp.c_str() ) * 10 ;
            szTemp = szData[i+1];
            nTemp = nTemp + atoi( szTemp.c_str() );
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
        else if( ( szFormat[i] == 'M' ) && ( szFormat[i+1] == 'M' ) )
        {
            szTemp =szData[i];
            nTemp = atoi( szTemp.c_str() ) * 10 ;
            szTemp = szData[i+1];
            nTemp = nTemp + atoi( szTemp.c_str() );
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
        else if( ( szFormat[i] == 'Y' ) && ( szFormat[i+1] == 'Y' ) &&
            ( szFormat[i+2] == 'Y' ) && ( szFormat[i+3] == 'Y' ) )
        {
            szTemp =szData[i];
            nTemp = atoi( szTemp.c_str() ) * 1000 ;
            szTemp = szData[i+1];
            nTemp = nTemp + atoi( szTemp.c_str() )*100;
            szTemp = szData[i+2];
            nTemp = nTemp + atoi( szTemp.c_str() )*10;
            szTemp = szData[i+3];
            nTemp = nTemp + atoi( szTemp.c_str() );
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
        else if( ( szFormat[i] == '/' ) || ( szFormat[i] == '-' ) || ( szFormat[i] == '.' ) )
        {
            ++i;
        }
        else if( szFormat[i] == '\0' )
        {
            break;
        }
        else
        {
                cout<<"Invalid Data.Try again."<<endl;
                goto again;
        }
    }
    return szData;
}

// ------------------------------------------------------------------
// Method      : Date
// Parameters  :
//  <param 1>  - < char *szData>   - Base pointer of input array containing date.
//  <param 2>  - <int nYearUpper>  - Upper bound for year input.
//  <param 3>  - <int nYeayLower>  - Lower bound for year input.
//  <param 4>  - <char szFormat[]> - Format of date input.
// Returns     : int
// Description : Checks and validates whether user inputs is a date
//               in valid format
// ------------------------------------------------------------------
void CInputValidate::Date(  /*IN*/ char *szData,
                            /*IN*/ const int nYearUpper,
                            /*IN*/ const int nYearLower,
                            /*IN*/ const char szFormat[] )
{
    int i;
    int nTemp;

    again:
    i = 0;
    nTemp = 0;
    memset( szData, '\0', sizeof( szData ) );
    cin.getline(szData, 11 );
    if (cin.fail()) {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    while( szFormat[i] != '\0' )
    {
        if( ( szFormat[i] == 'D' ) && ( szFormat[i+1] == 'D' ) )
        {
            nTemp = ( ( int )( szData[i] ) - 48 ) * 10 ;
            nTemp = nTemp + ( ( int )( szData[i+1] ) - 48 ) ;
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
        else if( ( szFormat[i] == 'M' ) && ( szFormat[i+1] == 'M' ) )
        {
            nTemp = ( ( int )( szData[i] ) - 48 ) * 10 ;
            nTemp = nTemp + ( ( int )( szData[i+1] ) - 48 ) ;
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
            nTemp = ( ( int )( szData[i] ) - 48 ) * 1000 ;
            nTemp = nTemp + ( ( int )( szData[i+1] ) - 48 ) * 100 ;
            nTemp = nTemp + ( ( int )( szData[i+2] ) - 48 ) * 10 ;
            nTemp = nTemp + ( ( int )( szData[i+3] ) - 48 )  ;
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
        else if( ( szFormat[i] == '/' ) || ( szFormat[i] == '-' ) || ( szFormat[i] == '.' ) )
        {
            ++i;
        }
        else if( szFormat[i] == '\0' )
        {
            break;
        }
        else
        {
                cout<<"Invalid Data.Try again."<<endl;
                goto again;
        }
    }
}
