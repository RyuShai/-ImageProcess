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
//Lefteyes
// ThangDM    

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
    
    
    
//    cv::Rect roiE;
//    
//    size_t ic =0; // ic is indext of current element
//    int ac = 0; // ac is area of current element
//    
//    size_t ib = 0; // ib is index of biggest element
//    int ab = 0; // ab is area of biggest element
//
//    
//    for(ic =0; ic <listData.size();ic++)
//    {      
//        roiE.x = listData[ic].x*0.8;
//        roiE.y = listData[ic].y*1.7;
//        roiE.width = listData[ic].width;
//        roiE.height = listData[ic].height*0.6;  
//        //get face detected area - current element
//        ac = roiE.width*roiE.height;     
//        rOutRectData= roiE;
//    }
    for(int i=0; i<listData.size();i++)
    {
        rOutRectData = listData[i];
    }
    cout<<"ryu 1"<<endl;
    if(listData.size() > 0 )
    {
    returnMatrix = inputImage(rOutRectData);
//    resize(returnMatrix-listData.size()/2,returnMatrix,Size(25,20),INTER_LINEAR);
    resize(returnMatrix,returnMatrix,Size(25,25));
    cout<<"ryu 2"<<endl;
    return returnMatrix;
    }
    return returnMatrix;    
}

//Righteye
//DucNM

Mat FacialDetect::detectRightEye(Mat inputImage)
{
    if(!cRightEye.load(uriRightEyes))
    {
        cout<<"cant load right eyes classifier"<<endl;
        return returnMatrix;
    }
    
    cRightEye.detectMultiScale(inputImage,listData,1.1,3,0, Size(16,16));

    cout<<"number eyes detect: "<<listData.size()<<endl;
    
    for(int i=0; i<listData.size();i++)
    {
        rOutRectData = listData[i];
    }
    
    
//    cv::Rect roiE;
//    
//    size_t ic =0; // ic is indext of current element
//    int ac = 0; // ac is area of current element
//    
//    size_t ib = 0; // ib is index of biggest element
//    int ab = 0; // ab is area of biggest element
//
//    
//    for(int i =0; i <listData.size();i++)
//    {
//        roiE.x = listData[ic].x*2.7;
//        roiE.y = listData[ic].y*1.5;
//        roiE.width = listData[ic].width;
//        roiE.height = listData[ic].height*0.8;   
//       // get face detected area - current element
//        ac = roiE.width*roiE.height; 
//        rOutRectData= roiE;
//        
//    }
    cout<<"ryu 3"<<endl;
    if(listData.size() > 0 )
    {
    returnMatrix = inputImage(rOutRectData);
    resize(returnMatrix,returnMatrix,Size(25,25));
    cout<<"ryu 4"<<endl;
    return returnMatrix;
    }  
    return returnMatrix;
}

Mat FacialDetect::detectMouth(Mat inputImage)
{
    if(!cMouth.load(uriMouth))
    {
        cout<<"cant load mouth classifier"<<endl;
        return returnMatrix;
    }
    
    //find left eye in matrix
    cMouth.detectMultiScale(inputImage,listData,1.1,3,0, Size(16,16));


    cout<<"number mouth detect: "<<listData.size()<<endl;
    for(int i=0; i<listData.size();i++)
    {
        rOutRectData = listData[i];
    }
    cout<<"ryu 5"<<endl;
    if(listData.size() > 0 )
    {
    returnMatrix = inputImage(rOutRectData);
    resize(returnMatrix,returnMatrix,Size(72,72));
    cout<<"ryu 6"<<endl;
    return returnMatrix;
    }
    return returnMatrix;
}

Mat FacialDetect::detectNose(Mat inputImage)
{
    if(!cNose.load(uriNose))
    {
        cout<<"cant load nose classifier"<<endl;
        return returnMatrix;
    }
    
    //find left eye in matrix
    cNose.detectMultiScale(inputImage,listData,1.1,3,0, Size(15,15));


    cout<<"number mouth detect: "<<listData.size()<<endl;
    for(int i=0; i<listData.size();i++)
    {
        rOutRectData = listData[i];
    }
    cout<<"ryu 7"<<endl;
    if(listData.size() > 0 )
    {
    returnMatrix = inputImage(rOutRectData);
    resize(returnMatrix,returnMatrix,Size(72,72));
    cout<<"ryu 8"<<endl;
    return returnMatrix;
    }
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
