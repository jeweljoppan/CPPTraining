/**
 * File CEmpDetails.cpp - Copyright (C) <2019>
 * <Triassic Solutions Private Limited>. All rights reserved.
 * This file contains the member functions of  class "CManager".
 *
 *
 * Author   : Jewel Jo Prince
 * Version  : 1.0.0
 * Date     : 12-07-2019
 *
 */

#include "CManager.h"

// ------------------------------------------------------------------
// Method      : Intro
// Parameters  : Nil
// Returns     : Nil
// Description : Shows a basic introduction to program.
// ------------------------------------------------------------------
void CManager::Intro( void )
{
    cout<<"PROGRAM TO SORT EMPLOYEES BASED ON DESIGNATION\n";
    cout<<string(46,'_');
}

// ------------------------------------------------------------------
// Method      : AllocateSpace
// Parameters  : Nil
// Returns     : int
// Description : Allocate memory to array.
// ------------------------------------------------------------------
int CManager::AllocateSpace( void )
{
    cout<<"\n\nEnter the number of employees: "<<endl;
    m_nCount = m_check.Integer( 0 );
    if( CEmpDetails *pempDetails = new CEmpDetails[m_nCount] )
    {
        m_pEmpDetails = pempDetails;
        return 1;
    }
    else
    {
        return 0;
    }
}

// ------------------------------------------------------------------
// Method      : StoreData
// Parameters  :
//   <param 1> - <int nCount> - Current Array Count  from GetData().
// Returns     : int
// Description : Read employee details from user.
// ------------------------------------------------------------------
int CManager::StoreData( int nCount )
{
    m_nFlag = 0;
    cout<<"\n\nName: "<<endl;
    m_szName = m_check.Stringg( 20 );
    cout<<"Available designations.";
    cout<<"\n\t1: Manager";
    cout<<"\n\t2: Developer";
    cout<<"\n\t3: Trainee";
    cout<<"\n\nEnter the number corresponding to the designation: "<<endl;
    m_nDesignation = m_check.Integer( 1, 3 );
    cout<<"Age: "<<endl;
    m_nAge = m_check.Integer( 18, 80 );
    cout<<"Salary: "<<endl;
    m_fSalary = m_check.Float( 0 );
    return SortData( nCount );
}

// ------------------------------------------------------------------
// Method      : SortData
// Parameters  :
//   <param 1> - <int nCount> - Current array size.
// Returns     : int
// Description : Sorts and stores user data in array
// ------------------------------------------------------------------
int CManager::SortData( int nCount )
{
    int nTemp = 0;

    switch( m_nDesignation )
    {
        case 1: m_szDesignation = "Manager";
                DoShift( nCount,m_nTrainee + m_nDeveloper );
                nTemp = m_nManager++;
                break;

        case 2: m_szDesignation = "Developer";
                DoShift( nCount,m_nTrainee );
                nTemp = m_nManager + m_nDeveloper++;
                break;

        case 3: m_szDesignation = "Trainee";
                nTemp = m_nManager + m_nDeveloper + m_nTrainee++;
                break;

        default:return 0;
    }

    return m_pEmpDetails[nTemp].DataEntry( m_szName,m_szDesignation,m_nAge,m_fSalary );
}

// ------------------------------------------------------------------
// Method      : DoShift
// Parameters  :
//   <param 1> - <int nCount]> - Current array size.
//   <param 2> - <int nTemp> - Number of iteration needed.
// Returns     : void
// Description : Shifts array accordingly.
// ------------------------------------------------------------------
void CManager::DoShift( int nCount,int nIterate )
{
    while( nIterate > 0 )
    {
            m_pEmpDetails[nCount] = m_pEmpDetails[nCount-1];
            nIterate--;
            nCount--;
    }
}

// ------------------------------------------------------------------
// Method      : GetData
// Parameters  : void
// Returns     : void
// Description : Function that handles User Data Entry.
// ------------------------------------------------------------------
void CManager::GetData( void )
{
    int nTemp = 0;
    int nFlag = 1;

    system( "cls" );
    cout<<"\nEnter the details of "<<m_nCount<<" employees:\n";
    cout<<string(33,'_');
    while( nTemp < m_nCount )
    {
        nFlag = StoreData( nTemp );
        if( nFlag == 1)
        {
            cout<<"Data entry successful.";
            nTemp++;
        }
        else
        {
            cout<<"Invalid Input. Re-enter data.";
        }
    }
}

// ------------------------------------------------------------------
// Method      : PrintData
// Parameters  : void
// Returns     : void
// Description : Prints sorted user data to the screen.
// ------------------------------------------------------------------
void CManager::PrintData( void )
{
    int nTemp = 0;

    system( "cls" );
    cout<<"\tDetails of employees grouped based on designation\n";
    cout<<"\t"<<string(50,'_')<<endl<<endl;
    cout<<setw(5)<<setiosflags( ios::left )<<"SI";
    cout<<setw(20)<<setiosflags( ios::left )<<"Name";
    cout<<setw(5)<<setiosflags( ios::left )<<"Age";
    cout<<setw(15)<<setiosflags( ios::left )<<"Salary";
    cout<<setw(10)<<setiosflags( ios::left )<<"Designation";
    cout<<endl<<endl;
    while( nTemp < m_nCount )
    {
        cout<<setw(5)<<setiosflags( ios::left )<<nTemp+1;
        m_pEmpDetails[nTemp].DisplayData();
        nTemp++;
    }
    cout<<"\n\n\n\n";
}

// ------------------------------------------------------------------
// Method      : Destructor
// Parameters  : Nil
// Returns     : Nil
// Description : Deallocates the array memory.
// ------------------------------------------------------------------
CManager::~CManager( void )
{
    delete [] m_pEmpDetails;
}

// ------------------------------------------------------------------
// Method      : Constructor
// Parameters  : Nil
// Returns     : Nil
// Description : Initializes different variables.
// ------------------------------------------------------------------
CManager::CManager( void )
{
    m_pEmpDetails = NULL;
    m_nManager = 0;
    m_nDeveloper = 0;
    m_nTrainee = 0;
    m_nFlag = 0;
}

// ------------------------------------------------------------------
// Method      : ManageAll
// Parameters  : Nil
// Returns     : Nil
// Description : Manages all class functions.
// ------------------------------------------------------------------
void CManager::ManageAll( void )
{
    int nFlag = 0;

    Intro();
    nFlag = AllocateSpace();
    if( nFlag == 0 )
    {
        cout<<"Memory allocation failed. Press any key to exit.";
        getch();
        exit( 0 );
    }
    else
    {
        GetData();
        PrintData();
    }
}
