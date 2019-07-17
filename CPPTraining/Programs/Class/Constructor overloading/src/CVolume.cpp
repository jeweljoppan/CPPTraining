/**
 * File CVolume.cpp - Copyright (C) <2019>
 * <Triassic Solutions Private Limited>. All rights reserved.
 * This file contains the member functions of  class "CVolume".
 *
 *
 * Author   : Jewel Jo Prince
 * Version  : 1.0.0
 * Date     : 08-07-2019
 *
 */

 #include"CVolume.h"

// ------------------------------------------------------------------
// Method      : Constructor
// Parameters  :
//   <param 1> - <float fEdge> - Measure of edge of Cube.
// Returns     : Nil
// Description : Copy measures of cube to data members.
// ------------------------------------------------------------------
 CVolume::CVolume( float fEdge )
{
    m_fEdge = fEdge;
    m_fVolume = fEdge * fEdge * fEdge;
}

// ------------------------------------------------------------------
// Method      : Constructor
// Parameters  :
//   <param 1> - <float fLength> - Measure of length of Cuboid.
//   <param 2> - <float fBreadth> - Measure of Breadth of Cuboid.
//   <param 3> - <float fHeight> - Measure of Height of Cuboid.
// Returns     : Nil
// Description : Copy measures of cuboid to data members.
// ------------------------------------------------------------------
CVolume::CVolume( float fLength,float fBreadth,float fHeight )
{
    m_fLength = fLength;
    m_fBreadth = fBreadth;
    m_fHeight = fHeight;
    m_fVolume = fLength * fBreadth * fHeight;
}

// ------------------------------------------------------------------
// Method      : Constructor
// Parameters  :
//   <param 1> - <double dRadius> - Measure of radius of Sphere.
// Returns     : float
// Description : Copy measures of Sphere to data members.
// ------------------------------------------------------------------
CVolume::CVolume( double dRadius )
{
    m_dRadius = dRadius;
    m_fVolume = CIRCLE_AREA_CONST * PIE * dRadius * dRadius * dRadius;
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

// ------------------------------------------------------------------
// Method      : Cube
// Parameters  : Nil
// Returns     : Nil
// Description : Finds the Volume of the Cube.
// ------------------------------------------------------------------
void Cube( void )
{
    float fEdge;
    cout<<"------------Enter the measure of Cube------------";
    cout<<"\nMeasure of edge in 'cm': ";
    cin>>fEdge;
    CVolume volume( fEdge );
    system( "cls" );
    volume.PrintVolume();
}

// ------------------------------------------------------------------
// Method      : Cuboid
// Parameters  : Nil
// Returns     : Nil
// Description : Finds the Volume of the Cuboid.
// ------------------------------------------------------------------
void Cuboid( void )
{
    float fLength;
    float fBreadth;
    float fHeight;
    cout<<"------------Enter the measures of Cuboid------------";
    cout<<"\nMeasure of Length in 'cm': ";
    cin>>fLength;
    cout<<"\nMeasure of Breadth in 'cm': ";
    cin>>fBreadth;
    cout<<"\nMeasure of Height in 'cm': ";
    cin>>fHeight;
    CVolume volume( fLength,fBreadth,fHeight );
    system( "cls" );
    volume.PrintVolume();
}

// ------------------------------------------------------------------
// Method      : Sphere
// Parameters  : Nil
// Returns     : Nil
// Description : Finds the Volume of the Sphere
// ------------------------------------------------------------------
void Sphere( void )
{
    double dRadius;
    cout<<"------------Enter the measure of Sphere------------";
    cout<<"\nMeasure of Radius in 'cm': ";
    cin>>dRadius;
    CVolume volume( dRadius );
    system( "cls" );
    volume.PrintVolume();
}
