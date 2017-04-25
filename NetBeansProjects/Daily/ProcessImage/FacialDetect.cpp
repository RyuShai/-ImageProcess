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
#include "CONFIG.h"


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

    if(listData.size() > 0 )
    {
    returnMatrix = inputImage(rOutRectData);
    resize(returnMatrix,returnMatrix,Size(25,25));

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
    
    if(listData.size() > 0 )
    {
    returnMatrix = inputImage(rOutRectData);
    resize(returnMatrix,returnMatrix,Size(72,72));
    
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


//ROI process
void FacialDetect::thresh_callback(Mat inputSource)
{  
    cout<<"start"<<endl;
    Mat canny_output;
    vector<vector<Point> > contours;
    vector<Vec4i> hierarchy;
    outputCounter=0;
    /// Detect edges using canny
    Canny(inputSource, canny_output, 45, 45*2, 3);
    /// Find contours
    findContours(canny_output, contours, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE, Point(0, 0));
    cout<<"contour: "<<contours.size()<<endl;
    /// Draw contours
    Mat drawing = Mat::zeros(canny_output.size(), CV_8UC3);
    for (int i = 0; i < contours.size(); i++) {
        Scalar color = Scalar(0, 0, 255);
        drawContours(drawing, contours, i, color, 1, 8, hierarchy, 0, Point());
    }
    this->outPutStream<<outputPath<<outputImageName<<outputCounter<<outputImageType<<endl;
    fFile = fopen(outPutStream.str().c_str(),"r");
    while(fFile!=NULL){
        fclose(fFile);
        outPutStream.str("");       
        outputCounter++;
        this->outPutStream<<outputPath<<outputImageName<<outputCounter<<outputImageType<<endl;
        fFile=fopen(outPutStream.str().c_str(),"r");
    }
    if(drawing.cols!=0)
    {
        Mat outMat(25,25,drawing.type(),Scalar(0));
        drawing.copyTo(outMat.rowRange(0,drawing.rows).colRange(0,drawing.cols));
        imwrite(outPutStream.str(),outMat);
    }
        
    outPutStream.str("");
    outputCounter++;
    
}

//start get roi from input image
void FacialDetect::getROIObject(){
    int iMaxRange=1000;//some file missing so we try to find in max range before quit
    int iCheckFile=0;// reset to 0 when found file
    do{
        //check existing file
        //if file does not exist => raise waitting number 
        inputStream<<this->inputPath<<this->inputImageName<<this->inputCounter<<this->inputImageType;
        cout<<inputStream.str()<<endl;
        fFile = fopen(inputStream.str().c_str(),"r");
        if(fFile==NULL){
            cout<<CONFIG::FILE_DOES_NOT_EXIST<<endl;
            iCheckFile++;
        }
        else
        {
            if(iCheckFile!=0)
                iCheckFile = 0;
            //if file existing
            //get sourceImage
            sourceImage = imread(inputStream.str());
//            cout<<sourceImage.channels()<<endl;
            //test 
            thresh_callback(sourceImage);

        }     
        inputCounter++;
        inputStream.str("");
    }while(iCheckFile<iMaxRange);
           
}
//



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

void FacialDetect::setOutputPath(string outputPath) {
    this->outputPath = outputPath;
}

string FacialDetect::getOutputPath() const {
    return outputPath;
}

void FacialDetect::setInputPath(string inputPath) {
    this->inputPath = inputPath;
}

string FacialDetect::getInputPath() const {
    return inputPath;
}

void FacialDetect::setOutputImageType(string outputImageType) {
    this->outputImageType = outputImageType;
}

string FacialDetect::getOutputImageType() const {
    return outputImageType;
}

void FacialDetect::setInputImageType(string inputImageType) {
    this->inputImageType = inputImageType;
}

string FacialDetect::getInputImageType() const {
    return inputImageType;
}

void FacialDetect::setOutputImageName(string outputImageName) {
    this->outputImageName = outputImageName;
}

string FacialDetect::getOutputImageName() const {
    return outputImageName;
}

void FacialDetect::setInputImageName(string inputImageName) {
    this->inputImageName = inputImageName;
}

string FacialDetect::getInputImageName() const {
    return inputImageName;
}

void FacialDetect::setOutputCounter(int outputCounter) {
    this->outputCounter = outputCounter;
}

int FacialDetect::getOutputCounter() const {
    return outputCounter;
}

void FacialDetect::setInputCounter(int inputCounter) {
    this->inputCounter = inputCounter;
}

int FacialDetect::getInputCounter() const {
    return inputCounter;
}

