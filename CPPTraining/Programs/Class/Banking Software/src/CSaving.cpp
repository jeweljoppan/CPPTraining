/**
 * File CSsving.h - Copyright (C) <2019>
 * <Triassic Solutions Private Limited>. All rights reserved.
 * This file contains the definition member functions of  class "CSaving".
 *
 *
 * Author   : Jewel Jo Prince
 * Version  : 1.0.0
 * Date     : 16-07-2019
 *
 */

#include "CSaving.h"

int CSaving::m_nAccountCount = 0;

void CSaving::AddUser( string szName, float fBalance )
{
    m_szName = szName;
    m_fBalance = fBalance;
    m_szAccountno = "S"+ to_string(m_nAccountCount);
    m_nAccountCount++;
}

void CSaving::WithDraw( float fAmount )
{
    m_fBalance = m_fBalance - fAmount;
    ViewBalance();
}

void CSaving::CalculateInterest( void )
{

}
CSaving::CSaving( void )
{
    m_szAccountno = "\0";
    m_szAccType = 'S';
    m_szName = "\0";
    m_fBalance = 0;
}

CSaving::~CSaving( void )
{
    //dtor
}
