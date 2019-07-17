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

#include "CCircle.h"

// ------------------------------------------------------------------
// Method      : ReadData
// Parameters  : Nil
// Returns     : Nil
// Description : Read and stores measurements of circle. Also computes area.
// ------------------------------------------------------------------
void CCircle::ReadData( void )
{
    cout<<"Enter the measurement of the circle in cm: \n";
    cout<<"Radius: ";
    cin>>m_fRadius;
    this->m_fArea = PIE * m_fRadius * m_fRadius;
}

// ------------------------------------------------------------------
// Method      : DrawShape
// Parameters  : Nil
// Returns     : Nil
// Description : Prints the area of Circle.
// ------------------------------------------------------------------
void CCircle::DrawShape( void )
{
    cout<<"Drawing circle with area: "<<this->m_fArea<<" cm^2\n";
}
CCircle::CCircle( void )
{
    m_fRadius = 0;
    m_fArea = 0;
}

// ------------------------------------------------------------------
// Method      : Destructor
// Parameters  : Nil
// Returns     : Nil
// Description : De allocates memory
// ------------------------------------------------------------------
CCircle::~CCircle( void )
{
    //dtor
}
