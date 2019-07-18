#include "CFile.h"

CFile::CFile( void )
{
    storage.open( "STUDENT.DAT", ios::in | ios::out | ios::binary );
    if( !storage )
    {
        cout<<"File access failed."<<endl;
        exit( 0 );
    }
    else
    {
        //unimplemented
    }
}

CStudent CFile::GetData( int nAdmNo )
{
    CStudent temp;
    ios.seekg( 0, ios::beg );
    while( !storage.eof() )
    {
        storage.read((C*)&temp,sizeof(temp));
        if( nAdmNo == temp->GetAdmn() )
        {
            return temp;
        }
        else
        {
            //unimplemented
        }
    }
    return temp;
}

void CFile::ViewAll( void )
{
    CStudent temp;
    ios.seekg( 0, ios::beg );
    while( !storage.eof() )
    {
        storage.read((CStudent*)&temp,sizeof(temp));


    }
}
CFile::~CFile( void )
{
    storage.close();
}
