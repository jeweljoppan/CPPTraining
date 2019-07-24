#include "CFile.h"

CFile::CFile( void )
{
    storage.open( "STUDENT.dat", ios::in | ios::out| ios::binary );
    if( !storage )
    {
        cout<<"File access failed or file does not exist."<<endl;
        exit( 0 );
    }
    else
    {

    }
}

int CFile::ReturnAdmnNo()
{
    CStudent data;

    storage.seekg( 0, ios::end );
    storage.read( ( char* )( &data ), -sizeof( data ) );
    return data.GetAdmNo();
}

void CFile::Write( CStudent data )
{
    storage.seekp( 0L, ios::end );
    storage.write( ( char* )( &data ), sizeof( data ) );
    storage.flush();
}

CStudent CFile::GetData( int nAdmNo )
{
    CStudent temp;

    storage.seekg( 0, ios::beg );
    while( storage.read( ( char* )&temp,sizeof( temp ) )
           )
    {
        if( nAdmNo == temp.GetAdmNo() )
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
    int nFlag = 0;

    storage.seekp( 0L, ios::beg );
    storage.seekg( 0L, ios::beg );
    while( storage.read( ( char* )&temp, sizeof( CStudent ) ) )
    {
        temp.ViewTab();
        cout<<endl;
        nFlag = 1;
    }
    if( nFlag == 0 )
    {
        system( "cls" );
        cout<<"\n\n\t\tFile Empty\n\n"<<endl;
    }
    else
    {
        //unimplemented
    }
}

void CFile::ClearSpec( int nAdmNo )
{
    CStudent temp;
    fstream fout("temp.dat", ios::out | ios::binary | ios::trunc );
    while( storage.read( ( char* )&temp, sizeof( temp ) ) )
    {
        if( temp.GetAdmNo() != nAdmNo )
        {
            fout.write( ( char* )&temp,sizeof( temp ) );
        }
        else
        {
            //else unimplemented
        }
    }
}

void CFile::ClearFile( void )
{
    storage.close();
    remove( "STUDENT.dat" );
    storage.open("STUDENT.dat", ios::out | ios::binary );
    if( !storage )
    {
        cout<<"File access failed or file does not exist."<<endl;
        exit( 0 );
    }
    else
    {
        //unimplemented
    }
    storage.close();
}

CFile::~CFile( void )
{
    storage.close();
}
