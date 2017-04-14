/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: ryu
 *
 * Created on April 13, 2017, 9:32 AM
 */

#include <cstdlib>
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <stdlib.h>
#include <stdio.h>
#include <opencv2/opencv.hpp>
#include "FacialDetect.h"
using namespace cv;
using namespace std;


/*
 * 
 */
int main(int argc, char** argv) {
     Mat src, dst;
     FacialDetect detect;
     detect.SetUriLeftEyes("/usr/local/share/OpenCV/haarcascades/haarcascade_lefteye_2splits.xml");
     src = imread("/home/ryu/Documents/testData/GrayImage/Grayimage99.png");
     dst=detect.detectLeftEye(src);
     namedWindow("test window",WINDOW_AUTOSIZE);
     cout<<"hahah"<<endl;
     imshow("test window",dst);
     waitKey(0);
     

    return 0;
}

