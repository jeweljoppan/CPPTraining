#include "CFile.h"

CFile::CFile( void )
{
    storage.open( "STUDENT.dat", ios::in | ios::out | ios::binary );
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
        temp->ViewTab();
    }
}

void CFile::ClearSpec( int nAdmNo )
{
    CStudent temp;
    ofstream fout("temp.dat", ios::out | ios::binary | ios::trunc );
    while( storage.read( ( CStudent* )&temp, sizeof( temp ) )
    {
        if( temp->GetAdmNo() != nAdmNo )
        {
            fout.write( ( char* )&temp,sizeof( temp ))
        }
        else
        {
            //else unimplemented
        }
    }
}

void CFile::ClearFile( void )
{
    remove( "STUDENT.dat" );
    storage.close();
    storage.open( "STUDENT.dat", ios::in | ios::out | ios::binary | ios::trunc );
    if( !storage )
    {
        cout<<"File clearing failed."<<endl;
        exit( 0 );
    }
    else
    {
        //unimplemented
    }

}

CFile::~CFile( void )
{
    storage.close();
}
