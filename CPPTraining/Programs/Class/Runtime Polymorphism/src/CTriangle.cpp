/**
 * File CTriangle.cpp - Copyright (C) <2019>
 * <Triassic Solutions Private Limited>. All rights reserved.
 * This file contains the member functions of  class "CTriangle".
 *
 *
 * Author   : Jewel Jo Prince
 * Version  : 1.0.0
 * Date     : 15-07-2019
 *
 */

#include "CTriangle.h"

// ------------------------------------------------------------------
// Method      : ReadData
// Parameters  : Nil
// Returns     : Nil
// Description : Reads measurements and calculate the area of the shape.
// ------------------------------------------------------------------
void CTriangle::ReadData( void )
{
    cout<<"Enter the measurements of the traingle in cm: \n";
    cout<<"Height: ";
    cin>>m_fHeight;
    cout<<"Breadth: ";
    cin>>m_fBreadth;
    this->m_fArea = TRIANLGE_AREA_CONST * m_fBreadth * m_fHeight;
}

// ------------------------------------------------------------------
// Method      : DrawShape
// Parameters  : Nil
// Returns     : Nil
// Description : Prints the Area of the shape.
// ------------------------------------------------------------------
void CTriangle::DrawShape( void )
{
    cout<<"Drawing triangle with area: "<<this->m_fArea<<" cm^2\n";
}

// ------------------------------------------------------------------
// Method      : Constructor
// Parameters  : Nil
// Returns     : Nil
// Description : Initializes data members with 0.
// ------------------------------------------------------------------
CTriangle::CTriangle( void )
{
    m_fArea = 0;
    m_fBreadth = 0;
    m_fHeight = 0;
}

// ------------------------------------------------------------------
// Method      : Destructor
// Parameters  : Nil
// Returns     : Nil
// Description : De allocates memory
// ------------------------------------------------------------------
CTriangle::~CTriangle( void )
{
    //dtor
}
