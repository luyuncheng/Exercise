////
////  main.cpp
////  testOpenCv
////
////  Created by 鲁蕴铖 on 15/6/11.
////  Copyright (c) 2015年 鲁蕴铖. All rights reserved.
////
///*
//#include <iostream>
//#include <opencv2/opencv.hpp>
//#include <opencv2/core/core.hpp>
//#include <cv.h>
//#include <highgui.h>
//#include <opencv2/highgui/highgui.hpp>
//using namespace cv;
//using namespace std;
//
//void show(){
//    //图像载入和显示
//    //图像载入
//    Mat pic1 = imread("/Users/luyuncheng/Pictures/com.tencent.ScreenCapture/1.png");
//    Mat pic2 = imread("/Users/luyuncheng/Pictures/test.png");
//    if(!pic2.data){
//        printf("fuck\n");
//    }
//    //创建第一个窗口
//    namedWindow("window1");
//    //显示出来
//    imshow("window1", pic2);
//
//}
//void mix(){
//    //图像混合
//    //载入第二个图像
//    Mat pic2 = imread("/Users/luyuncheng/Pictures/com.tencent.ScreenCapture/123.png",199);
//    Mat pic3 = imread("/Users/luyuncheng/Pictures/com.tencent.ScreenCapture/456.jpg");
//    //创建窗口显示
//    //namedWindow("window2"); imshow("window2", pic2);
//    //namedWindow("window3"); imshow("window3", pic3);
//    //定义一个mat类型用语存放图像的roi
//    Mat imagROI;
//    //方法一：将图片这个部分矩形截取到roi中
//    imagROI=pic2(Rect(500,550,pic3.cols,pic3.rows));
//    //将roi图片加到原图上
//    addWeighted(imagROI, 0.5, pic3, 0.3, 0.1 , imagROI);
//    namedWindow("window4");
//    imshow("window4", pic2);
//
//    imwrite("hahaha.jpg", pic2);
//}
//void  roi(){
//    Mat src1= imread("/Users/luyuncheng/Downloads/opencvcnblogdemo/OpenCVdemo2/OpenCVdemo2/dota_pa.jpg");
//    Mat logo= imread("/Users/luyuncheng/Downloads/opencvcnblogdemo/OpenCVdemo2/OpenCVdemo2/dota_logo.jpg");
//    if(!src1.data|| !logo.data){
//        printf("fuck\n");
//        return  ;
//    }
//    Mat imageROI= src1(Rect(200,250,logo.cols,logo.rows));
//    namedWindow("windowrr");
//    logo.copyTo(imageROI);
//    imshow("windowrr", src1);
//    //加个掩膜,灰度图
//    Mat mask = imread("/Users/luyuncheng/Downloads/opencvcnblogdemo/OpenCVdemo2/OpenCVdemo2/dota_logo.jpg",0);
//    //logo复制到roi图像上 并加上掩码
//    logo.copyTo(imageROI,mask);
//    //显示
//    namedWindow("windowr");
//    imshow("windowr", src1);
//
//}
//void linerBlending(){
//    double alp=0.618;
//    double beta;
//    Mat dest,src2,src3;
//    //两幅图为同样的类型和尺寸在这里需要注意的是，因为我们是对 srcImage1和srcImage2求和，所以它们必须要有相同的尺寸（宽度和高度）和类型，不然多余的部分没有对应的“伴”，肯定会出问题。
//    src2=imread("/Users/luyuncheng/Downloads/opencvcnblogdemo/OpenCVdemo2/OpenCVdemo2/mogu.jpg");
//    src3=imread("/Users/luyuncheng/Downloads/opencvcnblogdemo/OpenCVdemo2/OpenCVdemo2/rain.jpg");
//    if(!src2.data|| !src3.data){
//        printf("fuck\n");
//        return  ;
//    }
//
//    beta=(1.0-alp);
//    //创造加权
//    addWeighted(src2, alp, src3, beta, 0.0, dest);
//    namedWindow("window");
//    imshow("window", dest);
//
//}
//void roi_linerblendig(){
//    Mat src1= imread("/Users/luyuncheng/Downloads/opencvcnblogdemo/OpenCVdemo2/OpenCVdemo2/dota_pa.jpg");
//    Mat logo= imread("/Users/luyuncheng/Downloads/opencvcnblogdemo/OpenCVdemo2/OpenCVdemo2/dota_logo.jpg");
//    if(!src1.data|| !logo.data){
//        printf("fuck\n");
//        return  ;
//    }
//    Mat roi=src1(Rect(200,250,logo.cols,logo.rows));
//    namedWindow("window");
//    namedWindow("window2");
////    将logo和roi区域加权
//    addWeighted(roi, 0.5, logo, 0.5, 0, roi);
//    //截取了那一小部分来show
//    imshow("window", roi);
//    //此时小图片已经由于roi加入到原图中了
//    imshow("window2", src1);
//
//}
//void splitimage(){
//    Mat src=imread("/Users/luyuncheng/Downloads/opencvcnblogdemo/OpenCVdemo3/OpenCVdemo3/dota_jugg.jpg");
//    Mat logo=imread("/Users/luyuncheng/Downloads/opencvcnblogdemo/OpenCVdemo3/OpenCVdemo3/dota_logo.jpg",0);
//    if(!src.data || !logo.data){
//        printf("fuck\n");
//        return;
//    }
//    vector<Mat> channels;
//    Mat imageBlueChannel;
//    Mat imageGreenChannel;
//    Mat imageRedChannel;
//    split(src, channels);
//
//    //【3】将原图的蓝色通道引用返回给imageBlueChannel，注意是引用，相当于两者等价，修改其中一个另一个跟着变
//    imageBlueChannel = channels.at(0);
//    imageGreenChannel = channels.at(1);
//    imageRedChannel = channels.at(2);
//    namedWindow("test1");
//    namedWindow("test2");
//    namedWindow("test3");
//    //imshow("test1",imageBlueChannel);
//    //imshow("test2",imageGreenChannel);
//    //imshow("test3",imageRedChannel);
//    //【4】将原图的蓝色通道的（500,250）坐标处右下方的一块区域和logo图进行加权操作，将得到的混合结果存到imageBlueChannel中,那么那一块区域的就只能是蓝色图像了。
//    addWeighted(imageBlueChannel(Rect(500,250,logo.cols,logo.rows)), 0.5, logo, 0.5, 0.0, imageBlueChannel(Rect(500,250,logo.cols,logo.rows)));
//    //【5】将三个单通道重新合并成一个三通道
//    merge(channels, src);
//    namedWindow("window");
//    imshow("window", imageBlueChannel);
//    //同理可得绿色通道红色通道
//}
//void draw(){
//
//
//}
//*/
////int main(int argc, const char * argv[]) {
////    show();
////    waitKey();
////    return 1;
////}
//
