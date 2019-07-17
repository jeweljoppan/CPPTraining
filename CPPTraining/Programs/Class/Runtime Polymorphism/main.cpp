/**
 * File main.cpp - Copyright (C) <2019>
 * <Triassic Solutions Private Limited>. All rights reserved.
 * This file contains the the main function of the program to create a base class
 * “IShape” with should have a pure virtual functions ReadData() and DrawShape()
 * Derive three classes “CTriangle”, “CCircle” and “CRectangle” from “IShape”.
 * Three of them need to implement the ReadData() and DrawShape() methods.
 *
 *
 * Author   : Jewel Jo Prince
 * Version  : 1.0.0
 * Date     : 15-07-2019
 *
 */

 #include "CManager.h"

 int main()
 {
     CManager manager;
     manager.Manage();
     return 0;
 }
