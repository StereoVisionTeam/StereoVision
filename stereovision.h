#ifndef STEREOVISION_H
#define STEREOVISION_H

#include "opencv2/calib3d/calib3d.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <QDebug>
using namespace cv;

class StereoVision
{

public:
    StereoVision();
    bool addSampleToCalibration(Mat &leftImage, Mat &rightImage);
    bool calibrateStereoCameras();

    void setPatternSize(Size x){ patternSize =x;}
    void setPatternSize(int x, int y){ patternSize = Size(x,y);}
    void setImageSize(Size x) { imageSize= x;}

    vector<vector<Point2f> > imagePoints[2];
    vector<vector<Point3f> > objectPoints;
private:

    //Calibration Begin

    int samplesCounter;
    int goodSamplesCounter;
    int minSamples;
    float squareSize; //size of calibration pattern

    Size patternSize; //Number of inner corners per a chessboard row and column for (8x8) board it's (7x7)
    Size imageSize;
    Mat cameraMatrix[2], distCoeffs[2];
    Mat R, T, E, F;

};

#endif // STEREOVISION_H
