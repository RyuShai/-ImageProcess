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
#include <string>
#include <stdio.h>
#include <opencv2/opencv.hpp>
#include "FacialDetect.h"
#include <sstream>
using namespace cv;
using namespace std;


/*
 * 
 */

int main(int argc, char** argv) {

     FacialDetect detect;
    //set input  xml for classifier
     /* left eye */
    detect.SetUriLeftEyes("/usr/local/share/OpenCV/haarcascades/haarcascade_lefteye_2splits.xml");
     /* right eye */
    detect.SetUriRightEyes("/usr/local/share/OpenCV/haarcascades/haarcascade_righteye_2splits.xml");
     /* mouth */
    detect.SetUriMouth("/usr/local/share/OpenCV/haarcascades/mouth_2.xml");
      /* nose */
    detect.SetUriNose("/usr/local/share/OpenCV/haarcascades/Nariz_nuevo_20stages.xml");
    //
    //input - output path 
    detect.setInputPath("/home/ryu/Documents/testData/input/LeftEye/");
    detect.setOutputPath("/home/ryu/Documents/testData/output/LeftEye/");
    detect.setInputImageName("lefteye");
    detect.setOutputImageName("lefteye");
    detect.setInputImageType(".png");
    detect.setOutputImageType(".png");
    detect.setInputCounter(0);
    detect.setOutputCounter(0);
    
    detect.getROIObject("/home/ryu/Documents/testData/input/LeftEye/","lefteye",0,".png");
    
//    Mat src( 50,  70, CV_8UC1 , Scalar(1)); // 5x7
//    Mat dst(100, 100, CV_8UC1, Scalar(255)); // 10x10
//
//src.copyTo(dst.rowRange(0,50),dst.colRange(0,src.cols));
//namedWindow("1",100);
//imshow("1",dst);
    
    waitKey();
    return 0;
}

