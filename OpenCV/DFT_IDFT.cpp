//
////
////  DFT_IDFT.cpp
////  testOpenCv
////
////  Created by 鲁蕴铖 on 16/4/20.
////  Copyright © 2016年 鲁蕴铖. All rights reserved.
////
//
//#include "DFT_IDFT.hpp"
//#include "AddNoise.hpp"
//#include <iostream>
//#include <cmath>
//#include <vector>
//#include <algorithm>
//#include <stdio.h>
//#include <stdlib.h>
//#include <string>
//#include <opencv2/opencv.hpp>
//#include <opencv2/core/core.hpp>
//#include <cv.h>
//#include <highgui.h>
//#include <opencv2/highgui/highgui.hpp>
//#include <opencv2/imgproc/imgproc.hpp>
//using namespace std;
//using namespace cv;
//int solve(const Mat &srcimage)
//{
//
//
//    Mat I = srcimage.clone();
//    if( I.empty())
//        return -1;
//
////    将输入图像扩展到最佳尺寸
//    Mat padded;                            //expand input image to optimal size
//    int m = getOptimalDFTSize( I.rows );
//    int n = getOptimalDFTSize( I.cols );
//    // on the border add zero values
//    copyMakeBorder(I, padded, 0, m - I.rows, 0, n - I.cols, BORDER_CONSTANT, Scalar::all(0));
//
////    planes 存傅立叶变换的结果 2维度，一个存实数域 一个存虚数域
////    频率域值超出空间域值的范围，因此至少要用float的格式来存储
//    Mat planes[] = {Mat_<float>(padded), Mat::zeros(padded.size(), CV_32F)};
//    Mat complexI;
//
////    merge 用多个单通道合成一个多通道 这里用planes 合成一个2通道的Mat
//// makes multi-channel array out of several single-channel arrays
////    CV_EXPORTS void merge(const Mat* mv, size_t count, OutputArray dst);
//    merge(planes, 2, complexI);         // Add to the expanded another plane with zeros
//
////    进行傅立叶变换，支持原图像原地计算
//    dft(complexI, complexI);            // this way the result may fit in the source matrix
////    fft(complexI, complexI);
//
////  lyc 逆变换
//    Mat inverse = I.clone();
//    idft(complexI, inverse,DFT_REAL_OUTPUT);
//    normalize(inverse, inverse,0,1,CV_MINMAX);
//    imshow("inverse", inverse);
//
//
////  需要将复数转化为幅度 （分离实数部分和虚数部分）
////! computes magnitude (magnitude(i)) of each (x(i), y(i)) vector
////  magnitude:  算幅值 sqrt ( x[i]^2 + y[i]^2 ) 结果保存到 out数组里面
////    CV_EXPORTS_W void magnitude(InputArray x, InputArray y, OutputArray magnitude);
//
//    // compute the magnitude and switch to logarithmic scale
//    // => log(1 + sqrt(Re(DFT(I))^2 + Im(DFT(I))^2))
//    split(complexI, planes);                   // planes[0] = Re(DFT(I), planes[1] = Im(DFT(I))
//    magnitude(planes[0], planes[1], planes[0]);// planes[0] = magnitude
//    Mat magI = planes[0];
//
////    对数尺度化缩放 由于幅度范围大到不适合在屏幕上显示，高值在屏幕上显示为白点，低值为黑点
////    用对数尺度替换线性尺度
//    magI += Scalar::all(1);                    // switch to logarithmic scale
//    log(magI, magI);
//
////    剪切和重分布幅度图像象限 一般是1/4子图像
//    // crop the spectrum, if it has an odd number of rows or columns
//
//
////    for(int i= 1;i<=10;i++){
//////        向下取偶数
////        cout<<"i:"<<i<<" &-2:"<<(i&-2)<<endl;
////    }
//    magI = magI(Rect(0, 0, magI.cols & -2, magI.rows & -2));
//
//    // rearrange the quadrants of Fourier image  so that the origin is at the image center
//    int cx = magI.cols/2;
//    int cy = magI.rows/2;
////    x y width height
//    Mat q0(magI, Rect(0, 0, cx, cy));   // Top-Left - Create a ROI per quadrant
//    Mat q1(magI, Rect(cx, 0, cx, cy));  // Top-Right
//    Mat q2(magI, Rect(0, cy, cx, cy));  // Bottom-Left
//    Mat q3(magI, Rect(cx, cy, cx, cy)); // Bottom-Right
//
//    Mat tmp;                           // swap quadrants (Top-Left with Bottom-Right)
//    q0.copyTo(tmp);
//    q3.copyTo(q0);
//    tmp.copyTo(q3);
//
//    q1.copyTo(tmp);                    // swap quadrant (Top-Right with Bottom-Left)
//    q2.copyTo(q1);
//    tmp.copyTo(q2);
//
//
////    归一化操作
//    normalize(magI, magI, 0, 1, CV_MINMAX); // Transform the matrix with float values into a
//    // viewable image form (float between values 0 and 1).
//
//    imshow("Input Image"       , I   );    // Show the result
//    imshow("spectrum magnitude", magI);
//
////
////    Mat mag1 = magI.clone();
////    int height = mag1.rows;
////    int width  = mag1.cols;
////    cout<<"height:"<<height<<" width:"<<width<<endl;
////    int d0 = 100;
////    for(int i = 0; i<height; i++)
////        for(int j=0; j<width; j++) {
////            int dis = sqrt( pow(i-height/2.0,2.0)+pow(j-width/2.0,2.0)  );
//////            cout<<dis<<endl;
////            if(dis>d0) {
////                mag1.at<float>(i,j) = 0;
////            }
////        }
////    imshow("low_filter", mag1);
////
////    Mat inverse1 = mag1.clone();
////    idft(mag1, inverse1,DFT_REAL_OUTPUT);
////    normalize(inverse1, inverse1,0,1,CV_MINMAX);
////    imshow("inverse1", inverse1);
////
//    waitKey();
//
//    return 0;
//}
//int main()
//{
//    Mat image = imread("/Users/luyuncheng/Documents/图像/Homework/Hw5/box_in_scene.png",CV_LOAD_IMAGE_GRAYSCALE);
//    solve(image);
//}