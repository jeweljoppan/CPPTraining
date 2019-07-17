/**
 * File CVolume.h - Copyright (C) <2019>
 * <Triassic Solutions Private Limited>. All rights reserved.
 * This file contains the definition of class "CEmpDetails" which stores the details of employees.
 *
 * Author   : Jewel Jo Prince
 * Version  : 1.0.0
 * Date     : 10-07-2019
 *
 */


#ifndef CVOLUME_H
#define CVOLUME_H


#include<iostream>
#include<conio.h>
#include<stdlib.h>

#define CIRCLE_AREA_CONST 1.33
#define PIE 3.14

using namespace std;

/*
 * Class <CVolume>
 * <A class which calculates the volume of the object.>
 * Author : Jewel Jo Prince
 * Version : 1.0.0
 * Date : 10-07-2019
 *
 */

class CVolume
{
    public:
        int GetMeasure( int );
        float Volume( float );
        float Volume( float,float,float );
        float Volume( double );
        void PrintVolume( void );
    private:
        float m_fEdge;
        float m_fLength;
        float m_fBreadth;
        float m_fHeight;
        float m_fVolume;
        double m_dRadius;
};

#endif // CVOLUME_H
