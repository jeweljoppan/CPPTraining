#include "CStudent.h"

// ------------------------------------------------------------------
// Method      : Constructor
// Parameters  : Nil
// Returns     : Nil
// Description : Initializes the data members with default value.
// ------------------------------------------------------------------
CStudent::CStudent()
{
    m_data.nAdmNo = 0;
    strcpy( m_data.szName,  "\0" );
    m_data.cGender = '_';
    strcpy( m_data.szCourse, "\0" );
    strcpy( m_data.szDateOfJoin, "01/01/1990" );
}

// ------------------------------------------------------------------
// Method      : AddData
// Parameters  :
//  <param 1>  - <int nAdmno> - Admission number of student.
//  <param 2>  - <char szName[]> - Name of student.
//  <param 3>  - <char cGender> - Gender of student
//  <param 4>  - <char cCourse> - Value corresponding to the course selected by user.
//  <param 5>  - <char szDateOfJoin[]> - Date of joining of student
// Returns     : Nil
// Description : Method to copy user data to data members.
// ------------------------------------------------------------------
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

        default : strcpy( m_data.szCourse, " " );
                break;
    }
    strcpy( m_data.szDateOfJoin, szDateOfJoin );                                                                                  ;
}

// ------------------------------------------------------------------
// Method      : GetAdmNo
// Parameters  : Nil
// Returns     : int
// Description : Returns the admission number.
// ------------------------------------------------------------------
int CStudent::GetAdmNo( void )
{
    return m_data.nAdmNo;
}

// ------------------------------------------------------------------
// Method      : View
// Parameters  : Nil
// Returns     : Nil
// Description : Prints the student details.
// ------------------------------------------------------------------
void CStudent::View( void )
{
    cout<<"Name\t\t: "<<m_data.szName<<endl;
    cout<<"Admission Number: "<<m_data.nAdmNo<<endl;
    cout<<"Gender\t\t: "<<m_data.cGender<<endl;
    cout<<"Course\t\t: "<<m_data.szCourse<<endl;
    cout<<"Date of Join\t: "<<m_data.szDateOfJoin<<endl;
}

// ------------------------------------------------------------------
// Method      : ViewTab
// Parameters  : Nil
// Returns     : Nil
// Description : Prints the user details in tabular format.
// ------------------------------------------------------------------
void CStudent::ViewTab( void )
{
    cout<<setw( 15 )<<setiosflags(ios::left)<<m_data.nAdmNo;
    cout<<setw( 20 )<<setiosflags(ios::left)<<m_data.szName;
    cout<<setw( 10 )<<setiosflags(ios::left)<<m_data.cGender;
    cout<<setw( 18 )<<setiosflags(ios::left)<<m_data.szCourse;
    cout<<setw( 20 )<<setiosflags(ios::left)<<m_data.szDateOfJoin;
}
