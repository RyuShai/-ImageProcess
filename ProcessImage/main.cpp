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
#include <stdio.h>
#include <opencv2/opencv.hpp>
#include "FacialDetect.h"
using namespace cv;
using namespace std;


/*
 * 
 */

RNG rng(12345);
Mat sourceGray;
int threHold = 0;
string outputPath = "/home/ryu/Documents/testData/inputpath/45eyeCanny";
string type =".jpg";
stringstream outPutStream;
FILE *fFile;
void thresh_callback(int, void*) {
    cout<<"thresh_callback"<<endl;
    Mat canny_output;
    vector<vector<Point> > contours;
    vector<Vec4i> hierarchy;
    int iNumber=0;
    /// Detect edges using canny
    Canny(sourceGray, canny_output, 45, 45*2, 3);
    /// Find contours
    findContours(canny_output, contours, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE, Point(0, 0));

    /// Draw contours
    Mat drawing = Mat::zeros(canny_output.size(), CV_8UC3);
    for (int i = 0; i < contours.size(); i++) {
        Scalar color = Scalar(0, 0, 255);
        drawContours(drawing, contours, i, color, 1, 8, hierarchy, 0, Point());
    }
    outPutStream<<outputPath<<iNumber<<type;
    cout<<outPutStream.str()<<endl;
    fFile = fopen(outPutStream.str().c_str(),"r");
    while(fFile!=NULL){
        fclose(fFile);
        outPutStream.str("");       
        iNumber++;
        outPutStream<<outputPath<<iNumber<<type;
        fFile=fopen(outPutStream.str().c_str(),"r");
    }
    imwrite(outPutStream.str(),drawing);
    outPutStream.str("");
    iNumber++;
    
    /// Show in a window
//    namedWindow("Contours", 128);
//    imshow("Contours", drawing);
    
}

int main(int argc, char** argv) {
    Mat src, dst, hsv;

    FacialDetect detect;
    detect.SetUriLeftEyes("/usr/local/share/OpenCV/haarcascades/haarcascade_lefteye_2splits.xml");
    //     src = imread("/home/ryu/Documents/testData/cropVTT1/image98.png");
    int iNum = 0;
    string inputPath = "/home/ryu/Documents/testData/inputpath/image";
    stringstream inputUri;
    int iOutLoop = 0;

    do {
        inputUri.str("");
        inputUri << inputPath << iNum << type;
        iNum++;
        cout<<inputUri.str()<<endl;
        fFile = fopen(inputUri.str().c_str(), "r");
        if (fFile != NULL) {
            fclose(fFile);
            src = imread(inputUri.str());
//            cvtColor(src,src,CV_RGB2GRAY);
            dst = detect.detectLeftEye(src);
            cout << "dst size: " << dst.cols<<" "<<dst.rows << endl;
            if ((dst.cols < 1) || (dst.rows < 1)) {
                cout << "no eyes " << endl;

            } else {
                
                cvtColor(dst, sourceGray, CV_RGB2GRAY);

                blur(sourceGray, sourceGray, Size(3, 3));
                char* windowName = "source";
//                namedWindow(windowName, 128);
//                imshow(windowName, dst);

                createTrackbar("bar:", windowName, &threHold, 100, thresh_callback);

                thresh_callback(0, 0);
            }

        } else {
            iOutLoop++;
            cout<<"ioutLoop"<<iOutLoop<<endl;
        }

    } while (iOutLoop < 103);

    waitKey();
    return 0;
}

