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

//constant string that stores the admin password.
const string CManage::m_szAdminPass = "admin123";

// ------------------------------------------------------------------
// Method      : Intro
// Parameters  : Nil
// Returns     : Nil
// Description : Introduction message.
// ------------------------------------------------------------------
void CManage::Intro( void )
{
    cout<<"\t\t\tBANKING SOFTWARE"<<endl;
    cout<<"\t\t\t"<<string(16,'_')<<endl;
    cout<<"\n";
}

// ------------------------------------------------------------------
// Method      : AdminAccess
// Parameters  : Nil
// Returns     : Nil
// Description : Checks the input password of the admin
// ------------------------------------------------------------------
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

// ------------------------------------------------------------------
// Method      : MainMenu
// Parameters  : Nil
// Returns     : Nil
// Description : Display the user access menu
// ------------------------------------------------------------------
int CManage::MainMenu( void )
{
    int nChoice = 0;

    cout<<"1. My Account"<<endl;
    cout<<"2. Admin"<<endl;
    cout<<"9. Exit"<<endl;
    cout<<"Enter your choice (1,2 or 9): ";
    cin>>nChoice;
    return nChoice;
}

// ------------------------------------------------------------------
// Method      : Adduser
// Parameters  : Nil
// Returns     : Nil
// Description : Function for admin to add new customer
// ------------------------------------------------------------------
void CManage::AddUser( void )
{
    string szName;
    float fBalance;
    int nType;
    CSaving *pSaving;
    CCurrent *pCurrent;

    system( "cls" );
    Intro();
    cout<<setw(240)<<setiosflags( ios::right)<<"Current user: Admin"<<endl;
    getchar();
    cout<<"New registration";
    cout<<"\n\nName\t\t\t: ";
    getline( cin,szName );
    cout<<"Balance\t\t\t: ";
    cin>>fBalance;
    cout<<"Type of account" <<endl;
    cout<<"\t1. Current"<<endl;
    cout<<"\t2. Saving"<<endl;
    again:
    cout<<"Choose ( 1 or 2 )\t: ";
    cin>>nType;
    switch( nType )
    {
        case 1: pCurrent = new CCurrent;
                pCurrent->AddUser( szName,fBalance );
                system( "cls" );
                Intro();
                pCurrent->DisplayDetails();
                Accounts.push_back( pCurrent );
                break;

        case 2: pSaving = new CSaving;
                pSaving->AddUser( szName,fBalance );
                system( "cls" );
                Intro();
                pSaving->DisplayDetails();
                Accounts.push_back( pSaving );
                break;

        default:cout<<"Invalid option. Try again."<<endl;
                goto again;
                break;
    }
}

// ------------------------------------------------------------------
// Method      : DeleteUser
// Parameters  : Nil
// Returns     : Nil
// Description : Function for admin to delete a user
// ------------------------------------------------------------------
void CManage::DeleteUser( void )
{
    char cCheck;

    system( "cls" );
    Intro();
    cout<<setw(240)<<setiosflags( ios::right)<<"Current user: Admin"<<endl;
    cout<<"\n\nDelete account\n";
    DisplayAll();
    auto temp = GetUser( );
    if( temp == Accounts.end() )
    {
        cout<<"Invalid Account number. Try again"<<endl;
    }
    else
    {
        again:
        cout<<"\nDo you want to delete "<<(*temp)->GetAccountNo()<<"? (Y/N)\n";
        cin>>cCheck;
        cCheck = toupper( cCheck );
        if( cCheck == 'Y' )
        {
            cout<<(*temp)->GetAccountNo()<<" deleted."<<endl;
            Accounts.erase( temp );
        }
        else if( cCheck == 'N' )
        {
            cout<<"Delete operation canceled.\n";
        }
        else
        {
            cout<<"Invalid input.\n";
            goto again;
        }
    }
    sleep_for(seconds(2));
}

