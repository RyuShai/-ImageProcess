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

Mat Utilities::simpleColor(Mat& inputMat, int meanTimes, Vec3b smallColor, Vec3b bigColor) {
    int imean = 0;
    int threshold = 0;
    int totalPixel = 0;
    int meanValue = 255;
    //get limitColor 
    while (imean < meanTimes) {
        totalPixel = 0;
        threshold = 0;
        for (int i = 0; i < inputMat.rows; i++) {
            for (int j = 0; j < inputMat.cols; j++) {
                if ((int) inputMat.at<Vec3b>(i, j)[0] < meanValue) {
                    threshold += (int) inputMat.at<Vec3b>(i, j)[0];
                    totalPixel++;
                }

            }
        }
        imean++;
        meanValue = threshold / totalPixel;
    }
    cout << "Mean value: " << meanValue << endl;
    for (int i = 0; i < inputMat.rows; i++) {
        for (int j = 0; j < inputMat.cols; j++) {
            if ((int) inputMat.at<Vec3b>(i, j)[0] <= meanValue)
                inputMat.at<Vec3b>(i, j) = smallColor;
            else
                inputMat.at<Vec3b>(i, j) = bigColor;
        }
    }
    return inputMat;
}

vector< vector<Point> > Utilities::listArrayColor(Mat& inputMat, Vec3b color) {
    vector< vector<Point> > listArray;
    Point coordinate;
    for (int i = 0; i < inputMat.rows; i++) {
        for (int j = 0; j < inputMat.cols; j++) {
            if (inputMat.at<Vec3b>(i, j) == color) {
                vector<Point> add;
                add = popPixel(inputMat, i, j);
                listArray.push_back(add);
            }
        }
    }
    vector<Point> topList, bottomList;
    for(int i=0; i<listArray.size();i++)
    {
        if(listArray.at(i).size()>topList.size() || listArray.at(i).size()>bottomList.size())
        {
            if(topList.size()>=bottomList.size())
            {
                bottomList = listArray.at(i);
            }
            else
            {
                topList = listArray.at(i);
            }
        }
    }
    listArray.clear();
    if(topList.size()>0)
        listArray.push_back(topList);
    if(bottomList.size()>0)
        listArray.push_back(bottomList);
    return listArray;
}

vector<Point> Utilities::popPixel(Mat &inputMat, int row, int col) {
    vector<Point> addList;
    vector<Point> returnList;
    Vec3b currentColor = inputMat.at<Vec3b>(row, col);
    bool added = false;
    bool changedColor = false;
    Point addPoint;
    addPoint.x = row;
    addPoint.y =col;
    addList.push_back(addPoint);
    while (addList.size() > 0) { 
        Point locate = addList.back();
        row = locate.x;
        col = locate.y; 
        returnList.push_back(addList.back());
        addList.pop_back();
        //x-1:y
        if (col - 1 >= 0 &&
                currentColor == inputMat.at<Vec3b>(row, col - 1)) {
            addList.push_back(Point(row, col - 1));
        }
        //x+1:y
        if (col + 1 < inputMat.cols &&
                currentColor == inputMat.at<Vec3b>(row, col + 1)) {
            addList.push_back(Point(row, col + 1));
        }
//        //x:y-1
        if (row - 1 >= 0 &&
                currentColor == inputMat.at<Vec3b>(row - 1, col)) {
            addList.push_back(Point(row - 1, col));
        }
        //x:y-1
        if (row + 1 < inputMat.rows &&
                currentColor == inputMat.at<Vec3b>(row + 1, col)) {
            addList.push_back(Point(row + 1, col));
        }
//        x-1:y-1
        if (row -1 >= 0 && col-1 >=0 &&
                currentColor == inputMat.at<Vec3b>(row-1, col-1)) {
            addList.push_back(Point(row-1, col-1));
        }
        //x+1, y-1
        if (row - 1 >= 0 && col+1<=inputMat.cols &&
                currentColor == inputMat.at<Vec3b>(row - 1, col+1)) {
            addList.push_back(Point(row- 1, col+1));
        }
        //x-1:y+1
        if (row + 1 <= inputMat.rows && col-1>=0 &&
                currentColor == inputMat.at<Vec3b>(row + 1, col-1)) {
            addList.push_back(Point(row + 1, col-1));
        }
        if (row + 1 <= inputMat.rows && col+1 <=inputMat.cols &&
                currentColor == inputMat.at<Vec3b>(row + 1, col+1)) {
            addList.push_back(Point(row + 1, col+1));
        }
        inputMat.at<Vec3b>(row, col) = Vec3b::all(255);
    }
    return returnList;
}

void Utilities::drawMatImage(Mat& inputMat, vector<Point> listPixel, Vec3b color)
{
    while(listPixel.size()>0)
    {
        inputMat.at<Vec3b>(listPixel.front().x, listPixel.front().y) = color;
        listPixel.erase(listPixel.begin());
    }
}
struct TOADO
{
    int x = 0 ; 
    int y = 0 ;
};
Mat Utilities::drawLine(Mat& inputMat, int x,int y) {
        
     vector<TOADO> toaDo;
        TOADO remind;
        
        bool matchOne=false;
        Vec3b smallColor = Vec3b::all(0);
        for (int i=0 ;i<inputMat.rows;)
        {  

            for(int j=0;j<inputMat.cols;j++)
            { 
                Vec3b current = inputMat.at<Vec3b>(Point(j,i));
                if((int)current[1]<68)
                {
                    if(current == smallColor)
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
                matchOne = false;
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
        
}