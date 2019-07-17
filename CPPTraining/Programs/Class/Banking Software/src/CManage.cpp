/**
 * File CManage.cpp - Copyright (C) <2019>
 * <Triassic Solutions Private Limited>. All rights reserved.
 * This file contains the member functions of  class "CManage".
 *
 *
 * Author   : Jewel Jo Prince
 * Version  : 1.0.0
 * Date     : 16-07-2019
 *
 */

#include "CManage.h"

const string CManage::m_szAdminPass = "admin123";

void CManage::Intro( void )
{
    cout<<"\t\t\tBANKING SOFTWARE"<<endl;
    cout<<"\t\t\t"<<string(16,'_')<<endl;
    cout<<"\n\n\n";
}

int CManage::AdminAccess( void )
{
    string szPass ="\0";

    while(1)
    {
        system( "cls" );
        cout<<"Enter admin password: ";
        cin>>szPass;
        if( szPass == m_szAdminPass )
        {
            return 1;
        }
        else
        {
            cout<<"Wrong password. Press any key to continue. "<<endl;
            getch();
            return 0;
        }
    }

}

int CManage::MainMenu( void )
{
    int nChoice = 0;

    cout<<"1. My Acoount"<<endl;
    cout<<"2. Admin"<<endl;
    cout<<"0. Exit"<<endl;
    cout<<"Enter your choice (0,1,2): ";
    cin>>nChoice;
    return nChoice;
}

void CManage::AddUser( void )
{
    string szName;
    float fBalance;
    int nType;
    CSaving *pSaving;
    CCurrent *pCurrent;

    Intro();
    cout<<"Current user: Admin"<<endl;
    cout<<string(19,'_');
    getchar();
    cout<<"\n\nName of  customer: ";
    getline( cin,szName );
    cout<<"Balance: ";
    cin>>fBalance;
    cout<<"1. Current"<<endl;
    cout<<"2. Saving"<<endl;
    cout<<"3. Admin Menu"<<endl;
    cout<<"Type of account( 1, 2 or 3 ): ";
    cin>>nType;
    switch( nType )
    {
        case 1: pCurrent = new CCurrent;
                pCurrent->AddUser( szName,fBalance );
                Accounts.push_back( pCurrent );
                break;

        case 2: pSaving = new CSaving;
                pSaving->AddUser( szName,fBalance );
                Accounts.push_back( pSaving );
                break;

        case 3: MenuAdmin();
                break;

        default:cout<<"Invalid option.Try again."<<endl;
                MainMenu();
                break;
    }
}

void CManage::DeleteUser( void )
{
    string szAccountNumber;
    CAccount *ptr;
    int nFlag = 0;

    Intro();
    cout<<"Current user: Admin"<<endl;
    cout<<string(19,'_');
    cout<<"\n\nAccount Number: ";
    cin>>szAccountNumber;
    auto temp = Accounts.begin();
	while( temp != Accounts.end() )
    {
        ptr=*temp;
        if( ptr->GetAccountNo() == szAccountNumber)
        {
           Accounts.erase( temp );
           nFlag = 1;
           break;

        }
        else
        {
            temp++;
        }
    }
    if( nFlag == 1 )
    {
        cout<<"\nDelete successful."<<endl;
    }
    else
    {
        cout<<"Invalid Account number."<<endl;
    }
}


void CManage::HandleChoice( /*IN*/ int nChoice )
{
    system( "cls" );
    switch( nChoice )
    {
        case 0: cout<<"Program exiting. \n\n\n";
                exit( 0 );
                break;

        case 1: AddUser();
                break;

        case 2: DeleteUser();
                break;

        case 3: Manage();
                break;

        default:cout<<"Invalid input.Try again"<<endl;
                break;
    }
}

void CManage::MenuAdmin( void )
{
    int nFlag = 0;
    int nChoice = 0;

    nFlag = AdminAccess();
    if( nFlag == 0)
    {
        Manage();
    }
    else
    {
        while(1)
        {
            system( "cls" );
            cout<<"Current user: Admin"<<endl;
            cout<<string(19,'_');
            cout<<"\n\n1. Add new account"<<endl;
            cout<<"2. Delete an account"<<endl;
            cout<<"3. Main Menu"<<endl;
            cout<<"0. Exit"<<endl;
            cin>>nChoice;
            HandleChoice( nChoice );
        }
    }
}

CAccount* CManage::GetUser( string szAccountNumber )
{
    auto temp = Accounts.begin();
	while( temp != Accounts.end() )
    {
        if( *temp->GetAccountNo() == szAccountNumber)
        {
           erase( *temp );
           nFlag = 1;
           break;

        }
        else
        {
            temp++;
        }
    }
    if( nFlag == 1 )
    {
        cout<<"\nDelete successful."<<endl;
    }
    else
    {
        cout<<"Invalid Account number."<<endl;

}

void CManage::MenuUser()
{



}
void CManage::Manage( void )
{
    int nChoice;

    while(1)
    {
        system( "cls" );
        Intro();
        nChoice = MainMenu();
        switch( nChoice )
        {
            case 1: MenuUser();
                    break;

            case 2: MenuAdmin();
                    break;

            case 3: cout<<"Thank you for using Banking Software"<<endl;
                    cout<<"Program Exiting.\n\n\n";
                    exit( 0 );
                    break;

            default:cout<<"Invalid Choice. Try again."<<endl;
                    cout<<"Press any button to continue";
                    getch();
                    break;
        }
    }
}

