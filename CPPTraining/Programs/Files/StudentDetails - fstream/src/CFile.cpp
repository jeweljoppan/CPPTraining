/**
 * File CFile.h - Copyright (C) <2019>
 * <Triassic Solutions Private Limited>. All rights reserved.
 * This file contains the definitions of a Class "CFile" to handle files.
 *
 * Author   : Jewel Jo Prince
 * Version  : 1.0.0
 * Date     : 18-07-2019
 *
 */

#include "CFile.h"

// ------------------------------------------------------------------
// Method      : Constructor
// Parameters  : Nil
// Returns     : Nil
// Description : Opens the file to storage.
// ------------------------------------------------------------------
CFile::CFile( void )
{
    storage.open( "STUDENT.dat", ios::in | ios::out| ios::binary );
    if( !storage )
    {
        cout<<"File access failed or file does not exist."<<endl;
        exit( 0 );
    }
    else
    {

    }
}

// ------------------------------------------------------------------
// Method      : ReturnAdmnNo
// Parameters  : Nil
// Returns     : int
// Description : Method that returns the admission number of recently
//               added student.
// ------------------------------------------------------------------
int CFile::ReturnAdmnNo()
{
    CStudent data;
    int nTemp = sizeof( data ) * -1;

    storage.seekg( nTemp, ios::end );
    storage.read( ( char* )( &data ), sizeof( data ) );
    return data.GetAdmNo();
}

// ------------------------------------------------------------------
// Method      : Write
// Parameters  :
//  <param 1>  - <CStudent data> - Student object that has
//                                 to be written to file.
// Returns     : Nil
// Description : The method to write object to file.
// ------------------------------------------------------------------
void CFile::Write( /*IN*/ CStudent data )
{
    storage.seekp( 0L, ios::end );
    storage.write( ( char* )( &data ), sizeof( data ) );
    storage.flush();
}

// ------------------------------------------------------------------
// Method      : GetData
// Parameters  :
// <param 1>   - <int nAdmNo> - Admission number of the student that
//                              has to be searched
// Returns     : CStudent
// Description : Searches the file to find the object matching to the
//               admission number.
// ------------------------------------------------------------------
CStudent CFile::GetData( /*IN*/ int nAdmNo )
{
    CStudent temp;

    storage.seekg( 0, ios::beg );
    while( storage.read( ( char* )&temp,sizeof( temp ) )
           )
    {
        if( nAdmNo == temp.GetAdmNo() )
        {
            return temp;
        }
        else
        {
            temp.AddData( 0, " ", ' ', ' ', " " );
        }
    }
    return temp;
}

// ------------------------------------------------------------------
// Method      : ViewAll
// Parameters  : Nil
// Returns     : Nil
// Description : Methods to print all records in the file.
// ------------------------------------------------------------------
void CFile::ViewAll( void )
{
    CStudent temp;
    int nFlag = 0;

    storage.seekp( 0L, ios::beg );
    storage.seekg( 0L, ios::beg );
    while( storage.read( ( char* )&temp, sizeof( CStudent ) ) )
    {
        temp.ViewTab();
        cout<<endl;
        nFlag = 1;
    }
    if( nFlag == 0 )
    {
        system( "cls" );
        cout<<"\n\n\t\tFile Empty\n\n"<<endl;
    }
    else
    {
        //unimplemented
    }
}

// ------------------------------------------------------------------
// Method      : ClearSpec
// Parameters  :
//  <param 1>  - <int nAdmNo> - Admission number of student record that has
//                              to be deleted.
// Returns     : Nil
// Description : Function to clear a specific student record.
// ------------------------------------------------------------------
void CFile::ClearSpec( /*IN*/ int nAdmNo )
{
    CStudent temp;
    ofstream fout("temp.dat", ios::out | ios::binary | ios::trunc );
    while( storage.read( ( char* )&temp, sizeof( temp ) ) )
    {
        if( temp.GetAdmNo() != nAdmNo )
        {
            fout.write( ( char* )&temp,sizeof( temp ) );
        }
        else
        {
            //else unimplemented
        }
    }
    fout.close();
    storage.close();
    remove( "STUDENT.dat" );
    rename( "temp.dat", "STUDENT.dat" );
}

// ------------------------------------------------------------------
// Method      : ClearFile
// Parameters  : Nil
// Returns     : Nil
// Description : Method to clear the file.
// ------------------------------------------------------------------
void CFile::ClearFile( void )
{
    storage.close();
    remove( "Employee.dat" );
    storage.open("Employee.dat", ios::out | ios::binary );
    if( !storage )
    {
        cout<<"Operation failed."<<endl;
        exit( 0 );
    }
    else
    {
        //unimplemented
    }
}

// ------------------------------------------------------------------
// Method      : ModifyFile
// Parameters  :
//  <param 1>  - <CStudent data> - The modified record.
// Returns     : Nil
// Description : The function to modify the details of a particular student.
// ------------------------------------------------------------------
void CFile::ModifyFile( /*IN*/ CStudent data )
{
    CStudent temp;
    int nSize = sizeof( temp ) * -1;
    temp = GetData( data.GetAdmNo() );
    if( temp.GetAdmNo() == 0)
    {
        cout<<"No data found."<<endl;
    }
    else
    {
        cout<<storage.tellg();
        storage.seekg( nSize, ios::cur );
        storage.write( ( char* )( &data ), sizeof( data ) );
        storage.flush();
    }
}

// ------------------------------------------------------------------
// Method      : Destructor
// Parameters  : Nil
// Returns     : Nil
// Description : TO clear the class object from memory
// ------------------------------------------------------------------
CFile::~CFile( void )
{
    storage.close();
}
