////
////  均值滤波.cpp
////  testOpenCv
////
////  Created by 鲁蕴铖 on 15/6/13.
////  Copyright (c) 2015年 鲁蕴铖. All rights reserved.
////
///*
//#include <iostream>
//#include <vector>
//#include <opencv2/opencv.hpp>
//#include <opencv2/core/core.hpp>
//#include <cv.h>
//#include <highgui.h>
//#include <opencv2/highgui/highgui.hpp>
//using namespace std;
//using namespace cv;
//typedef vector<Vec3b> row;
//typedef vector<row> mat;
//Mat pic1;
//mat kernel;
//int w,h;
//mat in;
//mat tmp;
//mat t;
//Vec3b meanneighbour( int x,int y)
//{
//    //input输入矩阵，kernel时核，w是图像宽度，h是图像高度，x，y是像素点坐标,kernelw为核的宽度
//    int sum1=0;
//    int sum2=0;
//    int sum3=0;
//    for(int i=0;i<kernel.size();i++)
//        for(int j=0;j<kernel[i].size();j++){
//            Vec3b  tt= tmp[x-1+i][y-1+j];
//            sum1+=tt[0];
//            sum2+=tt[1];
//            sum3+=tt[2];
//        }
//    sum1/=9;sum2/=9;sum3/=9;
//    Vec3b tt;
//    tt[0]=sum1;tt[1]=sum2;tt[2]=sum3;
//
//    //    if(num<9)cout<<"i.j:"<<x<<" "<<y<<endl;
//    //    if(num==0)return 0;
//    return tt;
//
//}
//void smooth(int iterations){
//    mat output;
//    tmp.resize(h);
//    output.resize(h);
//    for(int i=0;i<h;i++)
//    {
//        output[i].resize(w);
//        tmp[i].resize(w);
//        for(int j=0;j<w;j++)
//        {
//            output[i][j]=in[i][j];
//            tmp[i][j]=in[i][j];
//        }
//    }
//
//    for(int its=0;its<iterations;its++)
//    {
//        for(int i=1;i<h-1;i++)
//        {
//            for(int j=1;j<w-1;j++)
//            {
//                output[i][j]=meanneighbour(i, j);
//            }
//            //                printf("处理一行\n");
//        }
//        printf("迭代： %d\n", its);
//        for(int i=0;i<h;i++)
//            for(int j=0;j<w;j++){
//                tmp[i][j]=output[i][j];
//            }
//    }
//    Mat res;
//    //    printf("%d %d %d %d",output.size(),output[1].size(),h,w);
//    //    while(1){}
//    res.create(h, w, 16);
//    for(int i=0;i<h;i++)
//        for(int j=0;j<w;j++){
//            res.at<Vec3b>(i,j)=output[i][j];
//            //            printf("%d %d",i,j);
//        }
////     for(long long i=0;i<h;i++)
////     for(long long j=0;j<w;j++)
////     if(pic1.at<long long>(i,j)!=res.at<long long>(i,j))
////     //if(inputs[i][j]!=output[i][j])
////     printf("结果：：：%d %d %d",output[i][j],res.at<long long>(i,j),inputs[i][j]);
////
//    namedWindow("window");
//    imshow("window", res);
//}*/
///*
//long long hahaha(long long x,long long y);
//void test();
//void solve(){
//
//    kernel.resize(3);
//    for(int i=0;i<3;i++)
//        for(int j=0;j<3;j++)
//            kernel[i].push_back(1);
//    //    test();
//
//    pic1 = imread("/Users/luyuncheng/Pictures/com.tencent.ScreenCapture/test.png");
//    if(!pic1.data){
//        printf("no image data\n");
//    }
//    printf("let in\n");
//    printf("channel:%d\n",pic1.channels());
//    printf("h:%d   w:%d\n",pic1.rows,pic1.cols);
//    printf("type:%d\n",pic1.type());
//
//    h=pic1.rows,w=pic1.cols;
//    in.resize(h);
//    //    cout<<pic1.at<long long>(1,1);
//    //    while(1){}
//    for(int i=0;i<h;i++)
//    {
//        in[i].resize(w);
//        for(int j=0;j<w;j++)
//        {
//            in[i][j]=pic1.at<Vec3b>(i,j);
//            //            printf("%d ",in[i][j]);
//        }
//        //        printf("\n");
//    }
//    smooth(1);
//    while(1){}
//}
//int main2(int argc, const char * argv[])
//{
//    return 0;
//}*/
///*
// long long hahaha( int x,int y)
// {
// //input输入矩阵，kernel时核，w是图像宽度，h是图像高度，x，y是像素点坐标,kernelw为核的宽度
// int sum=0;
// int num=0;
// cout<<"kernelsize:"<<kernel.size()<<" "<<kernel[0].size()<<endl;
// for(int i=0;i<kernel.size();i++)
// for(int j=0;j<kernel[i].size();j++){
// cout<<"x-1+i:"<<x-1+i<<" j-1+y:"<<y+j-1<<endl;
// if((kernel[i][j]==1)&& ((x-1+i)>=0) && ((x-1+i)<3) && ((y-1+i)>=0) && ((y-1+i)<5)){
// printf("[%d][%d]=%d\n",x-1+i,y-1+j,t[x-1+i][y-1+j]);
// sum+=t[x-1+i][y-1+j];
// num++;
// }
// }
// if(num==0)return 0;
// return (sum/num);
//
// }
//
// void test()
// {
// t.resize(3);
// int tcon=1;
// for(int i=0;i<3;i++)
// {
// for(int j=0;j<5;j++)
// {
// t[i].push_back(tcon++);
// cout<<t[i][j]<<"  ";
// }
// cout<<endl;
// }
// cout<<hahaha(1,3);
// while(1){}
// }*/