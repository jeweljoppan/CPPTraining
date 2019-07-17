/**
 * File CCirlce.h - Copyright (C) <2019>
 * <Triassic Solutions Private Limited>. All rights reserved.
 * This file contains the member functions of  class "CCircle".
 *
 *
 * Author   : Jewel Jo Prince
 * Version  : 1.0.0
 * Date     : 15-07-2019
 *
 */

#ifndef CCIRCLE_H
#define CCIRCLE_H

#include "CIShape.h"

#define PIE 3.14

/*
 * Class <CCircle>
 * <A stores details of a circle.>
 * Author : Jewel Jo Prince
 * Version : 1.0.0
 * Date : 15-07-2019
 *
 */

class CCircle : public CIShape
{
    private:
            float m_fRadius;
            float m_fArea;
    public:
            void ReadData( void );
            void DrawShape( void );
            CCircle( void );
            virtual ~CCircle( void );
};

#endif // CCIRCLE_H
