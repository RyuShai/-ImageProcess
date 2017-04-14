/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ConsolutionMatrix.h
 * Author: ryu
 *
 * Created on April 13, 2017, 9:33 AM
 */

#ifndef CONSOLUTIONMATRIX_H
#define CONSOLUTIONMATRIX_H
#include <stdio.h>
#include <iostream>
#include <cv.h>
using namespace cv;
class ConsolutionMatrix {
public:
    ConsolutionMatrix();
    ConsolutionMatrix(const ConsolutionMatrix& orig);
    virtual ~ConsolutionMatrix();
    void setSourceMatrixSize(int col, int row);
    void setKernelMatrixSize(int col, int row);
private:
    Mat sourceMatrix;
    Mat kernelMatrix;
};

#endif /* CONSOLUTIONMATRIX_H */

