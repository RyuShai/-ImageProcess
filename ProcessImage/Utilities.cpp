/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Utilities.cpp
 * Author: ryu
 * 
 * Created on April 22, 2017, 10:40 AM
 */

#include "Utilities.h"

Utilities::Utilities() {
}

Utilities::Utilities(const Utilities& orig) {
}

Utilities::~Utilities() {
}

Mat Utilities::simpleColor(Mat& inputMat, int meanTimes, Vec3b smallColor, Vec3b bigColor)
{
    int imean = 0;
    int threshold = 0;
    int totalPixel=0;
    int meanValue=255;
    //get limitColor 
    while(imean<meanTimes)
    {
        totalPixel=0;
        threshold=0;
        for(int i=0;i<inputMat.rows;i++)
        {
            for(int j=0; j<inputMat.cols;j++)
            {
                if((int)inputMat.at<Vec3b>(i,j)[0]<meanValue)
                {
                    threshold += (int) inputMat.at<Vec3b>(i, j)[0];
                    totalPixel++;
                }
                
            }
        }
        imean++;
        meanValue = threshold/totalPixel;
    }
    cout<<"Mean value: "<<meanValue<<endl;    
    for(int i=0;i<inputMat.rows;i++)
    {
        for(int j=0; j<inputMat.cols;j++)
        {
            if((int)inputMat.at<Vec3b>(i,j)[0]<=meanValue)
                inputMat.at<Vec3b>(i,j) = smallColor;
            else
                inputMat.at<Vec3b>(i,j) = bigColor;
        }
    }
    return inputMat;
}

vector< vector<Point> > Utilities::listArrayColor(Mat& inputMat, Vec3b color)
{
    vector<Point> add;
    vector< vector<Point> > listArray;
    Point coordinate;
    for(int i=0;i< inputMat.rows;i++)
    {
        for(int j=0;j<inputMat.cols;j++)
        {
            if(inputMat.at<Vec3b>(i,j) == color)
            {
                popPixel(inputMat,i,j,add);
                listArray.push_back(add);
            }
        }
    }
}

void Utilities::popPixel(Mat &inputMat,int x, int y, vector<Point> &add)
{
    Vec3b currentColor = inputMat.at<Vec3b>(x,y);
    if(y-1>=0 &&
            currentColor==inputMat.at<Vec3b>(x,y-1))
    {
//        add.push_back(Point(x,y));
        if(inputMat.at<Vec3b>(x,y)!=Vec3b::all(255));
            inputMat.at<Vec3b>(x,y)=Vec3b::all(255);
        popPixel(inputMat,x,y-1,add);
    }
    
//    if(y+1>=inputMat.rows &&
//            currentColor==inputMat.at<Vec3b>(x,y+1))
//    {
//        add.push_back(Point(x,y));
//        if(inputMat.at<Vec3b>(x,y)!=Vec3b::all(255));
//            inputMat.at<Vec3b>(x,y)=Vec3b::all(255);
//        popPixel(inputMat,x,y+1);
//    }
//    
//    if(x-1>=0 &&
//            currentColor==inputMat.at<Vec3b>(x-1,y))
//    {
//        add.push_back(Point(x,y));
//        if(inputMat.at<Vec3b>(x,y)!=Vec3b::all(255));
//            inputMat.at<Vec3b>(x,y)=Vec3b::all(255);
//        popPixel(inputMat,x-1,y);
//    }
//    
//    if(y+1 >=inputMat.cols &&
//            currentColor==inputMat.at<Vec3b>(x+1,y))
//    {
//        add.push_back(Point(x,y));
//        if(inputMat.at<Vec3b>(x,y)!=Vec3b::all(255));
//            inputMat.at<Vec3b>(x,y)=Vec3b::all(255);
//        popPixel(inputMat,x+1,y);
//    }
//    cout<<"add size "<< add.size()<<endl;
}