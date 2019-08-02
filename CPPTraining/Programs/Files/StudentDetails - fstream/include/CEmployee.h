/**
 * File Cemployee.h - Copyright (C) <2019>
 * <Triassic Solutions Private Limited>. All rights reserved.
 * This file contains the declaration of a Class "CEmployee"
 * to handle student details
 *
 * Author   : Jewel Jo Prince
 * Version  : 1.0.0
 * Date     : 26-07-2019
 *
 */

#ifndef CEMPLOYEE_H
#define CEMPLOYEE_H

#define MAX_LENGTH 20
#define DATE_MAX_LENGTH 11
#define ADM_MAX_LENGTH 10
#define LEAVE_MAX_LEANGTH
struct stEmployee
{
    char szAdmNo[ADM_MAX_LENGTH];
    char szName[MAX_LENGTH];
    char szDesignation[MAX_LENGTH];
    int nContactNumber;
    char szEmail[MAX_LENGTH];
    int nLeave;
    char szLeaveDates[LEAVE_MAX_LEANGTH][DATE_MAX_LENGTH];
};

class CEmployee
{
    protected:
        struct m_stEmployee;
    public:
        virtual void AddNew() = 0;
        void GetEmployeeID();
        void ShowLeave();
        void View();
        virtual void Salary() = 0;
};

#endif // CEMPLOYEE_H
