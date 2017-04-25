/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Utilities.h
 * Author: ryu
 *
 * Created on April 22, 2017, 10:40 AM
 */

#ifndef UTILITIES_H
#define UTILITIES_H
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;
class Utilities {
public:
    Utilities();
    Utilities(const Utilities& orig);
    virtual ~Utilities();
    
    //re-color image matrix to 2 color 
    //inputMat : gray image
    //meanTimes : times re-scale mean value, as larger as smaller value
    //smallColor: the color set to pixel has value <= meant value
    //bigColor: the color set to pixel has value > meant value
    Mat simpleColor(Mat &inputMat , int meanTimes, Vec3b smallColor, Vec3b bigColor);
    Mat drawLine(Mat& inputMat,int x , int y);
    //return colections of pixels which is nexto each other
    //inputMat: mat image after simple color
    //color : color  will be find in matrix
    vector< vector<Point> > listArrayColor(Mat &inputMat, Vec3b color);
    
    //drawMatImage
    //draw list point to matrix
    //inputMat: matrix will be draw
    //listPixel : list coordinate
    //color : color of pixel will be draw
    void drawMatImage(Mat &inputMat,vector<Point> listPixel, Vec3b color);
   
    
private:
    //popPixel
    //sub-function of listArrayColor, add all pixel apandable to collection
    //inpuMat : source matrix
    //row, col :start coordinate in matrix use to expandable
    vector<Point> popPixel(Mat &inputMat,int row, int col);
};

#endif /* UTILITIES_H */

