//
//  边缘检测_sobel2.cpp
//  testOpenCv
//
//  Created by 鲁蕴铖 on 15/6/17.
//  Copyright (c) 2015年 鲁蕴铖. All rights reserved.
//
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
#include <opencv2/imgproc/imgproc.hpp>
using namespace std;
using namespace cv;
typedef vector<Vec3b> row;
typedef vector<row> mat;
Mat pic1,res,res2;
mat kernel,output1,output2;
int w,h;
mat in;
mat tmp;
mat t;

void grey_guess()
{
    cout<<endl<<"output::"<<output1.size()<<" "<<output1[0].size()<<endl;
    for(int i=0;i<h;i++)
        for(int j=0;j<w;j++)
        {
            Vec3b tt=in[i][j];
            //Y=0.3R+0.59G+0.11B
            int tmp=ceil((tt[0]*11+tt[1]*59+tt[2]*30)/100);
            //int tmp=(tt[0]+tt[1]+tt[2])/3+0.5;
            tt[0]=tmp;
            tt[1]=tmp;
            tt[2]=tmp;
            //cout<<i<<" "<<j<<endl;
            output1[i][j]=tt;
        }
    res2.create(h, w, pic1.type());
    for(int i=0;i<h;i++)
        for(int j=0;j<w;j++)
            res2.at<Vec3b>(i,j)=output1[i][j];
    namedWindow("windowmyself");
    imshow("windowmyself", res2);
    
    //图像高斯滤波一次
    //GaussianBlur(res, image2, Size( 3, 3 ), 1, 1);
    //imshow("windowopencv" ,image2 );
    
}
Vec3b doub(Vec3b v)
{
    Vec3b vv;
    vv[0]=v[0]*2;
    vv[1]=v[1]*2;
    vv[2]=v[2]*2;
    return vv;
}
Vec3b sobel( int x,int y)
{
    Vec3b p1=tmp[x-1][y-1];
    Vec3b p2=tmp[x-1][y];
    Vec3b p3=tmp[x-1][y+1];
    Vec3b p4=tmp[x][y-1];
    Vec3b p5=tmp[x][y];
    Vec3b p6=tmp[x][y+1];
    Vec3b p7=tmp[x+1][y-1];
    Vec3b p8=tmp[x+1][y];
    Vec3b p9=tmp[x+1][y+1];
    //    Vec3b p7=tmp[x-1][y-1];
    //    Vec3b p8=tmp[x-1][y];
    //    Vec3b p9=tmp[x-1][y+1];
    //    Vec3b p4=tmp[x][y-1];
    //    Vec3b p5=tmp[x][y];
    //    Vec3b p6=tmp[x][y+1];
    //    Vec3b p1=tmp[x+1][y-1];
    //    Vec3b p2=tmp[x+1][y];
    //    Vec3b p3=tmp[x+1][y+1];
    
    Vec3b gx = (p3+doub(p6)+p9-p1-doub(p4)-p7);
    Vec3b gy = (p1+doub(p2)+p3-p7-doub(p8)-p9);
    Vec3b tt;
    //double dgx=gx[0];
    //double dgy=gy[0];
    //double val=sqrt(dgx*dgx+dgy*dgy);
    if(gx[0]<0)
    {
        gx[0]=-gx[0];
    }
    if(gy[0]<0)
    {
        gy[0]=-gy[0];
    }
    Vec3b ttt;
    ttt[0]=gx[0]+gy[0];
    //double val=fabs(dgx)+fabs(dgy);
    if(ttt[0]<0)ttt[0]=-ttt[0];
    tt[0]=tt[1]=tt[2]=ttt[0];
    return tt;
    
}
void smooth(int iterations){
    tmp.resize(h);
    output2.resize(h);
    for(int i=0;i<h;i++)
    {
        output2[i].resize(w);
        tmp[i].resize(w);
        for(int j=0;j<w;j++)
        {
            output2[i][j]=output1[i][j];
            tmp[i][j]=output1[i][j];
        }
    }
    
    for(int its=0;its<iterations;its++)
    {//边缘直接不处理
        for(int i=1;i<h-1;i++)
        {
            for(int j=1;j<w-1;j++)
            {
                output2[i][j]=sobel(i, j);
            }
        }
        printf("迭代： %d次\n", its+1);
        for(int i=0;i<h;i++)
            for(int j=0;j<w;j++){
                tmp[i][j]=output2[i][j];
            }
    }
    double limit=0;//上线阈值
    for(int i=0;i<h;i++)
        for(int j=0;j<w;j++)
        {
            if(limit<output2[i][j][0])
                limit=output2[i][j][0];
        }
    limit=limit;
    cout<<"limit:"<<limit<<endl;
    Vec3b ou1,ou2;
    ou1[0]=255;
    ou1[1]=255;
    ou1[2]=255;
    ou2[0]=0;
    ou2[1]=0;
    ou2[2]=0;
    
    for(int i=0;i<h;i++)
        for(int j=0;j<w;j++)
        {
            if(output2[i][j][0]>=100)
            {
                output2[i][j]=ou1;
            }
            else
            {
                output2[i][j]=ou2;
            }
        }
    Mat res;
    res.create(h, w, 16);
    for(int i=0;i<h;i++)
        for(int j=0;j<w;j++){
            res.at<Vec3b>(i,j)=output2[i][j];
            //            printf("%d %d",i,j);
        }
    
    namedWindow("window");
    imshow("window", res);
}
void sobel_opencv()
{
    Mat gradx,grady,absgradx,absgrady,dst;
    Sobel(res2,gradx,CV_16S,1,0,3,1,1,BORDER_DEFAULT );
    convertScaleAbs(gradx,absgradx);
    namedWindow("x");
    namedWindow("y");
    namedWindow("1");
    imshow("x",absgradx);
    Sobel(res2,grady,CV_16S,0,1,3,1,1,BORDER_DEFAULT );
    convertScaleAbs(grady,absgrady);
    imshow("y",absgrady);
    addWeighted(absgradx, 0.5, absgrady, 0.5, 0, dst);
    imshow("1",dst);
    
}
int main(int argc, const char * argv[])
{
    
    pic1 = imread("/Users/luyuncheng/Pictures/com.tencent.ScreenCapture/test10.jpg");
    if(!pic1.data){
        printf("no image data\n");
    }
    printf("let in\n");
    printf("channel:%d\n",pic1.channels());
    printf("h:%d   w:%d\n",pic1.rows,pic1.cols);
    printf("type:%d\n",pic1.type());
    
    h=pic1.rows,w=pic1.cols;
    in.resize(h);
    output1.resize(h);
    for(int i=0;i<h;i++)
    {
        output1[i].resize(w);
        in[i].resize(w);
        for(int j=0;j<w;j++)
        {
            in[i][j]=pic1.at<Vec3b>(i,j);
        }
    }
    grey_guess();
    smooth(1);
    //sobel_opencv();
    waitKey();
    while(1){}
    return 0;
}
/*
 //默许对8位位图进行处理
 void Sobel(unsigned char *pIn, int width, int height, unsigned char *pOut)
 {
 //每行像素所占字节数，输出图象与输入图象相同
 int lineByte=(width+3)/4*4;
 //申请输出图象缓冲区
 pOut=new unsigned char[lineByte*height];
 //循环变量，图象的坐标
 int i,j;
 //中间变量
 int x, y, t;
 //Sobel算子
 for(i=1;i<height⑴;i++)
 {
 for(j=1;j<width⑴;j++)
 {
 //x方向梯度
 x= *(pIn+(i⑴)*lineByte+j+1) + 2 * *(pIn+i*lineByte+j+1) + *(pIn+(i+1)*lineByte+j+1) - *(pIn+(i⑴)*lineByte+j⑴) - 2 * *(pIn+i*lineByte+j⑴) - *(pIn+(i+1)*lineByte+j⑴);
 //y方向梯度
 y= *(pIn+(i⑴)*lineByte+j⑴) + 2 * *(pIn+(i⑴)*lineByte+j) + *(pIn+(i⑴)*lineByte+j+1) - *(pIn+(i+1)*lineByte+j⑴) - 2 * *(pIn+(i+1)*lineByte+j) - *(pIn+(i+1)*lineByte+j+1);
 t=abs(x)+abs(y)+0.5;
 if (t>100)
 { *(pOut+i*lineByte+j)=255; }
 else { *(pOut+i*lineByte+j)=0; }
 }
 }
 for(j=0;j<width;j++)
 {
 *(pOut+(height⑴)*lineByte+j)=0;//补齐最后1行
 *(pOut+j)=0;//补齐第1行
 }
 for(i=0;i<height;i++)
 {
 *(pOut+i*lineByte)=0;//补齐第1列
 *(pOut+i*lineByte+width⑴)=0;//补齐最后1列
 }
 }
 }*/