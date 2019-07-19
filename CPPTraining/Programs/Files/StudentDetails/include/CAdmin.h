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
//#include <chrono>
//#include <thread>

//using namespace std::this_thread;
//using namespace std::chrono;
class CAdmin
{
    private:
        CStudent m_student;
        CFile m_file;
        static int m_nAdmCount;
        void Menu( void );
        void HandleChoice( void );
        void AddNew( void );
        void ViewSpec( void );
        void ViewAll( void );
        void DeleteSpec( void );
        void DeleteAll( void );
        void Hold( void );
    public:
        void Manage( void );
};

#endif // CADMIN_H
