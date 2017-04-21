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
    detect.setInputPath("//home/lordofknight93/Documents/Image_Origin/Image/cropVTT1/Man/Men4/");
    detect.setOutputPath("/home/lordofknight93/Documents/Image_Origin/Image/cropVTT1/Man/Men4/Eyes");
    
    
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
        //namedWindow("hehe",128);
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
        int last= 0;
        for (int i=0 ;i<sourceInput.rows;)
        {  

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
                     
            if(remind.x !=0 && remind.y!=0 && matchOne == true)
            {
                toaDo.push_back(TOADO(remind));
            
            }
            matchOne=false;
            
            i++;
        }
        cout<<"\n"<<endl;
        Mat image = Mat::zeros( 25, 25, CV_8UC3 );
        for(int i=0;i< toaDo.size();i+=1)
        {   
            if(i ==0)
            {
                    cout<<toaDo.at(i).x<<":"<<toaDo.at(i).y<<"-"<<toaDo.at(i+1).x<<":"<<toaDo.at(i+1).y<<endl;
                    cout<<toaDo.at(i).x<<":"<<toaDo.at(i).y<<"-"<<toaDo.at(i+2).x<<":"<<toaDo.at(i+2).y<<endl;
                    line( image, Point( toaDo.at(i).y, toaDo.at(i).x ), Point( toaDo.at(i+1).y,toaDo.at(i+1).x), Scalar( 110, 220, 0 ),1, CV_AA );
                    line( image, Point( toaDo.at(i).y, toaDo.at(i).x ), Point( toaDo.at(i+2).y,toaDo.at(i+2).x), Scalar( 110, 220, 0 ),1, CV_AA );
            }else if(i >= toaDo.size()-2)
            {
                cout<<toaDo.at(toaDo.size()-1).x<<":"<<toaDo.at(toaDo.size()-1).y<<"-"<<toaDo.at(toaDo.size()-2).x<<":"<<toaDo.at(toaDo.size()-2).y<<endl;
                line( image, Point( toaDo.at(toaDo.size()-1).y, toaDo.at(toaDo.size()-1).x ), Point( toaDo.at(toaDo.size()-2).y,toaDo.at(toaDo.size()-2).x), Scalar( 110, 220, 0 ),1, CV_AA );
            }
            else
            if(i%2 == 0 && i < toaDo.size()-2)
            {
                line( image, Point( toaDo.at(i).y, toaDo.at(i).x ), Point( toaDo.at(i+2).y,toaDo.at(i+2).x), Scalar( 110, 220, 0 ),1, CV_AA );
                cout<<toaDo.at(i).x<<":"<<toaDo.at(i).y<<"-"<<toaDo.at(i+2).x<<":"<<toaDo.at(i+2).y<<endl;
            } else if (i%2 != 0 && i < toaDo.size() - 2)
            {
                line( image, Point( toaDo.at(i).y, toaDo.at(i).x ), Point( toaDo.at(i+2).y,toaDo.at(i+2).x), Scalar( 110, 220, 0 ),1, CV_AA );
                cout<<toaDo.at(i).x<<":"<<toaDo.at(i).y<<"-"<<toaDo.at(i+2).x<<":"<<toaDo.at(i+2).y<<endl;
            }
            
        }
        imshow("hehe",image);
    }
    
    
    waitKey();
    return 0;
}

