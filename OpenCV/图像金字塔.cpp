////
////  图像金字塔.cpp
////  testOpenCv
////
////  Created by 鲁蕴铖 on 15/6/22.
////  Copyright (c) 2015年 鲁蕴铖. All rights reserved.
////
///*
//#include <opencv2/opencv.hpp>
//#include <vector>
//#include <opencv2/imgproc/imgproc.hpp>
//using namespace std;
//using namespace cv;
//int main( )
//{
//    //【1】载入原始图和Mat变量定义
//    Mat srcImage = imread("/Users/luyuncheng/Pictures/com.tencent.ScreenCapture/test12.jpg");
//    Mat midImage,dstImage,dstImage2;//临时变量和目标图的定义
//
//    //【2】进行边缘检测和转化为灰度图
//    Canny(srcImage, midImage, 50, 200, 3);//进行一此canny边缘检测
//    cvtColor(midImage,dstImage, CV_GRAY2BGR);//转化边缘检测后的图为灰度图
//
//    //【3】进行霍夫线变换
//    vector<Vec2f> lines;//定义一个矢量结构lines用于存放得到的线段矢量集合
//    HoughLines(midImage, lines, 1, CV_PI/180, 200, 0, 0 );
//
//    //【4】依次在图中绘制出每条线段
//    for( size_t i = 0; i < lines.size(); i++ )
//    {
//        float rho = lines[i][0], theta = lines[i][1];
//        Point pt1, pt2;
//        double a = cos(theta), b = sin(theta);
//        double x0 = a*rho, y0 = b*rho;
//        pt1.x = cvRound(x0 + 1000*(-b));
//        pt1.y = cvRound(y0 + 1000*(a));
//        pt2.x = cvRound(x0 - 1000*(-b));
//        pt2.y = cvRound(y0 - 1000*(a));
//        line( dstImage, pt1, pt2, Scalar(55,100,195), 1, CV_AA);
//    }
//
//    //【5】显示原始图
//    imshow("original", srcImage);
//
//    //【6】边缘检测后的图
//    imshow("canny", midImage);
//
//    //【7】显示效果图
//    imshow("show", dstImage);
//
//
//    cvtColor(midImage, dstImage2, CV_GRAY2BGR);
//    //【3】进行霍夫线变换
//    vector<Vec4i> lines2;//定义一个矢量结构lines用于存放得到的线段矢量集合
//    HoughLinesP(midImage, lines2, 1, CV_PI/180, 80, 50, 10 );
//
//    //【4】依次在图中绘制出每条线段
//    for( size_t i = 0; i < lines2.size(); i++ )
//    {
//        Vec4i l = lines2[i];
//        line( dstImage2, Point(l[0], l[1]), Point(l[2], l[3]), Scalar(186,88,255), 1, CV_AA);
//    }
//
//    //【7】显示效果图
//    imshow("show2", dstImage2);
//    waitKey(0);
//
//    return 0;
//}*/