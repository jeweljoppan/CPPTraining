#include "CStudent.h"



CStudent::CStudent()
{
    m_data.nAdmNo = 0;
    strcpy( m_data.szName,  "\0" );
    m_data.cGender = '_';
    strcpy( m_data.szCourse, "\0" );
    strcpy( m_data.szDateOfJoin, "01/01/1990" );
}

void CStudent::AddData( /*IN*/ int nAdmno,
                        /*IN*/ char szName[],
                        /*IN*/ char cGender,
                        /*IN*/ char cCourse,
                        /*IN*/ char szDateOfJoin[] )
{
    m_data.nAdmNo = nAdmno;
    strcpy( m_data.szName, szName );
    m_data.cGender = cGender;
    switch( cCourse )
    {
        case '1': strcpy( m_data.szCourse, "Computer Science" );
                break;

        case '2': strcpy( m_data.szCourse, "Biology" );
                break;

        case '3': strcpy( m_data.szCourse, "Commerce" );
                break;
    }
    strcpy( m_data.szDateOfJoin, szDateOfJoin );                                                                                  ;
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
