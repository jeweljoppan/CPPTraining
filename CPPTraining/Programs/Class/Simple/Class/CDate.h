/**
 * File date.h - Copyright (C) <2019>
 * <Triassic Solutions Private Limited>. All rights reserved.
 * This file contains the definition of class " date ".
 *
 * Author   : Jewel Jo Prince
 * Version  : 1.0.0
 * Date     : 05-07-2019
 *
 */

#ifndef DATE_H_INCLUDED
#define DATE_H_INCLUDED

#include<iostream>
#include<ctime>
/*
 * Class <CDate>
 * <A simple class which stores and prints date.>
 * Author : Jewel Jo Prince
 * Version : 1.0.0
 * Date : 05 June 2019
 *
 */

class CDate
{
    private:
        int m_nDay;
        int m_nMonth;
        int m_nYear;

    public:
        void Init( int nMonth, int nDay, int nYear);
        void Init(void);
        void Print(void);

};

#endif // DATE_H_INCLUDED
