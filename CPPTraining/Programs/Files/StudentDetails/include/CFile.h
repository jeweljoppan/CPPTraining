/**
 * File CFile.h - Copyright (C) <2019>
 * <Triassic Solutions Private Limited>. All rights reserved.
 * This file contains the declaration of a Class "CFile" to handle files.
 *
 * Author   : Jewel Jo Prince
 * Version  : 1.0.0
 * Date     : 18-07-2019
 *
 */

#ifndef CFILE_H
#define CFILE_H

#include <fstream>
#include <CStudent.h>

class CFile
{
    private:
        fstream istorage;
        fstream ostorage;
    public:
        CFile( void );
        void Write( CStudent );
        CStudent GetData( int );
        void ViewAll( void );
        void ClearSpec( int nAdmNo );
        void ClearFile( void );
        ~CFile( void );
};

#endif // CFILE_H
