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

