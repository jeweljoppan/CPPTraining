/**
 * File CEmpDetails.cpp - Copyright (C) <2019>
 * <Triassic Solutions Private Limited>. All rights reserved.
 * This file contains the member functions of  class "CEmpDetials".
 *
 *
 * Author   : Jewel Jo Prince
 * Version  : 1.0.0
 * Date     : 08-07-2019
 *
 */

#include "CEmpDetails.h"

// ------------------------------------------------------------------
// Method      : DataEntry
// Parameters  :
//   <param 1> - <char szName[]> - Name of employee.
//   <param 2> - <strng szDesignation> - Designation of the employee.
//   <param 3> - <int nAge> - Age of the employee.
//   <param 4> - <float fSalary> - month inputed by the user.
// Returns     : int
// Description : Stores each employees details to the object.
// ------------------------------------------------------------------
int CEmpDetails::DataEntry ( /*IN*/ string szName,
                            /*IN*/ string szDesignation,
                            /*IN*/ int nAge,
                            /*IN*/ float fSalary )
{
    m_szName = szName ;
    m_szDesignation = szDesignation;
    m_nAge = nAge;
    m_fSalary = fSalary;
    return 1;
}

// ------------------------------------------------------------------
// Method      : DisplayData
// Parameters  : Nil
// Returns     : void
// Description : Prints the Data of the employee.
// ------------------------------------------------------------------
void CEmpDetails::DisplayData( void )
{
    cout<<setw(20)<<setiosflags( ios::left )<<m_szName;
    cout<<setw(5)<<setiosflags( ios::left )<<m_nAge;
    cout<<setw(15)<<setiosflags( ios::left )<<m_fSalary;
    cout<<setw(10)<<setiosflags( ios::left )<<m_szDesignation;
}
