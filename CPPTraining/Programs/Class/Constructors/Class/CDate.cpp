/**
 * File date.pp - Copyright (C) <2019>
 * <Triassic Solutions Private Limited>. All rights reserved.
 * This file contains the member functions of  class date.
 *
 *
 * Author   : Jewel Jo Prince
 * Version  : 1.0.0
 * Date     : 05-07-2019
 *
 */
 #include "CDate.h"


 using namespace std;

// -------------------------------------------------------
// Method      : print
// Parameters  : Nil
// Returns     : void
// Description : Displays the stored time
// -------------------------------------------------------

void CDate::Print(void)
{
    cout<<m_nMonth<<"-"<<m_nDay<<"-"<<m_nYear;
}

// -------------------------------------------------------
// Method      : Constructor
// Parameters  :
//   <param 1> - <int nMonth> - month inputed by the user.
//   <param 2> - <int nDay> - Day inputed by user.
//   <param 3> - <int nYear> - Year inputed by user.
// Returns     : void
// Description : Initializes the member variables with the arguments.
// -------------------------------------------------------

CDate::CDate(/*IN*/ int nMonth,
             /*IN*/ int nDay,
             /*IN*/ int nYear)
{
    m_nMonth = nMonth;
    m_nDay = nDay;
    m_nYear = nYear;
}

// -------------------------------------------------------
// Method      : Constructor
// Parameters  : Nil
// Returns     : void
// Description : Initializes the member variables with the current time.
// -------------------------------------------------------

 CDate::CDate(void)
{
    time_t now = time(0);
    tm *ltm = localtime(&now);
    m_nMonth = 1 + ltm->tm_mon;
    m_nDay = ltm->tm_mday;
    m_nYear = 1900 + ltm->tm_year;
}
