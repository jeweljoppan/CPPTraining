/**
 * File CEmpDetails.h - Copyright (C) <2019>
 * <Triassic Solutions Private Limited>. All rights reserved.
 * This file contains the definition of class "CEmpDetails" which stores the details of employees.
 *
 * Author   : Jewel Jo Prince
 * Version  : 1.0.0
 * Date     : 08-07-2019
 *
 */

#ifndef DATE_H_INCLUDED
#define DATE_H_INCLUDED

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <iomanip>


using namespace std;


/*
 * Class <CEmpDetails>
 * <A class which stores details of employees.>
 * Author : Jewel Jo Prince
 * Version : 2.0.0
 * Date : 12-07-2019
 *
 */

class CEmpDetails
{
    private:
        string m_szName;
        string m_szDesignation;
        int m_nAge;
        float m_fSalary;
    public:
        int DataEntry( string,string,int,float );
        void DisplayData( void );
};

#endif // EMPDETAILS_H
