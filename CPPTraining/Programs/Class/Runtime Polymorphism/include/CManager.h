/**
 * File CManager.h - Copyright (C) <2019>
 * <Triassic Solutions Private Limited>. All rights reserved.
 * This file contains the member functions of  class "CManager".
 *
 *
 * Author   : Jewel Jo Prince
 * Version  : 1.0.0
 * Date     : 15-07-2019
 *
 */

#ifndef CMANAGER_H
#define CMANAGER_H

#include "CCircle.h"
#include "CRectangle.h"
#include "CTriangle.h"


/*
 * Class <CManager>
 * <Handles the control flow of the program.>
 * Author : Jewel Jo Prince
 * Version : 1.0.0
 * Date : 16-07-2019
 *
 */

class CManager
{
    private:
            CIShape **m_pShapes;
            static int m_nCount;
            CTriangle *m_pTriangle;
            CRectangle *m_pRectangle;
            CCircle *m_pCircle;
            static void Intro( void );
            void Menu( void );
            void HandleChoice( int );
            void AllocateSpace( void );
            void DrawShape( void );
    public:
            void Manage( void );
            virtual ~CManager( void );

};

#endif // CMANAGER_H
