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

int CAdmin::m_nAdmCount = 0;

void Intro( void )
{
    system( "cls" );
    cout<<"\t\t\tStudent Register\n\n\n";
}
void CAdmin::Menu( void )
{
    Intro();
    cout<<"1. Add new"<<endl;
    cout<<"2. View specific"<<endl;
    cout<<"3. View all"<<endl;
    cout<<"4. Delete specific"<<endl;
    cout<<"5. Delete all"<<endl;
    cout<<"9. Exit"<<endl;
    HandleChoice();
}

void CAdmin::HandleChoice( void )
{
    char cChoice;

    re:
    cout<<"\nEnter your choice (1-5 or 9): ";
    cChoice = getche();
    cout<<endl;
    switch( cChoice )
    {
    case '1':
        AddNew();
        break;

    case '2':
        ViewSpec();
        break;

    case '3':
        ViewAll();
        break;

    case '4':
        DeleteSpec();
        break;

    case '5':
        DeleteAll();
        break;

    case '9':
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

void CAdmin::AddNew( void )
{
    CFile file;
    char szName[MAX_LENGTH];
    char cGender;
    char cCourse;
    char szDateOfJoin[DATE_LENGTH];

    Intro();
    cout<<"Registration"<<endl;
    cout<<string( 12,'_' );
    cout<<"\nName\t\t: ";
    m_check.CharArray( szName, MAX_LENGTH, MAX_LENGTH - 1 );
    Gre:
    cout<<"Gender( M/F/O )\t\t: ";
    cGender = getche();
    cout<<endl;
    cGender = toupper( cGender );
    if( cGender == 'M' || cGender == 'F' || cGender == 'O' )
    {
        cout<<"Courses\t\t:\n";
        cout<<"\t1. Computer Science"<<endl;
        cout<<"\t2. Biology"<<endl;
        cout<<"\t3. Commerce"<<endl;
        DOJre:
        cout<<"\nEnter your course: ";
        cCourse=getche();
        cout<<endl;
        if( cCourse == '1' || cCourse == '2' || cCourse == '3' )
        {
            cout<<"Date of Join ( DD/MM/YYYY )\t\t: ";
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
    m_student.AddData( ++m_nAdmCount, szName, cGender, cCourse, szDateOfJoin);
    file.Write( m_student );
    file.~CFile();
}

void CAdmin::ViewSpec( void )
{
    CFile file;
    int nAdmNo = 0;

    Intro();
    cout<<"Admno: ";
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
void CAdmin::DeleteSpec( void )
{

}

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

void CAdmin::Hold( void )
{
    cout<<"Press any key to continue.";
    getch();
}

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

CAdmin::CAdmin()
{
    CFile file;

    m_nAdmCount = file.ReturnAdmnNo();
    file.~CFile();
}

void CAdmin::Manage( void )
{
    while( 1 )
    {
        Intro();
        Menu();
    }
}
