/**
 * File date.cpp - Copyright (C) <2019>
 * <Triassic Solutions Private Limited>. All rights reserved.
 * This file contains the main function of the program.
 *
 * Author   : Jewel Jo Prince
 * Version  : 1.0.0
 * Date     : 05-07-2019
 *
 */

#include "CDate.h"

using namespace std;

int main()
{
    CDate today;
    CDate someDay( 31, 11, 2019);
    cout << "\n----------------------------------\n\n";
    cout << "Today's date: ";
    today.Print();
    cout << "\nSome day: ";
    someDay.Print();
    cout << "\n\n----------------------------------\n";
    return 0;
}
