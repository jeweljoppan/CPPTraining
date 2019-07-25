/**
 * File CAdmin.cpp - Copyright (C) <2019>
 * <Triassic Solutions Private Limited>. All rights reserved.
 * This file contains the member functions of  class "CAdmin".
 *
 *
 * Author   : Jewel Jo Prince
 * Version  : 1.0.0
 * Date     : 18-07-2019
 *
 */

#include "CAdmin.h"

//Static variable to assign admission number.
int CAdmin::m_nAdmCount = 0;

// ------------------------------------------------------------------
// Method      : Intro
// Parameters  : Nil
// Returns     : Nil
// Description : Header message for the program
// ------------------------------------------------------------------
void Intro( void )
{
    system( "cls" );
    cout<<"\t\t\tStudent Register\n\n\n";
}

// ------------------------------------------------------------------
// Method      : Menu
// Parameters  : Nil
// Returns     : Nil
// Description : Menu for the program
// ------------------------------------------------------------------
void CAdmin::Menu( void )
{
    Intro();
    cout<<"1. Add new"<<endl;
    cout<<"2. View specific"<<endl;
    cout<<"3. View all"<<endl;
    cout<<"4. Delete specific"<<endl;
    cout<<"5. Delete all"<<endl;
    cout<<"6. Modify"<<endl;
    cout<<"9. Exit"<<endl;
    HandleChoice();
}

// ------------------------------------------------------------------
// Method      : HandleChoice
// Parameters  : Nil
// Returns     : Nil
// Description : Function to handle the choice selected by user.
// ------------------------------------------------------------------
void CAdmin::HandleChoice( void )
{
    int nChoice;

    re:
    cout<<"\nEnter your choice (1-5 or 9): ";
    cin.sync();
    nChoice = m_check.Integer();
    switch( nChoice )
    {
    case 1:
        AddNew();
        break;

    case 2:
        ViewSpec();
        break;

    case 3:
        ViewAll();
        break;

    case 4:
        DeleteSpec();
        break;

    case 5:
        DeleteAll();
        break;

    case 6:
        Modify();
        break;

    case 9:
        system( "cls" );
        cout<<"Program exiting\n\n";
        exit( 0 );
        break;

    default:
        cout<<"Invalid option.Try again.\n";
        goto re;
        break;
    }
}

// ------------------------------------------------------------------
// Method      : AddNew
// Parameters  : Nil
// Returns     : Nil
// Description : Method to add new user.
// ------------------------------------------------------------------
void CAdmin::AddNew( void )
{
    CFile file;

    Intro();
    cout<<"Registration"<<endl;
    cout<<string( 12,'_' );
    UserData();
    file.Write( m_student );
    cout<<"Saving student details"<<endl;
    system( "cls" );
    Intro();
    m_student.View();
    cout<<endl;
    Hold();
    file.~CFile();
}

// ------------------------------------------------------------------
// Method      : UserData
// Parameters  :
//  <param 1>  - <int nAdmNo> - Admission number of student
// Returns     : Nil
// Description : Method that get student data from user.
// ------------------------------------------------------------------
 void CAdmin::UserData( /*IN*/ int nAdmNo )
 {
    char szName[MAX_LENGTH];
    char cGender;
    char cCourse;
    char szDateOfJoin[DATE_LENGTH];

    cin.sync();
    cout<<"\nName\t\t\t\t: ";
    m_check.CharArray( szName, MAX_LENGTH, MAX_LENGTH - 1 );
    Gre:
    cout<<"Gender( M/F/O )\t\t\t: ";
    cGender = getche();
    cout<<endl;
    cGender = toupper( cGender );
    if( cGender == 'M' || cGender == 'F' || cGender == 'O' )
    {
        cout<<"Courses\n";
        cout<<"\t1. Computer Science"<<endl;
        cout<<"\t2. Biology"<<endl;
        cout<<"\t3. Commerce"<<endl;
        DOJre:
        cout<<"\nEnter your course\t\t: ";
        cCourse=getche();
        cout<<endl;
        if( cCourse == '1' || cCourse == '2' || cCourse == '3' )
        {
            cout<<"Date of Join ( DD/MM/YYYY )\t: ";
            m_check.Date( szDateOfJoin );
        }
        else
        {
            cout<<"Invalid input. Try again.\n";
            goto DOJre;
        }
    }
    else
    {
        cout<<"Invalid input. Try again.\n";
        goto Gre;
    }
    if ( nAdmNo == 0)
    {
        m_student.AddData( ++m_nAdmCount, szName, cGender, cCourse, szDateOfJoin);
    }
    else
    {
        m_student.AddData( nAdmNo, szName, cGender, cCourse, szDateOfJoin);
    }
 }

