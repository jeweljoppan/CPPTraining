#include "CStudent.h"



CStudent::CStudent()
{
    m_nAdmNo = 0;
    m_szName = "\0";
    m_cGender = '\0';
    m_szCourse = "\0";
    m_DateOfJoin = "01/01/1990";
}

void CStudent::AddData( /*IN*/ int nAdmno,
                        /*IN*/ string szName,
                        /*IN*/ char cGender,
                        /*IN*/ int nCourse,
                        /*IN*/ string szDateOfJoin )
{
    m_nAdmNo = nAdmno;
    m_szName = szName;
    m_cGender = cGender;
    switch( nCourse )
    {
        case 1: m_szCourse = "Computer Science";
                break;

        case 2: m_szCourse = "Biology";
                break;

        case 3: m_szCourse = "Commerce";
                break;
    }
    m_szDateOfJoin = szDateOfJoin;
    cout<<"Saving details to file."<<endl;
}

int CStudent::GetAdmNo( void )
{
    return m_nAdmNo;
}

void CStudent::View( void )
{
    cout<<"Name\t\t:"<<m_szName<<endl;
    cout<<"Admission Number\t:"<<m_nAdmNo<<endl;
    cout<<"Gender\t\t:"<<m_cGender<<endl;
    cout<<"Course\t\t:"<<m_szCourse<<endl;
    cout<<"Date of Join\t:"<<m_szDateOfJoin<<end;
}

void CStudent::ViewTab( void )
{

}
