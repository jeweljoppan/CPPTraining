/**
 * File CComplex.cpp - Copyright (C) <2019>
 * <Triassic Solutions Private Limited>. All rights reserved.
 * This file contains the member functions of  class "CComplex".
 *
 *
 * Author   : Jewel Jo Prince
 * Version  : 1.0.0
 * Date     : 11-07-2019
 *
 */

 #include"CComplex.h"

// ------------------------------------------------------------------
// Method      : Constructor
// Parameters  :
// Returns     : Nil
// Description : allocates memory for new object.
// ------------------------------------------------------------------
 CComplex::CComplex( )
{
    //Constructor that is invoked when no arguments are passed.
}

// ------------------------------------------------------------------
// Method      : Constructor
// Parameters  :
//   <param 1> - <float fReal> - Real part of the complex number.
//   <param 2> - <float fImaginary> - Imaginary part of the complex number.
// Returns     : Nil
// Description : Copy real and imaginary part to data members.
// ------------------------------------------------------------------
 CComplex::CComplex( float fReal,float fImaginary )
{
    m_fReal = fReal;
    m_fImaginary = fImaginary;
}

// ------------------------------------------------------------------
// Method      : Operator +
// Parameters  :
//   <param 1> - <CComplex const &obj> - Constant variable holding address of a
//                                       CComplex Object
// Returns     : CComplex
// Description : Overloads operator "+" to add to objects of CComplex.
// ------------------------------------------------------------------
CComplex CComplex::operator +( CComplex const &obj )
{
    CComplex temp;
    temp.m_fReal = m_fReal + obj.m_fReal;
    temp.m_fImaginary = m_fImaginary + obj.m_fImaginary;
    return temp;
}

// ------------------------------------------------------------------
// Method      : PrintData
// Parameters  : Nil
// Returns     : Nil
// Description : Prints the Complex number.
// ------------------------------------------------------------------
void CComplex::PrintData( void )
{
    cout<<"\nValue of c3 is "<<m_fReal<<"+ i"<<m_fImaginary;
    cout<<"\n";
}

// ------------------------------------------------------------------
// Method      : Intro
// Parameters  : Nil
// Returns     : Nil
// Description : Gives an Introduction of what the program does.
// ------------------------------------------------------------------
void Intro()
{
    cout<<"\nThis program shows the implementation of operator overloading.";
    cout<<"\nSum of two complex numbers (c1 and c2) will be stored in complex number c3.";
}
