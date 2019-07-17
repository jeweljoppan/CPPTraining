
/**
 * File main.cpp - Copyright (C) <2019>
 * <Triassic Solutions Private Limited>. All rights reserved.
 * This file contains the main of sample functions
 *
 * Author   : Jewel Jo Prince
 * Version  : 1.0.0
 * Date     : 04-07-2019
 *
 */

 #include   <iostream>
 #include   <string.h>

 using namespace std;

 void StrLength(/*IN*/ int nLength = 0)
 {
         cout<<"Length of your name is "<<nLength;
 }


int main()
{
    string szName;
    int nLength;

    cout<<"Enter your name: ";
    getline(cin,szName);
    nLength = szName.size();
    StrLength(nLength);


    return 0;
}
