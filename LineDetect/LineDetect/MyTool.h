#pragma once
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
#include <fstream>
#include <vector>

using namespace cv;
using namespace std;

class CMyTool
{
public:
    CMyTool();
    ~CMyTool();

    //read positions from txt file
    static vector<Point2f> readPositionsFromTxt(string filename);
    //write positions to txt file
    static void writePositionsToTxt(string filename, const vector<Point2f> &goalPos);
    //draw line of goal
    static void drawGoalLine(Mat img, vector<Point2f> goalPos, Scalar color);
};