// ------------------------------------------------------------------
// Method      : ViewSpec
// Parameters  : Nil
// Returns     : Nil
// Description : Method to details of a student.
// ------------------------------------------------------------------
void CAdmin::ViewSpec( void )
{
    CFile file;
    int nAdmNo = 0;

    Intro();
    cout<<"Admission number : ";
    cin>>nAdmNo;
    system( "cls" );
    Intro();
    m_student = file.GetData( nAdmNo );
    cout<<" Student Details "<<endl<<endl;
    if( m_student.GetAdmNo() == 0 )
    {
        cout<<"No Record found.";
    }
    else
    {
        m_student.View();
    }
    cout<<endl;
    Hold();
    file.~CFile();
}

// ------------------------------------------------------------------
// Method      : DeleteSpec
// Parameters  : Nil
// Returns     : Nil
// Description : Delete details of a student.
// ------------------------------------------------------------------
void CAdmin::DeleteSpec( void )
{
    CFile file;
    int nAdmNo = 0;

    Intro();
    cout<<"Admission number : ";
    cin>>nAdmNo;
    system( "cls" );
    Intro();
    file.ClearSpec( nAdmNo );
    cout<<"Admission number: "<<nAdmNo<<"\n\n \tCleared."<<endl;
    Hold();
    file.~CFile();
}

// ------------------------------------------------------------------
// Method      : DeleteAll
// Parameters  : Nil
// Returns     : Nil
// Description : Method to clear the whole database.
// ------------------------------------------------------------------
void CAdmin::DeleteAll( void )
{
    CFile file;
    file.ClearFile();
    Intro();
    cout<<"File Cleared."<<endl<<endl;
    m_nAdmCount = 1;
    Hold();
    file.~CFile();
}

// ------------------------------------------------------------------
// Method      : Hold
// Parameters  : Nil
// Returns     : Nil
// Description : Method to add a pause.
// ------------------------------------------------------------------
void CAdmin::Hold( void )
{
    cout<<"Press any key to continue.";
    getch();
}

// ------------------------------------------------------------------
// Method      : ViewAll
// Parameters  : Nil
// Returns     : Nil
// Description : Method to view the entire database.
// ------------------------------------------------------------------
void CAdmin::ViewAll( void )
{
    CFile file;

    Intro();
    cout<<setw( 15 )<<setiosflags(ios::left)<<"Admission";
    cout<<setw( 20 )<<setiosflags(ios::left)<<"Name";
    cout<<setw( 10 )<<setiosflags(ios::left)<<"Gender";
    cout<<setw( 18 )<<setiosflags(ios::left)<<"Course";
    cout<<setw( 20 )<<setiosflags(ios::left)<<"Date of Join"<<endl;
    file.ViewAll();
    Hold();
    file.~CFile();
}

// ------------------------------------------------------------------
// Method      : Modify
// Parameters  : Nil
// Returns     : Nil
// Description : Method to modify a specific record.
// ------------------------------------------------------------------
void CAdmin::Modify( void )
{
    CFile file;
    int nAdmno;

    Intro();
    cout<<"Admission Number : ";
    nAdmno = m_check.Integer();
    Intro();
    cout<<"Modified data"<<endl;
    cout<<string( 13,'_' )<<endl;
    UserData( nAdmno );
    file.ModifyFile( m_student );
    cout<<"\nData Modified."<<endl;
    Hold();


}

// ------------------------------------------------------------------
// Method      : Constructor
// Parameters  : Nil
// Returns     : Nil
// Description : Resets the m_nAdmCount each time the program is executed.
// ------------------------------------------------------------------
CAdmin::CAdmin( void )
{
    CFile file;

    m_nAdmCount = file.ReturnAdmnNo();
    file.~CFile();
}

// ------------------------------------------------------------------
// Method      : Manage
// Parameters  : Nil
// Returns     : Nil
// Description : The root method called from main.
// ------------------------------------------------------------------
void CAdmin::Manage( void )
{
    while( 1 )
    {
        Intro();
        Menu();
    }
}