// ------------------------------------------------------------------
// Method      : DisplayAll
// Parameters  : Nil
// Returns     : Nil
// Description : Function to display all customers
// ------------------------------------------------------------------
void CManage::DisplayAll( void )
{
    system( "cls" );
    Intro();
    int nCount = 1;

    cout<<"SI";
    cout<<"\tNAME";
    cout<<"\t\tACCOUNT NUMBER";
    cout<<"\tACCOUNT TYPE";
    cout<<"\tBALANCE"<<endl;
    cout<<"\n";
    for (auto iterate = Accounts.begin(); iterate < Accounts.end(); iterate++)
    {
        cout<<nCount<<". ";
        (*iterate)->DisplayTab();
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

// ------------------------------------------------------------------
// Method      : HandleChoiceAmin
// Parameters  : Nil
// Returns     : Nil
// Description : Function to handle the choice inputed my the admin
// ------------------------------------------------------------------
void CManage::HandleChoiceAdmin( void )
{
    int nChoice;

    again:
    cout<<"\nEnter your choice (1-4 or 0): ";
    cin>>nChoice;
    switch( nChoice )
    {

        case 1: AddUser();
                break;

        case 2: DeleteUser();
                break;

        case 3: DisplayAll();
                break;

        case 4: Manage();
                break;

        case 9: cout<<"Program exiting. \n\n\n";
                exit( 0 );
                break;

        default:cout<<"Invalid input.Try again"<<endl;
                goto again;
                break;
    }
}

// ------------------------------------------------------------------
// Method      : MenuAdmin
// Parameters  : Nil
// Returns     : Nil
// Description : Function that displays the menu for admin
// ------------------------------------------------------------------
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
            cout<<setw(240)<<setiosflags( ios::right)<<"Current user: Admin"<<endl;
            cout<<"\n\n1. Add new account"<<endl;
            cout<<"2. Delete an account"<<endl;
            cout<<"3. View all account"<<endl;
            cout<<"4. Main Menu"<<endl;
            cout<<"9. Exit"<<endl;
            HandleChoiceAdmin();
        }
    }
}

// ------------------------------------------------------------------
// Method      : GetUser
// Parameters  : Nil
// Returns     : Nil
// Description : Fucntion that finds a specific opbject from array
//               using account number.
// ------------------------------------------------------------------
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

// ------------------------------------------------------------------
// Method      : PrintMenu
// Parameters  : Nil
// Returns     : Nil
// Description : Displays the menu for th customer
// ------------------------------------------------------------------
void CManage::PrintMenu( void )
{
    cout<<"\n1. Deposit"<<endl;
    cout<<"2. Balance"<<endl;
    cout<<"3. My Details"<<endl;
    cout<<"4. Withdraw"<<endl;
    cout<<"5. Calculate interest"<<endl;
    cout<<"6. Main Menu"<<endl;
    cout<<"9. Exit"<<endl;
    cout<<"\nEnter your choice (0-6): ";
}

// ------------------------------------------------------------------
// Method      : HandleUser
// Parameters  : Nil
// Returns     : Nil
// Description : Handles the input of the user
// ------------------------------------------------------------------
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

        case 9: cout<<"Program Exiting"<<endl;
                exit( 0 );
                break;

        default:cout<<"Invalid option. Try again."<<endl;
                break;

    }
    sleep_for( seconds( 2 ) );
}

// ------------------------------------------------------------------
// Method      : MenuUser
// Parameters  : Nil
// Returns     : Nil
// Description : Handles the control flow of customer.
// ------------------------------------------------------------------
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
            cout<<setw(235)<<setiosflags( ios::right)<<"Current user: "<<( *User )->GetAccountNo()<<endl;
            PrintMenu();
            cin>>nChoice;
            HandleChoiceUser( nChoice,( *User ) );
        }
    }
}

// ------------------------------------------------------------------
// Method      : Manage
// Parameters  : Nil
// Returns     : Nil
// Description : The root function that handles the control flow
//               of program
// ------------------------------------------------------------------
void CManage::Manage( void )
{
    int nChoice;

    cout<<"\n\n\n\t\t\t\tWelcome to XYZ Bank";
    sleep_for( seconds( 4 ) );
    while( 1 )
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

            case 9: cout<<"Thank you for using Banking Software"<<endl;
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

