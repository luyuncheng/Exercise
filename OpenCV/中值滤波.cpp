//
//  中值滤波.cpp
//  testOpenCv
//
//  Created by 鲁蕴铖 on 15/6/13.
//  Copyright (c) 2015年 鲁蕴铖. All rights reserved.
//
/*
#include <iostream>
#include <vector>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <cv.h>
#include <highgui.h>
#include <algorithm>
#include <opencv2/highgui/highgui.hpp>
using namespace std;
using namespace cv;
typedef vector<Vec3b> row;
typedef vector<row> mat;
Mat pic1;
mat kernel;
int w,h;
mat in;
mat tmp;
mat t;
Vec3b medianNeighbour( int x,int y)
{
    //取算子的中间值
    vector<int> blue;
    vector<int> green;
    vector<int> red;
    blue.clear();green.clear();red.clear();
    for(int i=0;i<kernel.size();i++)
        for(int j=0;j<kernel[i].size();j++){
            Vec3b  tt= tmp[x-1+i][y-1+j];
            blue.push_back(tt[0]);
            green.push_back(tt[1]);
            red.push_back(tt[2]);
        }
    Vec3b tt;int mid=0;
    set<int>::iterator itb,itg,itr;
    int aa=0,bb=0,cc=0;
    sort(blue.begin(),blue.end());
    sort(green.begin(),green.end());
    sort(red.begin(),red.end());
    
    tt[0]=blue[4],tt[1]=green[4],tt[2]=red[4];
    return tt;
    
}
void smooth(int iterations){
    mat output;
    tmp.resize(h);
    output.resize(h);
    for(int i=0;i<h;i++)
    {
        output[i].resize(w);
        tmp[i].resize(w);
        for(int j=0;j<w;j++)
        {
            output[i][j]=in[i][j];
            tmp[i][j]=in[i][j];
        }
    }
    
    for(int its=0;its<iterations;its++)
    {//边缘直接不处理
        for(int i=1;i<h-1;i++)
        {
            for(int j=1;j<w-1;j++)
            {
                output[i][j]=medianNeighbour(i, j);
            }
        }
        printf("迭代： %d次\n", its+1);
        for(int i=0;i<h;i++)
            for(int j=0;j<w;j++){
                tmp[i][j]=output[i][j];
            }
    }
    Mat res;
    res.create(h, w, 16);
    for(int i=0;i<h;i++)
        for(int j=0;j<w;j++){
            res.at<Vec3b>(i,j)=output[i][j];
            //            printf("%d %d",i,j);
        }
    
    namedWindow("window");
    imshow("window", res);
}
long long hahaha(long long x,long long y);
void test();
int main(int argc, const char * argv[])
{
    kernel.resize(3);
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            kernel[i].push_back(1);
    
    pic1 = imread("/Users/luyuncheng/Pictures/com.tencent.ScreenCapture/test.png");
    if(!pic1.data){
        printf("no image data\n");
    }
    printf("let in\n");
    printf("channel:%d\n",pic1.channels());
    printf("h:%d   w:%d\n",pic1.rows,pic1.cols);
    printf("type:%d\n",pic1.type());
    
    h=pic1.rows,w=pic1.cols;
    in.resize(h);
    for(int i=0;i<h;i++)
    {
        in[i].resize(w);
        for(int j=0;j<w;j++)
        {
            in[i][j]=pic1.at<Vec3b>(i,j);
        }
    }
    smooth(1);
    while(1){}
    return 0;
}
*/