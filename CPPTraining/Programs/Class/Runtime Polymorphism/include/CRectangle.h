/**
 * File CRectangle.h - Copyright (C) <2019>
 * <Triassic Solutions Private Limited>. All rights reserved.
 * This file contains the member functions of  class "CRectangle".
 *
 *
 * Author   : Jewel Jo Prince
 * Version  : 1.0.0
 * Date     : 15-07-2019
 *
 */

#ifndef CRECTANGLE_H
#define CRECTANGLE_H

#include "CIShape.h"

/*
 * Class <CRectangle>
 * <A stores details of a rectangle.>
 * Author : Jewel Jo Prince
 * Version : 1.0.0
 * Date : 15-07-2019
 *
 */

class CRectangle : public CIShape
{
    private:
            float m_fLength;
            float m_fBreadth;
            float m_fArea;
    public:
            void ReadData( void );
            void DrawShape( void );
            CRectangle( void );
            virtual ~CRectangle( void );
};

#endif // CCRECTANGLE_H
