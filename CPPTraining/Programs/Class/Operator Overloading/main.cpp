/**
 * File main.cpp - Copyright (C) <2019>
 * <Triassic Solutions Private Limited>. All rights reserved.
 * This file contains the main function of the program. This program
 * Overload the operator “+” so that we can add two Complex instance
 * like C3 = C1 + C2, C1 + C2
 *
 * Author   : Jewel Jo Prince
 * Version  : 1.0.0
 * Date     : 11-07-2019
 *
 */

#include"CComplex.h"

int main()
{
    float fReal;
    float fImaginary;



    Intro();
    cout<<"\n\nEnter the real part of c1\t: ";
    cin>>fReal;
    cout<<"Enter the imaginary part of c1\t: ";
    cin>>fImaginary;
    CComplex c1( fReal,fImaginary );
    cout<<"\nEnter the real part of c2\t: ";
    cin>>fReal;
    cout<<"Enter the imaginary part of c2\t: ";
    cin>>fImaginary;
    CComplex c2( fReal,fImaginary );
    CComplex c3 = ( c1 + c2 );
    c3.PrintData();
    return 0;
}
