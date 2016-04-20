
////
////  高提升滤波.cpp
////  testOpenCv
////
////  Created by 鲁蕴铖 on 16/4/11.
////  Copyright © 2016年 鲁蕴铖. All rights reserved.
////
//
//#include "高提升滤波.hpp"
//
//#include <iostream>
//#include <vector>
//#include <opencv2/opencv.hpp>
//#include <opencv2/core/core.hpp>
//#include <cv.h>
//#include <highgui.h>
//#include <algorithm>
//#include <opencv2/highgui/highgui.hpp>
//using namespace std;
//using namespace cv;
//Mat image,guess;
//void solveinopencv()
//{
//    imshow("Region", image );
//    GaussianBlur(image, guess, Size( 5, 5 ), 1, 1);
//    imshow("Guess" ,guess );
////    imwrite("/Users/luyuncheng/Pictures/com.tencent.ScreenCapture/test2_opencv.png",out);
//}
//void Solve() {
//    solveinopencv();
//    vector<vector<uchar> > difference (image.rows,vector<uchar>(image.cols,0));
//    for(int i=0; i < image.rows; i++)
//        for(int j=0; j < image.cols; j++) {
//            int tmp1 = image.at<uchar>(i,j) ;
//            int tmp2 = guess.at<uchar>(i,j) ;
//            int tmp = tmp1 - tmp2;
//            if(tmp<0)tmp = 0;
//            difference[i][j] = tmp;
//        }
//    int k = 5;
//    Mat out;
//    out.create(image.rows, image.cols, image.type());
//    for(int i=0; i < image.rows; i++){
//        for(int j=0; j < image.cols; j++)
//        {
//            int tmp1 = image.at<uchar>(i,j);
//            int tmp2 = difference[i][j];
//            int tmp = tmp1 + tmp2*k;
//            if(tmp>=255) tmp = 255;
//            if(tmp<0) tmp = 0;
//            out.at<uchar>(i,j)=tmp;
//        }
//    }
//
//    imshow("CV_image", out );
//
//}
//int main()
//{
//    image=imread("/Users/luyuncheng/Documents/图像/Homework/Hw3/box_in_scene.png",CV_8U);
//    Solve();
//    waitKey();
//}