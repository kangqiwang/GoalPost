#ifndef GOALPOSTDETECTOR_H					// avoid repeated expansion
#define GOALPOSTDETECTOR_H


#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
#include <fstream>
#include <vector>
#include "cmaes.h"


using namespace cv;
using namespace std;


#define EPS 0.01

#define lowThreshold  45
#define ratio  3
#define kernelSize  3
#define scale 100.0f
#define penalization 10.0f
#define windowSearchSize squareSize*1.0

typedef Point_<float> Point2f;

class LineDetectAlgorithm {

public:
    LineDetectAlgorithm(Mat InputImg, vector<Point2f> ApproxGoalPos, int NumOfInnerSquares = 1, int  LineStep = 10, float SquareSize = 30.0f) :
        lineStep(LineStep), numOfInnerSquares(NumOfInnerSquares), squareSize(SquareSize)
    {
        approxGoalPos = ApproxGoalPos;
        originalImg = InputImg;

    }

    virtual ~LineDetectAlgorithm() {};

    Point2f findTheShift();

private:
    int lineStep, numOfInnerSquares;
    float squareSize;

    Mat img, originalImg;
    Mat paddedImg;
    vector<Point2f> approxGoalPos;
    vector<Point2f> samplePointsAlongThePost;

    void createPaddedImg();

    void getPointsAlongTheLine(int iteration);

    void getPointsAlongTheGoalBar();

    double objectiveFunction(float const *x);

    void CannyThreshold();


};

#endif /* GOALPOSTDETECTOR_H */
