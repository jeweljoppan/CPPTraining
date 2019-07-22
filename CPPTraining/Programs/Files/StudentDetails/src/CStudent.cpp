#include "CStudent.h"



CStudent::CStudent()
{
    m_data.nAdmNo = 0;
    m_data.szName = "\0";
    m_data.cGender = '_';
    m_data.szCourse = "\0";
    m_data.szDateOfJoin = "01/01/1990";
}

void CStudent::AddData( /*IN*/ int nAdmno,
                        /*IN*/ string szName,
                        /*IN*/ char cGender,
                        /*IN*/ int nCourse,
                        /*IN*/ string szDateOfJoin )
{
    m_data.nAdmNo = nAdmno;
    m_data.szName = szName;
    m_data.cGender = cGender;
    switch( nCourse )
    {
        case 1: m_data.szCourse = "Computer Science";
                break;

        case 2: m_data.szCourse = "Biology";
                break;

        case 3: m_data.szCourse = "Commerce";
                break;
    }
    m_data.szDateOfJoin = szDateOfJoin                                                                                  ;
    cout<<"Saving details to file."<<endl;
}

int CStudent::GetAdmNo( void )
{
    return m_data.nAdmNo;
}

void CStudent::View( void )
{
    cout<<"Name\t\t:"<<m_data.szName<<endl;
    cout<<"Admission Number:"<<m_data.nAdmNo<<endl;
    cout<<"Gender\t\t:"<<m_data.cGender<<endl;
    cout<<"Course\t\t:"<<m_data.szCourse<<endl;
    cout<<"Date of Join\t:"<<m_data.szDateOfJoin<<endl;
}

void CStudent::ViewTab( void )
{
    cout<<setw( 10 )<<m_data.szName;
    cout<<setw( 10 )<<m_data.nAdmNo;
    cout<<setw( 10 )<<m_data.cGender;
    cout<<setw( 10 )<<m_data.szCourse;
    cout<<setw( 10 )<<m_data.szDateOfJoin;
}
