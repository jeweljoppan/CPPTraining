/**
 * File CComplex.h - Copyright (C) <2019>
 * <Triassic Solutions Private Limited>. All rights reserved.
 * This file contains the declaration of  class "CComplex".
 *
 *
 * Author   : Jewel Jo Prince
 * Version  : 1.0.0
 * Date     : 11-07-2019
 *
 */

#ifndef CCOMPLEX_H
#define CCOMPLEX_H

#include<iostream>
#include<conio.h>
#include<stdlib.h>

using namespace std;

/*
 * Class <CComplex>
 * <A class which holds a complex number.>
 * Author : Jewel Jo Prince
 * Version : 1.0.0
 * Date : 11-07-2019
 *
 */

 class CComplex
 {
    private:
        float m_fReal;
        float m_fImaginary;
    public:
        CComplex( void );
        CComplex( const CComplex & );
        CComplex( float,float );
        CComplex operator +( CComplex const & );
        void PrintData ( void );
 };

 void Intro();
#endif // CCOMPLEX_H

