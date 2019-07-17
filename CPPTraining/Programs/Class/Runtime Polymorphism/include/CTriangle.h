/**
 * File CTriangle.h - Copyright (C) <2019>
 * <Triassic Solutions Private Limited>. All rights reserved.
 * This file contains the member functions of  class "CTriangle".
 *
 *
 * Author   : Jewel Jo Prince
 * Version  : 1.0.0
 * Date     : 15-07-2019
 *
 */

#ifndef CTRIANGLE_H
#define CTRIANGLE_H

#include "CIShape.h"

#define TRIANLGE_AREA_CONST 0.5

/*
 * Class <CTriangle>
 * <A stores details of a triangle.>
 * Author : Jewel Jo Prince
 * Version : 1.0.0
 * Date : 15-07-2019
 *
 */

class CTriangle: public CIShape
{
    private:
            float m_fHeight;
            float m_fBreadth;
            float m_fArea;
    public:
        void ReadData( void );
        void DrawShape ( void );
        CTriangle( void );
        virtual ~CTriangle( void );
};

#endif // CTRIANGLE_H
