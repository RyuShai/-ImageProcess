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
#include "Utilities.h"
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
    detect.setInputPath("/home/lordofknight93/Documents/Image_Origin/Image/cropVTT1/Man/Men6/");
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
         namedWindow("origin",128);
         imshow("origin",sourceInput);
         cout<<"row"<<sourceInput.rows<<"-"<<sourceInput.cols<<endl;
         Vec3b smallColor = Vec3b::all(0);
         Vec3b bigColor = Vec3b::all(255);
         vector< vector<Point> > list;
         Utilities util;
         
         sourceInput = util.simpleColor(sourceInput,2,smallColor,bigColor);
         
         namedWindow("simple color",128);
         imshow("simple color",sourceInput);
         
         
         cout<<"chet nhu tu hai"<<endl;
         list =util.listArrayColor(sourceInput, smallColor);
         cout<<"list size: "<<list.size()<<endl; 
         for(int i=0; i<list.size();i++)
         {
             Mat apart(sourceInput.rows,sourceInput.cols,sourceInput.type());
             apart = Scalar(255,255,255);
            util.drawMatImage(apart,list.at(i),Vec3b::all(0));
             string title = "apart"+i;
             namedWindow(title,128);
             imshow(title, apart);
             cout<<"list "<<list.size()<<endl;
             Mat drawLine = util.drawLine(apart,0,0);
             string drawline = "draw" + i;
             namedWindow(drawline,128);
             imshow(drawline,drawLine);
             
             
            
         }         
         waitKey();
    }   
    return 0;
}

