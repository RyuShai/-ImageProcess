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
    
    //get all array int mat image
    //inputMat: mat image after simple color
    //
    vector< vector<Point> > listArrayColor(Mat &inputMat, Vec3b color);
    void popPixel(Mat &inputMat , int x, int y, vector<Point> &add);
   
    
private:

};

#endif /* UTILITIES_H */

