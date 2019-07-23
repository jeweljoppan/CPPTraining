/**
 * File CEmpDetails.h - Copyright (C) <2019>
 * <Triassic Solutions Private Limited>. All rights reserved.
 * This file contains the definition of class "CManager" .
 *
 * Author   : Jewel Jo Prince
 * Version  : 1.0.0
 * Date     : 12-07-2019
 *
 */

#ifndef CMANAGER_H
#define CMANAGER_H

#include "CEmpDetails.h"
#include "CInputValidate.h"

/*
 * Class <CManager>
 * <A class manages functionalities such as grouping,data entry,printing etc. >
 * Author : Jewel Jo Prince
 * Version : 1.0.0
 * Date : 12-07-2019
 *
 */

class CManager
{
    private:
        CEmpDetails *m_pEmpDetails;
        int m_nCount;
        int m_nFlag;
        string m_szName;
        int m_nDesignation;
        int m_nAge;
        string m_szDesignation;
        int m_nManager;
        int m_nDeveloper;
        int m_nTrainee;
        float m_fSalary;
        void Intro( void );
        int AllocateSpace();
        int StoreData( int );
        int SortData( int );
        void DoShift( int,int );
        void GetData( void );
        void PrintData();
        CInputValidate m_check;
    public:
        CManager( void );
        ~CManager( void );
        void ManageAll( void );
};

#endif // CMANAGER_H
