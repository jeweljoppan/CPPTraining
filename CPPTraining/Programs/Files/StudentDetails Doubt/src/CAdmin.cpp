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

int CAdmin::m_nAdmCount = 1;

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
}

void CAdmin::HandleChoice( void )
{
    int nChoice;

re:
    cout<<"\nEnter your choice (1-5 or 9): ";
    cin>>nChoice;
    getchar();
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

void CAdmin::AddNew( void )
{
    string szName;
    char cGender;
    int nCourse;
    string szDateOfJoin;

    Intro();
    cout<<"Registration"<<endl;
    cout<<string( 12,'_' );
    cout<<"\nName\t\t: ";
    getline( cin,szName );
Gre:
    cout<<"Gender( M/F/O )\t\t: ";
    cin>>cGender;
    if( cGender == 'M' || cGender == 'F' || cGender == 'O' )
    {
        cout<<"Courses\t\t:\n";
        cout<<"\t1. Computer Science"<<endl;
        cout<<"\t2. Biology"<<endl;
        cout<<"\t3. Commerce"<<endl;
DOJre:
        cout<<"\nEnter your course: ";
        cin>>nCourse;
        if( nCourse == 1 || nCourse == 2 || nCourse == 3)
        {
            cout<<"Date of Join ( DD/MM/YYYY )\t\t: ";
            cin>>szDateOfJoin;
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
    m_student.AddData( m_nAdmCount++, szName, cGender, nCourse, szDateOfJoin);
    m_file.Write( m_student );
}

void CAdmin::ViewSpec( void )
{
    int nAdmNo = 0;

    Intro();
    cout<<"Admno: ";
    cin>>nAdmNo;
    m_student = m_file.GetData( nAdmNo );
    cout<<" Student Details: "<<endl;
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
}
void CAdmin::DeleteSpec( void )
{

}

void CAdmin::DeleteAll( void )
{
    m_file.ClearFile();
}

void CAdmin::Hold( void )
{
    cout<<"Press any key to continue.";
    getch();
}

void CAdmin::ViewAll( void )
{
    Intro();
    cout<<setw( 10 )<<setiosflags(ios::left)<<"Name";
    cout<<setw( 10 )<<"Admission";
    cout<<setw( 10 )<<"Gender";
    cout<<setw( 10 )<<"Course";
    cout<<setw( 10 )<<"Date of Join"<<endl;
    m_file.ViewAll();
    getch();
}

void CAdmin::Manage( void )
{
    while( 1 )
    {
        Intro();
        Menu();
        HandleChoice();
        m_file.~CFile();
    }
}
