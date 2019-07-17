/**
 * File CCircle.cpp - Copyright (C) <2019>
 * <Triassic Solutions Private Limited>. All rights reserved.
 * This file contains the member functions of  class "CCircle".
 *
 *
 * Author   : Jewel Jo Prince
 * Version  : 1.0.0
 * Date     : 15-07-2019
 *
 */

#include "CRectangle.h"

// ------------------------------------------------------------------
// Method      : ReadData
// Parameters  : Nil
// Returns     : Nil
// Description : Reads measurements and calculate the area of the shape.
// ------------------------------------------------------------------
void CRectangle::ReadData( void )
{
    cout<<"Enter the measurement of the rectangle in cm:\n";
    cout<<"Length: ";
    cin>>m_fLength;
    cout<<"Breadth: ";
    cin>>m_fBreadth;
    this->m_fArea = m_fLength * m_fBreadth;
}

// ------------------------------------------------------------------
// Method      : DrawShape
// Parameters  : Nil
// Returns     : Nil
// Description : Prints the Area of the shape.
// ------------------------------------------------------------------
void CRectangle::DrawShape( void )
{
    cout<<"Drawing rectangle with area: "<<m_fArea<<" cm^2\n";
}

// ------------------------------------------------------------------
// Method      : Constructor
// Parameters  : Nil
// Returns     : Nil
// Description : Initializes data members with 0.
// ------------------------------------------------------------------
CRectangle::CRectangle( void )
{
    m_fArea = 0;
    m_fBreadth = 0;
    m_fLength = 0;
}

// ------------------------------------------------------------------
// Method      : Destructor
// Parameters  : Nil
// Returns     : Nil
// Description : De allocates memory
// ------------------------------------------------------------------
CRectangle::~CRectangle( void )
{
    //dtor
}
