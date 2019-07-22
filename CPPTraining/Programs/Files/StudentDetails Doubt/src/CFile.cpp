#include "CFile.h"

CFile::CFile( void )
{
    ostorage.open("STUDENT.dat", ios::out | ios::binary | ios::ate );
    if( !ostorage )
    {
        cout<<"File access failed or file does not exist."<<endl;
        exit( 0 );
    }
    else
    {
        //unimplemented
    }
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
}
void CFile::Write( CStudent data )
{
    ostorage.seekp( 0, ios::end );
    ostorage.write( reinterpret_cast<const char*>( &data ),sizeof( data ) );
    ostorage.flush();
}

CStudent CFile::GetData( int nAdmNo )
{
    CStudent temp;
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
    return temp;
}

void CFile::ViewAll( void )
{
    CStudent temp;
    cout<<istorage.tellg()<<"\n";
    istorage.clear();
    istorage.seekg( 0, ios::beg );
    while( istorage.read( ( char* )&temp, sizeof( CStudent ) ) )
    {
        cout<<"in\n";
        temp.ViewTab();
        cout<<"after\n";
    }
    cout<<istorage.tellg();
}

void CFile::ClearSpec( int nAdmNo )
{
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
    }
}

void CFile::ClearFile( void )
{
    istorage.close();
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

    istorage.open( "STUDENT.dat", ios::in | ios::binary  );
    if( !istorage )
    {
        cout<<"File access failed or file does not exist."<<endl;
        exit( 0 );
    }
    else
    {
        //unimplemented
    }
}

CFile::~CFile( void )
{
    ostorage.close();
    istorage.close();
}
