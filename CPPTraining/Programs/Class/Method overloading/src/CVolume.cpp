/**
 * File CVolume.cpp - Copyright (C) <2019>
 * <Triassic Solutions Private Limited>. All rights reserved.
 * This file contains the member functions of  class "CVolume".
 *
 *
 * Author   : Jewel Jo Prince
 * Version  : 1.0.0
 * Date     : 10-07-2019
 *
 */

 #include"CVolume.h"

// ------------------------------------------------------------------
// Method      : GetMeasure
// Parameters  : Nil
// Returns     : Nil
// Description : Gets the measures of the shape from the user.
// ------------------------------------------------------------------
int CVolume::GetMeasure( int nChoice )
{

    switch( nChoice )
    {
    case 1: cout<<"------------Enter the measure of Cube------------";
            cout<<"\nMeasure of edge in 'cm': ";
            cin>>m_fEdge;
            m_fVolume = Volume( m_fEdge );
            break;

    case 2: cout<<"------------Enter the measures of Cuboid------------";
            cout<<"\nMeasure of Length in 'cm': ";
            cin>>m_fLength;
            cout<<"\nMeasure of Breadth in 'cm': ";
            cin>>m_fBreadth;
            cout<<"\nMeasure of Height in 'cm': ";
            cin>>m_fHeight;
            m_fVolume= Volume( m_fLength,m_fBreadth,m_fHeight );
            break;

    case 3: cout<<"------------Enter the measure of Sphere------------";
            cout<<"\nMeasure of Radius in 'cm': ";
            cin>>m_dRadius;
            m_fVolume = Volume( m_dRadius );
            break;
    default: return -1;
    }
    return 1;
}

// ------------------------------------------------------------------
// Method      : Volume
// Parameters  :
//   <param 1> - <float fEdge> - Measure of edge of Cube.
// Returns     : float
// Description : Find and returns the volume of Cube.
// ------------------------------------------------------------------
float CVolume::Volume( float fEdge )
{
    return fEdge * fEdge * fEdge;
}

// ------------------------------------------------------------------
// Method      : Volume
// Parameters  :
//   <param 1> - <float fLength> - Measure of length of Cuboid.
//   <param 2> - <float fBreadth> - Measure of Breadth of Cuboid.
//   <param 3> - <float fHeight> - Measure of Height of Cuboid.
// Returns     : float
// Description : Find and returns the volume of Cube.
// ------------------------------------------------------------------

float CVolume::Volume( float fLength,float fBreadth,float fHeight )
{
    return fLength * fBreadth * fHeight;
}

// ------------------------------------------------------------------
// Method      : Volume
// Parameters  :
//   <param 1> - <double dRadius> - Measure of radius of Sphere.
// Returns     : float
// Description : Find and returns the volume of Sphere.
// ------------------------------------------------------------------
float CVolume::Volume( double dRadius )
{
    return CIRCLE_AREA_CONST * PIE * dRadius * dRadius * dRadius;
}

// ------------------------------------------------------------------
// Method      : PrintVolume
// Parameters  : Nil
// Returns     : Nil
// Description : Prints the found volume.
// ------------------------------------------------------------------
void CVolume::PrintVolume( void )
{
    cout<<"\nThe Volume is "<<m_fVolume<<" cm^3.\n\n";
}

