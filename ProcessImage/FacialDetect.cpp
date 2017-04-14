/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FacialDetect.cpp
 * Author: ryu
 * 
 * Created on April 13, 2017, 2:39 PM
 */

#include "FacialDetect.h"

FacialDetect::FacialDetect() {
}

FacialDetect::FacialDetect(const FacialDetect& orig) {
}

FacialDetect::~FacialDetect() {
}

Mat FacialDetect::detectLeftEye(Mat inputImage)
{
    if(!cLeftEye.load(uriLeftEyes))
    {
        cout<<"cant load left eyes classifier"<<endl;
        return returnMatrix;
    }
    
    //find left eye in matrix
    cLeftEye.detectMultiScale(inputImage,listData,1.1,3,0, Size(16,16));
    cout<<"number eyes detect: "<<listData.size()<<endl;
    for(int i=0; i<listData.size();i++)
    {
        rOutRectData = listData[i];
    }
    cout<<"ryu 1"<<endl;
    returnMatrix = inputImage(rOutRectData);
    resize(returnMatrix,returnMatrix,Size(72,72));
    cout<<"ryu2"<<endl;
    return returnMatrix;
}


void FacialDetect::SetUriMouth(string uriMouth) {
    this->uriMouth = uriMouth;
}

string FacialDetect::GetUriMouth() const {
    return uriMouth;
}

void FacialDetect::SetUriForeHead(string uriForeHead) {
    this->uriForeHead = uriForeHead;
}

string FacialDetect::GetUriForeHead() const {
    return uriForeHead;
}

void FacialDetect::SetUriBrow(string uriBrow) {
    this->uriBrow = uriBrow;
}

string FacialDetect::GetUriBrow() const {
    return uriBrow;
}

void FacialDetect::SetUriNose(string uriNose) {
    this->uriNose = uriNose;
}

string FacialDetect::GetUriNose() const {
    return uriNose;
}

void FacialDetect::SetUriRightEyes(string uriRightEyes) {
    this->uriRightEyes = uriRightEyes;
}

string FacialDetect::GetUriRightEyes() const {
    return uriRightEyes;
}

void FacialDetect::SetUriLeftEyes(string uriLeftEyes) {
    this->uriLeftEyes = uriLeftEyes;
}

string FacialDetect::GetUriLeftEyes() const {
    return uriLeftEyes;
}

