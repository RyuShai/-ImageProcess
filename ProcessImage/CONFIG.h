/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   CONFIG.h
 * Author: ryu
 *
 * Created on April 18, 2017, 2:39 PM
 */

#ifndef CONFIG_H
#define CONFIG_H
#include <string>
using namespace std;
namespace CONFIG{
    //error
    static string FILE_DOES_NOT_EXIST = "File does not exist";
    static string FILE_EXIST = "File existing";
    static string FAIL_LOAD_LEFT_EYE_CLASSIFIER = "cant load left eyes classifier";
    static string FAIL_LOAD_R_EYE_CLASSIFIER = "cant load right eyes classifier";
    static string FAIL_LOAD_LEFT_MOUTH_CLASSIFIER = "cant load mouth classifier";
    static string FAIL_LOAD_NOSE_CLASSIFIER = "cant load nose classifier";
    //
    
    static string NUMBER_LEFT_EYE_DETECTED = "number left eye detect: ";
    static string NUMBER_RIGHT_EYE_DETECTED = "number right eye detect: ";
    static string NUMBER_MOUTH_DETECTED = "number mouth detect: ";
    static string NUMBER_NOSE_DETECTED = "number nose detect: ";
    //value
    static int DETECT_MULTISCALE_SCALEFACTOR = 1.1;
    static int DETECT_MULTISCALE_MINNEIGHBORS = 3;
    static int DETECT_MULTISCALE_FLAG = 0;
    static int SIZE_IMAGE_MIN_H = 16;
    static int SIZE_IMAGE_MIN_W = 16;
    
    static int SIZE_IMAGE_DETECTED_H = 16;
    static int SIZE_IMAGE_DETECTED_W = 16;
    
    static int CANNY_THRESHOLD_1 = 45;
    static int CANNY_APERTURESIZE = 3;
    
    static string NOSE_FOLDER = "nose/";
}


#endif /* CONFIG_H */

