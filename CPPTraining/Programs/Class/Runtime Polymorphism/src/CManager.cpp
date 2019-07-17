/**
 * File CManager.cpp - Copyright (C) <2019>
 * <Triassic Solutions Private Limited>. All rights reserved.
 * This file contains the member functions of  class "CManager".
 *
 *
 * Author   : Jewel Jo Prince
 * Version  : 1.0.0
 * Date     : 15-07-2019
 *
 */

#include "CManager.h"

//Static variable initialization
int CManager::m_nCount = 0;

// ------------------------------------------------------------------
// Method      : Intro
// Parameters  : Nil
// Returns     : Nil
// Description : Prints what the program does.
// ------------------------------------------------------------------
void CManager::Intro( void )
{
    cout<<"This menu driven program gets input from user and display shapes.\n";
    cout<<string(65,'_');
}

// ------------------------------------------------------------------
// Method      : Menu
// Parameters  : Nil
// Returns     : Nil
// Description : Displays and iterates the menu.
// ------------------------------------------------------------------
void CManager::Menu( void )
{
    int nChoice = 0;
    while(1)
    {
        cout<<"\n\n0 .Exit";
        cout<<"\n1. Triangle";
        cout<<"\n2. Circle";
        cout<<"\n3. Rectangle";
        cout<<"\n4. Draw selected shape(s)";
        cout<<"\nPlease choose an option by providing an input as number(0,1,2,3 or 4): ";
        cin>>nChoice;
        cout<<"\n";
        HandleChoice( nChoice );
    }
}

// ------------------------------------------------------------------
// Method      : HandleChoice
// Parameters  :
//   <param 1> - <int nChoice> - Choice inputed by the user.
// Returns     : Nil
// Description : Process the choice of the user.
// ------------------------------------------------------------------
void CManager::HandleChoice(/*IN*/ int nChoice )
{
    switch( nChoice )
    {
        case 0: cout<<"Program exiting.\n";
                exit( 0 );
                break;

        case 1: m_pTriangle = new CTriangle;
                m_pTriangle->ReadData();
                AllocateSpace();
                m_pShapes[m_nCount-1] = dynamic_cast<CIShape *>(m_pTriangle);
                break;

        case 2: m_pCircle = new CCircle;
                m_pCircle->ReadData();
                AllocateSpace();
                m_pShapes[m_nCount-1] = dynamic_cast<CIShape *>(m_pCircle);
                break;

        case 3: m_pRectangle = new CRectangle;
                m_pRectangle->ReadData();
                AllocateSpace();
                m_pShapes[m_nCount-1] = dynamic_cast<CIShape *>(m_pRectangle);
                break;

        case 4: DrawShape();
                break;

        default: cout<<"Invalid option.";
    }
}

// ------------------------------------------------------------------
// Method      : AllocateSpace
// Parameters  : Nil
// Returns     : Nil
// Description : Dynamically reallocates the memory of the array.
// ------------------------------------------------------------------
void CManager::AllocateSpace( void )
{
    CIShape **pShapeNew;

    ++m_nCount;
    pShapeNew = (CIShape **)realloc(m_pShapes, sizeof(CIShape*)*m_nCount-1);
    m_pShapes = pShapeNew;
}

// ------------------------------------------------------------------
// Method      : DrawShape
// Parameters  : Nil
// Returns     : Nil
// Description : Prints the area of selected shape
// ------------------------------------------------------------------
void CManager::DrawShape( void )
{
    int nTemp = 0;

    cout<<"\n";
    while( nTemp < m_nCount )
    {
        m_pShapes[nTemp]->DrawShape();
        ++nTemp;
    }
}

// ------------------------------------------------------------------
// Method      : Manage
// Parameters  : Nil
// Returns     : Nil
// Description : Manages the control flow.
// ------------------------------------------------------------------
void CManager::Manage( void )
{
    CIShape **pShapes = new CIShape*[1];

    m_pShapes = pShapes;
    Intro();
    Menu();

}

// ------------------------------------------------------------------
// Method      : Destructor
// Parameters  : Nil
// Returns     : Nil
// Description : De allocates memory
// ------------------------------------------------------------------
CManager::~CManager( void )
{
    delete[] m_pShapes;
    delete m_pCircle;
    delete m_pRectangle;
    delete m_pTriangle;
}
