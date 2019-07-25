/**
 * File CSudent.h - Copyright (C) <2019>
 * <Triassic Solutions Private Limited>. All rights reserved.
 * This file contains the declaration of a Class "CStudent"
 * to handle student details
 *
 * Author   : Jewel Jo Prince
 * Version  : 1.0.0
 * Date     : 18-07-2019
 *
 */

#ifndef CSTUDENT_H
#define CSTUDENT_H

#include <iostream>
#include <ctime>
#include <string.h>
#include <conio.h>
#include <iomanip>
#include <stdio.h>

#define MAX_LENGTH 20
#define DATE_LENGTH 11

using namespace std;

// Structure that holds the details of student.

struct stStudent
{
    int nAdmNo;
    char szName[MAX_LENGTH];
    char cGender;
    char szCourse[MAX_LENGTH];
    char szDateOfJoin[DATE_LENGTH];
};

/*
 * Class <CStudent>
 * <A class which stores details of students.>
 * Author : Jewel Jo Prince
 * Version : 2.0.0
 * Date : 12-07-2019
 *
 */

class CStudent
{
    private:
        struct stStudent m_data;
    public:
        CStudent( void );
        void AddData( int, char [], char, char, char [] );
        int GetAdmNo( void );
        void View( void );
        void ViewTab( void );
};

#endif // CSTUDENT_H
