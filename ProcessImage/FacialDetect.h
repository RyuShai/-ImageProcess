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
#include "opencv2/objdetect.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"

#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace cv;
using namespace std;

class FacialDetect {
public:
    FacialDetect();
    FacialDetect(const FacialDetect& orig);
    virtual ~FacialDetect();
    
    Mat detectLeftEye(Mat inputImage);
    Mat detectRightEye(Mat inputImage);
    Mat detectNose(Mat inputImage);
    Mat detectBrow(Mat inputImage);
    Mat detectForeHead(Mat inputImage);
    Mat detectMouth(Mat inputImage);
    
    
    
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
private:
    string uriLeftEyes;
    string uriRightEyes;
    string uriNose;
    string uriBrow;
    string uriForeHead;
    string uriMouth;
    
    CascadeClassifier cLeftEye;
    CascadeClassifier cRightEye;
    CascadeClassifier cNose;
    CascadeClassifier cBrow;
    CascadeClassifier cForeHead;
    CascadeClassifier cMouth;
    
    vector<Rect> listData;
    Rect rOutRectData;
    Mat returnMatrix;
};

#endif /* FACIALDETECT_H */

