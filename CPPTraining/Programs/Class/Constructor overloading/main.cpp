/**
 * File main.cpp - Copyright (C) <2019>
 * <Triassic Solutions Private Limited>. All rights reserved.
 * This file contains the main function of the program. This program
 * calculates to calculate the volume of different shapes using constructor
 * overloading.
 *
 * Author   : Jewel Jo Prince
 * Version  : 1.0.0
 * Date     : 08-07-2019
 *
 */

 #include "CVolume.h"

int main()
{
    int nChoice;
    char cCheck = 'Y';

    do
    {
        cout<<"\nShapes: ";
        cout<<"\n\n1. CUBE";
        cout<<"\n2. CUBOID";
        cout<<"\n3. SPHERE";
        again:
        cout<<"\n\nEnter integer corresponding to the shape of choice: ";
        cin>>nChoice;
        cout<<"\n\n";
        switch( nChoice )
        {
            case 1: Cube();
                    break;

            case 2: Cuboid();
                    break;

            case 3: Sphere();
                    break;

            default: cout<<"\nInvalid Input.";
                     goto again;
        }
        cout<<"Enter 'Y' to try again: ";
        cin>>cCheck;
        system( "cls" );
        cCheck = toupper( cCheck );
    }while( cCheck == 'Y' );
    cout<<"Program exited\n\n";
    return 0;
}
