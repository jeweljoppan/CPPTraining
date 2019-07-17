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

    system( "cls" );
    Intro();
    cout<<"Password: ";
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

int CManage::MainMenu( void )
{
    int nChoice = 0;

    cout<<"1. My Account"<<endl;
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

    system( "cls" );
    Intro();
    cout<<"Current user: Admin"<<endl;
    cout<<string(19,'_');
    getchar();
    cout<<"\n\nNew registration:";
    cout<<"\n\nName: ";
    getline( cin,szName );
    cout<<"Balance: ";
    cin>>fBalance;
    again:
    cout<<"1. Current"<<endl;
    cout<<"2. Saving"<<endl;
    cout<<"Type of account( 1 or 2 ): ";
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

        default:cout<<"Invalid option. Try again."<<endl;
                goto again;
                break;
    }
}

void CManage::DeleteUser( void )
{
    system( "cls" );
    Intro();
    cout<<"Current user: Admin"<<endl;
    cout<<string(19,'_');
    cout<<"\n\nDelete account";
    auto temp = GetUser( );
    if( temp == Accounts.end() )
    {
        cout<<"Invalid Account number. Try again"<<endl;
    }
    else
    {
        cout<<(*temp)->GetAccountNo()<<" deleted."<<endl;
        Accounts.erase( temp );
    }
    sleep_for(seconds(2));
}

void CManage::DisplayAll( void )
{
    system( "cls" );
    Intro();
    int nCount = 1;

    cout<<"\n\nAccount numbers: \n"<<endl;
    for (auto iterate = Accounts.begin(); iterate < Accounts.end(); iterate++)
    {
        cout<<nCount<<". "<<(*iterate)->GetAccountNo()<<endl;
        ++nCount;
    }
    if( nCount == 1 )
    {
        cout<<"\n\t\tNo item to display.\n"<<endl;
        sleep_for(seconds(2));
    }
    else
    {
        cout<<"\n\nPress any key to continue. ";
        getch();
    }
}

void CManage::HandleChoiceAdmin( void )
{
    int nChoice;

    again:
    cout<<"\nEnter your choice (0-4): ";
    cin>>nChoice;
    switch( nChoice )
    {
        case 0: cout<<"Program exiting. \n\n\n";
                exit( 0 );
                break;

        case 1: AddUser();
                break;

        case 2: DeleteUser();
                break;

        case 3: DisplayAll();
                break;

        case 4: Manage();
                break;

        default:cout<<"Invalid input.Try again"<<endl;
                goto again;
                break;
    }
}

void CManage::MenuAdmin( void )
{
    int nFlag = 0;

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
            Intro();
            cout<<"Current user: Admin"<<endl;
            cout<<string(19,'_');
            cout<<"\n\n1. Add new account"<<endl;
            cout<<"2. Delete an account"<<endl;
            cout<<"3. View all account"<<endl;
            cout<<"4. Main Menu"<<endl;
            cout<<"0. Exit"<<endl;
            HandleChoiceAdmin();
        }
    }
}

vector<CAccount*>::iterator CManage::GetUser( void )
{
    string szAccountNumber = "\0";

    cout<<"\n\nAccount Number: ";
    cin>>szAccountNumber;
    auto temp = Accounts.begin();
	while( temp != Accounts.end() )
    {
        if( ( *temp )->GetAccountNo() == szAccountNumber)
        {
            return temp;
        }
        else
        {
            temp++;
        }
    }
    return temp;

}

void CManage::PrintMenu( void )
{
    cout<<"\n1. Deposit"<<endl;
    cout<<"2. Balance"<<endl;
    cout<<"3. My Details"<<endl;
    cout<<"4. Withdraw"<<endl;
    cout<<"5. Calculate interest"<<endl;
    cout<<"6. Main Menu"<<endl;
    cout<<"0. Exit"<<endl;
    cout<<"\nEnter your choice (0-6): ";
}

void  CManage::HandleChoiceUser( int nChoice,CAccount *User )
{
    float fAmount = 0;
    system( "cls" );
    Intro();
    switch( nChoice )
    {
        case 1: cout<<"Credit amount: ";
                cin>>fAmount;
                User->AddBalance( fAmount );
                break;

        case 2: User->ViewBalance();
                break;

        case 3: User->DisplayDetails();
                break;

        case 4: cout<<"Withdraw amount: ";
                cin>>fAmount;
                User->WithDraw( fAmount );
                break;

        case 5: User->CalculateInterest();
                break;

        case 6: Manage();
                break;

        case 0: cout<<"Program Exiting"<<endl;
                exit( 0 );
                break;

        default:cout<<"Invalid option. Try again."<<endl;
                break;

    }
    sleep_for( seconds( 2 ) );
}

void CManage::MenuUser()
{
    int nChoice;

    system( "cls" );
    Intro();
    auto User = GetUser();
    if( User == Accounts.end() )
    {
        cout<<"No Match found. Try again."<<endl;
        sleep_for( seconds( 2 ) );
    }
    else
    {
        while( 1 )
        {
            system( "cls ");
            Intro();
            cout<<"Current user: "<<( *User )->GetAccountNo()<<endl;
            cout<<string(19,'_')<<endl;
            PrintMenu();
            cin>>nChoice;
            HandleChoiceUser( nChoice,( *User ) );
        }
    }
}

void CManage::Manage( void )
{
    int nChoice;

    while( 1 )
    {
        system( "cls" );
        Intro();
        nChoice = MainMenu();
        switch( nChoice )
        {
            case 0: cout<<"Thank you for using Banking Software"<<endl;
                    cout<<"Program Exiting.\n\n\n";
                    exit( 0 );
                    break;

            case 1: MenuUser();
                    break;

            case 2: MenuAdmin();
                    break;


            default:cout<<"Invalid Choice. Try again."<<endl;
                    cout<<"Press any button to continue";
                    getch();
                    break;
        }
    }
}

