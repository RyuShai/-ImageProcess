/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FacialDetect.h
 * Author: ryu
 *
 * Created on April 13, 2017, 2:39 PM
 */

#ifndef FACIALDETECT_H
#define FACIALDETECT_H
#include <cstdlib>
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"

#include <stdio.h>
#include <string.h>
#include <iostream>
#include <sstream>

using namespace cv;
using namespace std;
using namespace CONFIG;

class FacialDetect {
public:
    FacialDetect();
    FacialDetect(const FacialDetect& orig);
    virtual ~FacialDetect();
    //detect basic using opencv
    Mat detectLeftEye(Mat inputImage);
    Mat detectRightEye(Mat inputImage);
    Mat detectNose(Mat inputImage);
    Mat detectBrow(Mat inputImage);
    Mat detectForeHead(Mat inputImage);
    Mat detectMouth(Mat inputImage);
    //----------------------------------
    //----------ROI process---------
    //draw contour as image
    //input = Mat object detected
    void thresh_callback(Mat input);
    void getROIObject(string inputpath, string imageName, int counterNumber, string imagetype);
    //------------------------------
    
    
    //access private data
    void SetUriMouth(string uriMouth);
    string GetUriMouth() const;
    void SetUriForeHead(string uriForeHead);
    string GetUriForeHead() const;
    void SetUriBrow(string uriBrow);
    string GetUriBrow() const;
    void SetUriNose(string uriNose);
    string GetUriNose() const;
    void SetUriRightEyes(string uriRightEyes);
    string GetUriRightEyes() const;
    void SetUriLeftEyes(string uriLeftEyes);
    string GetUriLeftEyes() const;
    void setOutputPath(string outputPath);
    string getOutputPath() const;
    void setInputPath(string inputPath);
    string getInputPath() const;
    void setOutputImageType(string outputImageType);
    string getOutputImageType() const;
    void setInputImageType(string inputImageType);
    string getInputImageType() const;
    void setOutputImageName(string outputImageName);
    string getOutputImageName() const;
    void setInputImageName(string inputImageName);
    string getInputImageName() const;
    void setOutputCounter(int outputCounter);
    int getOutputCounter() const;
    void setInputCounter(int inputCounter);
    int getInputCounter() const;
    
    //public variable

private:
    string uriLeftEyes;
    string uriRightEyes;
    string uriNose;
    string uriBrow;
    string uriForeHead;
    string uriMouth;
    
    string inputImageName;
    string outputImageName;
    string inputImageType;
    string outputImageType;
    int inputCounter; // input Path/filename+inputCounter.filetype 
    int outputCounter;// output Path/filename+outputCounter.filetype 
    
    string inputPath;
    string outputPath;
    std::stringstream outPutStream;
    std::stringstream inputStream;
    
    CascadeClassifier cLeftEye;
    CascadeClassifier cRightEye;
    CascadeClassifier cNose;
    CascadeClassifier cBrow;
    CascadeClassifier cForeHead;
    CascadeClassifier cMouth;
    
    vector<Rect> listData;
    Rect rOutRectData;
    Mat returnMatrix;
    
    Mat sourceImage;
    Mat graySourceImage;
    
    FILE *fFile;
    
};

#endif /* FACIALDETECT_H */

