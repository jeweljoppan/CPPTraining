/**
 * File date.cpp - Copyright (C) <2019>
 * <Triassic Solutions Private Limited>. All rights reserved.
 * This file contains the main function of the program. This program
 * calculates to calculate the volume of different shapes using method
 * overloading.
 *
 * Author   : Jewel Jo Prince
 * Version  : 1.0.0
 * Date     : 10-07-2019
 *
 */

 #include "CVolume.h"

int main()
{
    CVolume volume;
    int nChoice;
    int nFlag = -1;
    char cCheck = 'Y';

    do{
        cout<<"\n1. CUBE";
        cout<<"\n2. CUBOID";
        cout<<"\n3. SPHERE";
        cout<<"\nEnter integer corresponding to the shape of choice: ";
        cin>>nChoice;
        cout<<"\n\n";
        nFlag = volume.GetMeasure( nChoice );
        if( nFlag == -1)
        {
            cout<<"\nInvalid Input. ";
            goto skip;
        }
        else if ( nFlag = 1)
        {
            cout<<"\nData entry successful. ";
        }
        volume.PrintVolume();
        skip:
        cout<<"Enter 'Y' to try again: ";
        cin>>cCheck;
        cCheck = toupper( cCheck );
        system( "cls" );
    }while( cCheck == 'Y' );
    cout<<"Program exited"<<endl;
    return 0;
}
