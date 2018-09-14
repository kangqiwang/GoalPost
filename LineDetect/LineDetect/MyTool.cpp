#include "stdafx.h"
#include "MyTool.h"


CMyTool::CMyTool()
{
}


CMyTool::~CMyTool()
{
}


vector<Point2f> CMyTool::readPositionsFromTxt(string filename)
{
    ifstream inputFile;
    vector<Point2f> goalPos;
    inputFile.open(filename.c_str(), ios_base::in);
    float x, y;
    while (!inputFile.eof())
    {
        inputFile >> x;
        inputFile >> y;

        goalPos.push_back(Point(x, y));
    }

    inputFile.close();
    return goalPos;
}

void CMyTool::writePositionsToTxt(string filename, const vector<Point2f> &goalPos)
{
    ofstream outputFile;

    outputFile.open(filename.c_str(), ios_base::out);

    for (int i = 0; i < goalPos.size(); i++)
    {

        outputFile << goalPos.at(i).x << " ";
        outputFile << goalPos.at(i).y;
        outputFile << endl;
    }

    outputFile.close();

}

void CMyTool::drawGoalLine(Mat img, vector<Point2f> goalPos, Scalar color)
{
    for (int i = 0; i < goalPos.size() - 1; i++)
    {
        line(img, goalPos.at(i), goalPos.at(i + 1),
            color,
            4,
            8);
    }
}