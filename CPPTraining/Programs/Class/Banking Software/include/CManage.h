/**
 * File CManage.h - Copyright (C) <2019>
 * <Triassic Solutions Private Limited>. All rights reserved.
 * This file contains declaration the member functions of  class "CManage".
 *
 *
 * Author   : Jewel Jo Prince
 * Version  : 1.0.0
 * Date     : 16-07-2019
 *
 */

#ifndef CMANAGE_H
#define CMANAGE_H

#include "CSaving.h"
#include "CCurrent.h"

/*
 * Class <CManage>
 * <A class which handles all control flow.>
 * Author : Jewel Jo Prince
 * Version : 1.0.0
 * Date : 17-07-2019
 *
 */

class CManage
{
    private:
        vector<CAccount*> Accounts;
        static const string m_szAdminPass;
    public:
        void Intro( void );
        int AdminAccess( void );
        void AddUser( void );
        void DeleteUser( void );
        void DisplayAll( void );
        void HandleChoiceAdmin( void );
        int MainMenu( void );
        void MenuAdmin( void );
        vector<CAccount*>::iterator GetUser( void );
        void PrintMenu( void );
        void HandleChoiceUser( int,CAccount* );
        void MenuUser( void );
        void Manage( void );
};

#endif // CMANAGE_H
