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
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
using namespace cv;
using namespace std;


/*
 * 
 */
struct TOADO{
    int x=0;
    int y=0;
};
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
    detect.setInputPath("/home/ryu/Documents/testData/Men4/");
    detect.setOutputPath("/home/ryu/Documents/testData/Men4/Eyes/");
    
    
    detect.setInputImageName("grayimage");
    detect.setOutputImageName("lefteye");
    
    
    detect.setInputImageType(".png");
    detect.setOutputImageType(".png");
    detect.setInputCounter(1);
    detect.setOutputCounter(0);
    
    stringstream sstream;
    sstream<<detect.getInputPath()<<detect.getInputImageName()<<detect.getInputCounter()<<detect.getInputImageType();
    cout<<"input stream: "<<sstream.str()<<endl;
    Mat sourceInput = detect.detectRightEye(imread(sstream.str()));
    if(sourceInput.cols ==0 || sourceInput.rows==0)
    {
        cout<<"not found eyes"<<endl;
        return 0;
    }
    else
    {
        namedWindow("hihi",128);
         imshow("hihi",sourceInput);
         cout<<"row"<<sourceInput.rows<<"-"<<sourceInput.cols<<endl;
        Vec3b fillBlack = Vec3b::all(0);
        Vec3b fillwhite = Vec3b::all(255);
//        for (int i=0;i<sourceInput.rows;i++)
//        {
//            for(int j=0;j<sourceInput.cols;j++)
//            {
//                Vec3b current = sourceInput.at<Vec3b>(Point(j,i));
//                if((int)current[0]<10)
//                    cout<<"0"<<(int)current[1]<<" ";
//                else cout<<(int)current[0]<<" ";
//                
////                if((int)current[1]>110)
////                    sourceInput.at<Vec3b>(j,i)=fillBlack;
////                else if((int)current[1]<50)
////                    sourceInput.at<Vec3b>(j,i)=fillwhite;
////                else
////                    sourceInput.at<Vec3b>(j,i)=Vec3b(0,255,255);
//                
//            }
//            cout<<"\n";
//        }
        cout<<"\n";
        for (int i=0;i<sourceInput.rows;i++)
        {
            for(int j=0;j<sourceInput.cols;j++)
            {
                Vec3b current = sourceInput.at<Vec3b>(Point(j,i));
                if((int)current[1]<68)
                    cout<<"0"<<" ";
//                else if (69<(int)current[1] and (int)current[1]<126)
//                    cout<<"2"<<" ";
//                else if(126<(int)current[1] and 200>(int)current[1])
//                    cout<<"8"<<(int)current[1]<<" ";
                else
                    cout<<"1"<<" ";
//                if((int)current[1]>110)
//                    sourceInput.at<Vec3b>(j,i)=fillBlack;
//                else if((int)current[1]<50)
//                    sourceInput.at<Vec3b>(j,i)=fillwhite;
//                else
//                    sourceInput.at<Vec3b>(j,i)=Vec3b(0,255,255);
                
            }
            cout<<"\n";
        }
        vector<TOADO> toaDo;
        TOADO remind;
        int iCurrent=0;
        bool matchOne=false;
        for (int i=5;i<sourceInput.rows;i++)
        {
            iCurrent=i;
            for(int j=0;j<sourceInput.cols;j++)
            { 
                Vec3b current = sourceInput.at<Vec3b>(Point(j,i));
                if((int)current[1]<68)
                {
                    if(!matchOne)
                    {
                        //add first point in line
                        remind.x=i;
                        remind.y=j;
                        cout<<"add: "<<i<<"-"<<j<<endl;
                        toaDo.push_back(TOADO(remind));
                        matchOne=true;
                    }
                    else{
                        remind.x=i;
                        remind.y=j;                        
                    }
                }
            }
            if(remind.x !=0 && remind.y!=0)
                toaDo.push_back(TOADO(remind));
            matchOne=false;
        }
        cout<<"\n"<<endl;
        for(int i=0;i< toaDo.size();i+=2)
        {
            line( image, Point( toaDo.at(i).x, toaDo.at(i).y ), Point( 7, 13), Scalar( 110, 220, 0 ),1, CV_AA );
            cout<<toaDo.at(i).x<<":"<<toaDo.at(i).y<<"-"<<toaDo.at(i+1).x<<":"<<toaDo.at(i+1).y<<endl;
        }
//        imwrite("/home/ryu/Documents/testData/Men6/Eyes/yey.jpg",sourceInput);
//        imshow("hehe",sourceInput);
    }
    
//    Mat src( 50,  70, CV_8UC1 , Scalar(1)); // 5x7
//    Mat dst(100, 100, CV_8UC1, Scalar(255)); // 10x10
//
//src.copyTo(dst.rowRange(0,50),dst.colRange(0,src.cols));
//namedWindow("1",100);
//imshow("1",dst);
    
//    waitKey();
    return 0;
}

