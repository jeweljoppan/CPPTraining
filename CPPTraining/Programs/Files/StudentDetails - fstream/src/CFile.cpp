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
        //unimplemented
    }
}
void CFile::Write( CStudent data )
{
    storage.seekp( 0L, ios::end );
    storage.write( ( char* )( &data ),sizeof( data ) );
    storage.flush();
}

CStudent CFile::GetData( int nAdmNo )
{
  CStudent temp;
/*
    istorage.open( "STUDENT.dat", ios::in | ios::binary );
    if( !istorage )
    {
        cout<<"File access failed or file does not exist."<<endl;
        exit( 0 );
    }
    else
    {
        //unimplemented
    }
    istorage.seekg( 0, ios::beg );
    while( !istorage.eof() )
    {
        istorage.read( ( char* )&temp,sizeof( temp ) );
        if( nAdmNo == temp.GetAdmNo() )
        {
            return temp;
        }
        else
        {
            //unimplemented
        }
    }
    istorage.close();
    */
    return temp;
}

void CFile::ViewAll( void )
{
    CStudent temp;

    cout<<storage.tellp()<<"\t"<<storage.tellg()<<"\n";
    storage.seekp( 0L, ios::beg );
    storage.seekg( 0L, ios::beg );
    cout<<storage.tellp()<<"\t"<<storage.tellg()<<"\n";
    while( storage.read( ( char* )&temp, sizeof( CStudent ) ) )
    {
        temp.ViewTab();
        cout<<endl;

    }
    cout<<storage.tellg();
}

void CFile::ClearSpec( int nAdmNo )
{/*
    CStudent temp;
    ofstream fout("temp.dat", ios::out | ios::binary | ios::trunc );
    while( istorage.read( ( char* )&temp, sizeof( temp ) ) )
    {
        if( temp.GetAdmNo() != nAdmNo )
        {
            fout.write( ( char* )&temp,sizeof( temp ) );
        }
        else
        {
            //else unimplemented
        }
    }*/
}

void CFile::ClearFile( void )
{
  /*  istorage.close();
    ostorage.close();
    remove( "STUDENT.dat" );
    ostorage.open("STUDENT.dat", ios::out | ios::binary );
    if( !ostorage )
    {
        cout<<"File access failed or file does not exist."<<endl;
        exit( 0 );
    }
    else
    {
        //unimplemented
    }
    ostorage.close();
    */
}

CFile::~CFile( void )
{
    storage.close();
}
