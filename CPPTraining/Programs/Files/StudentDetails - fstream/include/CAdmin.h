/**
 * File CAdmin.h - Copyright (C) <2019>
 * <Triassic Solutions Private Limited>. All rights reserved.
 * This file contains the declaration of a Class "CAdmin"
 *
 * Author   : Jewel Jo Prince
 * Version  : 1.0.0
 * Date     : 18-07-2019
 *
 */

#ifndef CADMIN_H
#define CADMIN_H

#include "CStudent.h"
#include "CFile.h"
#include "CInputValidate.h"

/*
 * Class <CAdmin>
 * <A class which manages the control flow of program.>
 * Author : Jewel Jo Prince
 * Version : 1.0.0
 * Date : 18-07-2019
 *
 */

class CAdmin
{
    private:
        CStudent m_student;
        CInputValidate m_check;
        static int m_nAdmCount;
        void Menu( void );
        void HandleChoice( void );
        void AddNew( void );
        void UserData( int nAdmNo = 0 );
        void ViewSpec( void );
        void ViewAll( void );
        void Modify( void );
        void DeleteSpec( void );
        void DeleteAll( void );
        void Hold( void );
    public:
        CAdmin();
        void Manage( void );
};

#endif // CADMIN_H
