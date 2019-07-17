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
    cout<<"\nShapes: ";
    cout<<"\n\n1. CUBE";
    cout<<"\n2. CUBOID";
    cout<<"\n3. SPHERE";
    cout<<"\n\nEnter integer corresponding to the shape of choice: ";
    cin>>nChoice;
    cout<<"\n\n";
    system( "cls" );
    switch( nChoice )
    {
        case 1: Cube();
                break;

        case 2: Cuboid();
                break;

        case 3: Sphere();
                break;

        default: cout<<"\nInvalid Input. Press a button to continue.";
                 getch();
                 exit(0);
    }
    return 87;
}
