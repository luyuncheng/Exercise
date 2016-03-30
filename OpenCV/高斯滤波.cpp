////
////  高斯滤波.cpp
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
//#include <algorithm>
//#include <opencv2/highgui/highgui.hpp>
//using namespace std;
//using namespace cv;
//Mat image;
//typedef vector<Vec3b> row;
//typedef vector<row> mat;
//mat in,tmp,output;
//int w,h;
//double pi=M_PI;
//double kernel[10][10]={0};
//double mins=999999999;
//void test()
//{
//    double n=5;
//    double mid=floor((n+1)/2);
//    double sigma=1.0;
//    for(int i=1;i<=n;i++){
//        for(int j=1;j<=n;j++)
//        {//p为0 （x,y）~(u1,u2,sigma,sigma,0)的二维正态分布
//         //我取u1＝u2 为mid值 我算的3*3的没问题 但是貌似算大5*5中间值会有误差
//         //取中点也就是期望值，用坐标去－期望值就是i－mid 那么就符合二维正态分布
//            double ttt=((i-mid)*(i-mid)+(j-mid)*(j-mid))/(2*sigma*sigma);
//            double t=exp(- ( ttt ));
//            //printf("%.3lf", t);
//            //scanf("%lf",ttt);
//            double  a=t/(2*pi*sigma*sigma);
//            if(a<mins)
//                mins=a;
//            kernel[i][j]=a;
//        }
//    }
//    for(int i=1;i<=n;i++)
//        for(int j=1;j<=n;j++)
//        {//先归一化操作 然后向上取整
//            kernel[i][j]/=mins;
//            kernel[i][j]=ceil(kernel[i][j]);
//        }
//    for(int i=1;i<=n;i++){
//        for(int j=1;j<=n;j++){
//            printf("%.3lf ",(kernel[i][j]));
//        }
//        cout<<endl;
//    }
//    printf("mins:%.10lf",mins);
//}
//Vec3b guessbour(int x,int y){
//    double sum0=0,sum1=0,sum2=0;
//    for(int i=0;i<5;i++)
//        for(int j=0;j<5;j++){
//            Vec3b  tt= tmp[x-2+i][y-2+j];
//            sum0+=tt[0]*kernel[i+1][j+1];
//            sum1+=tt[1]*kernel[i+1][j+1];
//            sum2+=tt[0]*kernel[i+1][j+1];
//        }
//    Vec3b tt;
//    tt[0]=sum0*mins;
//    tt[1]=sum1*mins;
//    tt[2]=sum2*mins;
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
//                output[i][j]=guessbour(i,j);
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
//    imshow("windowmyself", res);
//    imwrite("/Users/luyuncheng/Pictures/com.tencent.ScreenCapture/test2_myself.png",res);
//
//}
//void solve()
//{
//    h=image.rows,w=image.cols;
//    in.resize(h);
//    for(int i=0;i<h;i++)
//    {
//        in[i].resize(w);
//        for(int j=0;j<w;j++)
//        {
//            in[i][j]=image.at<Vec3b>(i,j);
//        }
//    }
//    smooth(1);
//
//}
//void solveinopencv()
//{
//    namedWindow("window原始图" );
//    namedWindow("windowopencv");
//    imshow("window原始图", image );
//    //进行均值滤波操作
//    Mat out;
//    GaussianBlur(image, out, Size( 5, 5 ), 1, 1);
//    imshow("windowopencv" ,out );
//    imwrite("/Users/luyuncheng/Pictures/com.tencent.ScreenCapture/test2_opencv.png",out);
//}
//int main()
//{
//    //载入原图
//    image=imread("/Users/luyuncheng/Pictures/com.tencent.ScreenCapture/test2.png");
//    if(!image.data){
//        cout<<"no image data"<<endl;
//    }
//    test();
//    solve();
//    solveinopencv();
//    waitKey();
//}*/