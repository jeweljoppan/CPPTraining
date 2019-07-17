/**
 * File CIShape.h - Copyright (C) <2019>
 * <Triassic Solutions Private Limited>. All rights reserved.
 * This file contains the declaration of  class "CIShape".
 *
 *
 * Author   : Jewel Jo Prince
 * Version  : 1.0.0
 * Date     : 15-07-2019
 *
 */

#ifndef CISHAPE_H
#define CISHAPE_H

#include<iostream>
#include<conio.h>
#include<stdlib.h>

using namespace std;

/*
 * Class <CIShape>
 * <A base class for the classes CTriangle,CCircle,CRectangle>
 * Author : Jewel Jo Prince
 * Version : 1.0.0
 * Date : 15-07-2019
 *
 */

class CIShape
{
    public:
            virtual void ReadData( void  ) = 0;
            virtual void DrawShape( void ) = 0;
            virtual ~CIShape( void );
};

#endif // CISHAPE_H
