/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

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
    fileName = "";
    fileNumberLeftEye = 0;
    fileNumberRightEye = 0;
    fileNumberMouth = 0;
    fileNumberNose = 0;
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
    
    
    
    cv::Rect roiE;
    float imgh, imgw;
    size_t ic =0; // ic is indext of current element
    int ac = 0; // ac is area of current element

    for(int i=0; i<listData.size();i++)
    {
        rOutRectData = listData[i];
    }
    for(ic =0; ic <listData.size();ic++)
    {      
        roiE.x = listData[ic].x;
        roiE.y = listData[ic].y*1.5;
        roiE.width = listData[ic].width;
        roiE.height = listData[ic].height/2;  
        //get face detected area - current element
        ac = roiE.width*roiE.height;
        if(roiE.width == roiE.height)
        {
            imgh = 16;
            imgw = 16;
            
        cout<<"th1"<<endl;
        }else if (roiE.width < roiE.height)
        {
            imgh =  16;
            imgw = 16/(roiE.height/roiE.width);
            
        }else if (roiE.width > roiE.height)
        {
            imgh = 16/(roiE.width/roiE.height);                  
            imgw = 16;
        }
        rOutRectData= roiE;
    }
    
    stringstream eyesleft;
    
    eyesleft.str("");
    
    eyesleft<<"/home/lordofknight93/Desktop/outPut/leftEye/lefteye"<<fileNumberLeftEye<<".png";
    
    if(listData.size() > 0 and listData.size() < 2)
    {
    returnMatrix = inputImage(rOutRectData); 
    resize(returnMatrix,returnMatrix,Size(imgw,imgh));
    fileNumberLeftEye++;
    imwrite(eyesleft.str(),returnMatrix);
    }
    else
    {
    return returnMatrix;    
    }
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
    cv::Rect roiE;
    float imgh, imgw;
    size_t ic =0; // ic is indext of current element
    int ac = 0; // ac is area of current element

    for(ic =0; ic <listData.size();ic++)
    {
        roiE.x = listData[ic].x;
        roiE.y = listData[ic].y*1.5;
        roiE.width = listData[ic].width;
        roiE.height = listData[ic].height/2;   
       // get face detected area - current element
        ac = roiE.width*roiE.height;
        if(roiE.width == roiE.height)
        {
            imgh = 16;
            imgw = 16;
            
        cout<<"th1"<<endl;
        }else if (roiE.width < roiE.height)
        {
            imgh =  16;
            imgw = 16/(roiE.height/roiE.width);
            
        }else if (roiE.width > roiE.height)
        {
            imgh = 16/(roiE.width/roiE.height);                  
            imgw = 16;
        }
        rOutRectData= roiE;
        
    }       
    stringstream eyesright;
    eyesright.str("");
    eyesright<<"/home/lordofknight93/Desktop/outPut/rightEye/righteye"<<fileNumberRightEye<<".png";
    
    if(listData.size() > 0 and listData.size()< 2)
   
    {
    returnMatrix = inputImage(rOutRectData);
    resize(returnMatrix,returnMatrix,Size(25,25));
    fileNumberRightEye++;
    imwrite(eyesright.str(),returnMatrix);
    }  
    else{
    return returnMatrix;
    }
}

Mat FacialDetect::detectMouth(Mat inputImage)
{
    if(!cMouth.load(uriMouth))
    {
        cout<<"cant load right mouth classifier"<<endl;
        return returnMatrix;
    }
    
    cMouth.detectMultiScale(inputImage,listData,1.1,3,0, Size(16,16));

    cout<<"number mouth detect: "<<listData.size()<<endl;
    cv::Rect roiE;
    float imgh, imgw;
    for(int i=0; i<listData.size();i++)
    {
        rOutRectData = listData[i];
        if(roiE.width == roiE.height)
        {
            imgh = 16;
            imgw = 16;
            
        cout<<"th1"<<endl;
        }else if (roiE.width < roiE.height)
        {
            imgh =  16;
            imgw = 16/(roiE.height/roiE.width);
            
        }else if (roiE.width > roiE.height)
        {
            imgh = 16/(roiE.width/roiE.height);                  
            imgw = 16;
        }
    }

    stringstream mouth;
    
    mouth.str("");
    mouth<<"/home/lordofknight93/Desktop/outPut/Mouth/mouth"<<fileNumberMouth<<".png";
    
    if(listData.size() > 0 and listData.size()< 2)
   
    {
    returnMatrix = inputImage(rOutRectData);
    resize(returnMatrix,returnMatrix,Size(imgw,imgh));
    fileNumberMouth++;
    imwrite(mouth.str(),returnMatrix);
    }  
    else{
    return returnMatrix;
    }
}

Mat FacialDetect::detectNose(Mat inputImage)
{
    if(!cNose.load(uriNose))
    {
        cout<<"cant load nose classifier"<<endl;
        return returnMatrix;
    }
    cNose.detectMultiScale(inputImage,listData,1.1,3,0, Size(16,16));
    cout<<"number nose detect: "<<listData.size()<<endl;
    cv::Rect roiE;
    float imgh, imgw;
    for(int i=0; i<listData.size();i++)
    {
        rOutRectData = listData[i];
        if(roiE.width == roiE.height)
        {
            imgh = 16;
            imgw = 16;
            
        cout<<"th1"<<endl;
        }else if (roiE.width < roiE.height)
        {
            imgh =  16;
            imgw = 16/(roiE.height/roiE.width);
            
        }else if (roiE.width > roiE.height)
        {
            imgh = 16/(roiE.width/roiE.height);                  
            imgw = 16;
        }
    }
    
    stringstream nose;
    
    nose.str("");
    nose<<"/home/lordofknight93/Desktop/outPut/Nose/nose"<<fileNumberNose<<".png";
    if(listData.size() > 0 and listData.size()< 2)
    {
    returnMatrix = inputImage(rOutRectData);
    resize(returnMatrix,returnMatrix,Size(imgw,imgh));
    fileNumberNose++;
    imwrite(nose.str(),returnMatrix);
    }
    else
    {
    return returnMatrix;    
    }
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
