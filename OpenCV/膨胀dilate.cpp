////
////  膨胀dilate.cpp
////  testOpenCv
////
////  Created by 鲁蕴铖 on 15/6/15.
////  Copyright (c) 2015年 鲁蕴铖. All rights reserved.
////
///*
//#include <iostream>
//#include <vector>
//#include <opencv2/opencv.hpp>
//#include <opencv2/core/core.hpp>
//#include <cv.h>
//#include <highgui.h>
//#include <algorithm>
//#include <cmath>
//#include <opencv2/highgui/highgui.hpp>
//using namespace std;
//using namespace cv;
//Mat image;
//typedef vector<Vec3b> row;
//typedef vector<row> mat;
//mat in,tmp,output;
//int w,h;
//
//Vec3b dilate(int x,int y){
//    //由于我默认在区域范围内扫描 所以就省去了判断边界操作
//    int sum0=-256,sum1=-256,sum2=-256;
//    for(int i=0;i<5;i++)
//        for(int j=0;j<5;j++){
//            Vec3b  tt= tmp[x-2+i][y-2+j];
//            sum0=sum0>tt[0]?sum0:tt[0];
//            sum1=sum0>tt[1]?sum0:tt[1];
//            sum2=sum0>tt[2]?sum0:tt[2];
//        }
//    Vec3b tt;
//    tt[0]=sum0;    tt[1]=sum1;    tt[2]=sum2;
//    return tt;
//}
//void smooth(int iterations)
//{
//    tmp.resize(h),output.resize(h);
//    for(int i=0;i<h;i++){
//        tmp[i].resize(w),output[i].resize(w);
//        for(int j=0;j<w;j++){
//            output[i][j]=tmp[i][j]=in[i][j];
//        }
//    }
//    while(iterations--){
//        for(int i=2;i<h-2;i++)
//            for(int j=2;j<w-2;j++)
//                output[i][j]=dilate(i,j);
//        for(int i=0;i<h;i++)
//            for(int j=0;j<w;j++){
//                tmp[i][j]=output[i][j];
//            }
//    }
//    Mat res;
//    res.create(h, w, image.type());
//    for(int i=0;i<h;i++)
//        for(int j=0;j<w;j++)
//            res.at<Vec3b>(i,j)=output[i][j];
//    namedWindow("windowmyself");
//    //imshow("windowmyself", res);
//    imwrite("/Users/luyuncheng/Pictures/com.tencent.ScreenCapture/test5_myself.png",res);
//}
//
//void solve(){
//    h=image.rows,w=image.cols;
//    in.resize(h);
//    for(int i=0;i<h;i++){
//        in[i].resize(w);
//        for(int j=0;j<w;j++){
//            in[i][j]=image.at<Vec3b>(i,j);
//        }
//    }
//    smooth(1);
//}
//void solveinopencv()
//{
//    namedWindow("window原始图" );
//    namedWindow("windowopencv");
//    imshow("window原始图", image );
//    Mat out;
//    //自定义核
//    Mat element = getStructuringElement(MORPH_RECT, Size(5, 5));
//    //膨胀操作
//    dilate(image, out,element);
//    //imshow("windowopencv" ,out );
//    imwrite("/Users/luyuncheng/Pictures/com.tencent.ScreenCapture/test5_opencv.png",out);
//}
//int main()
//{
//    image=imread("/Users/luyuncheng/Pictures/com.tencent.ScreenCapture/test5.jpg");
//    if(!image.data){
//        cout<<"no image data"<<endl;
//        return 0;
//    }
//    solveinopencv();
//    solve();
//    waitKey();
//    return 0;
//}
//*/