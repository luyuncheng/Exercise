////
////  Hw2_Histograms_normalization.cpp
////  testOpenCv
////
////  Created by 鲁蕴铖 on 16/4/4.
////  Copyright © 2016年 鲁蕴铖. All rights reserved.
////
//
//#include "Hw2_Histograms_normalization.hpp"
//#include <iostream>
//#include <cmath>
//#include <vector>
//#include <opencv2/opencv.hpp>
//#include <opencv2/core/core.hpp>
//#include <opencv2/imgproc/imgproc.hpp>
//#include <cv.h>
//#include <highgui.h>
//#include <algorithm>
//#include <map>
//#include <opencv2/highgui/highgui.hpp>
//using namespace std;
//using namespace cv;
//Mat srcimage1;
//Mat srcimage2;
//class Histogram_gray
//{
//public:
//    int histSize[1];//项的数量
//    float hranges[2];//像素的最小及最大值
//    const float *ranges[1];
//    int channels[1];//仅用到一个通道
//    Histogram_gray()
//    {
//        //准备1D直方图的参数
//        histSize[0] = 256;
//        hranges[0] = 0.0;
//        hranges[1] = 255.0;
//        ranges[0] = hranges;
//        channels[0] = 0;
//    }
//    MatND getHistogram_sys(const Mat &image){
//        MatND hist;
//        //计算直方图
//        calcHist(&image,1,channels,Mat(),hist,1,histSize,ranges,true,false);
//        return hist;
//    }
//    Mat getHistogramImage_sys(const Mat &image){
//        MatND hist = getHistogram_sys(image);
//        double maxVal = 0;
//        double minVal = 0;
//        minMaxLoc(hist, &minVal, &maxVal, 0, 0);
//        Mat histImg(histSize[0], histSize[0], CV_8U, Scalar(255));
//        int hpt = static_cast<int>(0.9 * histSize[0]);
//        for(int h = 0; h < histSize[0]; h ++)
//        {
//            float binVal = hist.at<float>(h);
//            int intensity = static_cast<int>(binVal * hpt / maxVal);
//            line(histImg, Point(h, histSize[0]), Point(h, histSize[0] - intensity), Scalar::all(0));
//        }
//        return histImg;
//    }
//    uchar max (uchar a1, uchar a2) {
//        return a1>a2?a1:a2;
//    }
//    uchar min (uchar a1, uchar a2) {
//        return a1<a2?a1:a2;
//    }
////    画出直方图
//    void drawline(string name,vector<int > mp,int total) {
//
//
//        Mat histImg(300,mp.size(),CV_8U,Scalar(255));
//        for(int i = 0; i<255; i++) {
//            if(mp[i]>=0) {
//                if(mp[i]>255){
//                    cout<<mp[i]<<endl;
//                    cout<<"histimage over 255"<<endl;
//                }
//                double val = mp[i];
//                double intensity = (val*1.0) / total * 1500;
//                // x,y 在上
//                line(histImg,Point(i,150),Point(i,150-intensity),Scalar::all(0),0);
//            }
//        }
//        imshow(name,histImg);
//    }
////    运用直方图改变原有图像
//    Mat applyHistoToimage(const Mat &image,vector<int> &mp) {
//        int h = image.rows, w = image.cols;
//        Mat newimage (image.rows,image.cols,CV_8U,Scalar(255));
//        for(int i = 0; i < h; i++) {
//
//            for(int j = 0; j < w; j++) {
//                uchar val = image.at<uchar>(i,j);
//                newimage.at<uchar>(i,j) = mp[val];
////                cout<<(int)val<<"/"<<(int)mp[val]<<"   ";
//            }
////            cout<<endl;
//        }
//
//        return newimage;
//    }
////    将直方图归一化
//    vector<int> TransHisto(const Mat &image,vector<int> &mp) {
//        int h = image.rows, w = image.cols;
//        int total = h*w;
//        vector<int> T(258,-1);
//        vector<double> pr(258,0.0);
//        int con = 0 ;
//        for(int i=0;i<mp.size();i++) {
//            pr[i] = (mp[i]*1.0)/(total*1.0);
//            con+=mp[i];
//        }
//        cout<<"total:"<<total<<" con:"<<con<<endl;
//        for(int i=0;i<mp.size();i++){
//            //sigma 求和
//            for(int j = 0; j<=i; j++) {
//                T[i] += 255.0 * pr[j];
//            }
//        }
////        drawline("trans",T);
//        return T;
//    }
////    直方图统计
//    vector<int> getHistogram_self(string name,const Mat &image) {
//        int h = image.rows, w = image.cols;
//        int total = h*w;
//        vector<int > mp(258,0);
//        for(int i = 0; i < h; i++) {
//            for(int j = 0; j < w; j++) {
//                int val = image.at<uchar>(i,j);
////                cout<<val<<endl;
//                if(val >= 256 && val <0 ) {
//                    cout<< "over gray 256"<<endl;
//                    return mp;
//                }
//                mp[val]++;
//            }
//        }
//        drawline(name,mp,total);
//        return mp;
////        TransHisto(image,mp);
//    }
//    void solve(const Mat &image){
//        imshow("Regional_gray",image);
//        vector<int> mp = getHistogram_self("region_histo",image);
//        vector<int>  T = TransHisto(image, mp);
//        Mat newimage = applyHistoToimage(image,T);
//        imshow("hist_image_gray", newimage);
//        getHistogram_self("newimage_histo",newimage);
//    }
//
//};
//class Histogram_color {
//public:
//    Mat applyHistoToimage(const Mat &image,vector<int> &mp) {
//        int h = image.rows, w = image.cols;
//        Mat newimage (h,w,CV_8UC3,Scalar(255));
//        for(int i = 0; i < h; i++) {
//
//            for(int j = 0; j < w; j++) {
//                Vec3b Tval = image.at<Vec3b>(i,j);
//                int val = Tval[2];
//                Tval[2] = mp[val];
//                newimage.at<Vec3b>(i,j) = Tval;
//                //                cout<<(int)val<<"/"<<(int)mp[val]<<"   ";
//            }
////            cout<<endl;
//        }
//
//        return newimage;
//    }
//    vector<int> TransHisto(const Mat &image,vector<int> &mp) {
//        int h = image.rows, w = image.cols;
//        int total = h*w;
//        vector<int> T(258,-1);
//        vector<double> pr(258,0.0);
//        int con = 0 ;
//        for(int i=0;i<mp.size();i++) {
//            pr[i] = (mp[i]*1.0)/(total*1.0);
//            con+=mp[i];
//        }
//        cout<<"total:"<<total<<" con:"<<con<<endl;
//        for(int i=0;i<mp.size();i++){
//            //sigma 求和
//            for(int j = 0; j<=i; j++) {
//                T[i] += 255.0 * pr[j];
//            }
//        }
//        //        drawline("trans",T);
//        return T;
//    }
//    //    直方图统计
//    vector<int> getHistogram_self(string name,const Mat &image) {
//        int h = image.rows, w = image.cols;
//        int total = h*w;
//        vector<int > mp(258,0);
//        for(int i = 0; i < h; i++) {
//            for(int j = 0; j < w; j++) {
//                Vec3b Tval = image.at<Vec3b>(i,j);
//                int val = Tval[2];
//                //                cout<<val<<endl;
//                if(val >= 256 && val <0 ) {
//                    cout<< "over gray 256"<<endl;
//                    return mp;
//                }
//                mp[val]++;
//            }
//        }
////        drawline(name,mp,total);
//        return mp;
//        //        TransHisto(image,mp);
//    }
//    void solve(const Mat &image) {
//        Mat hsi;
//        imshow("image_color",image);
////        转换成HSV图像
//        cvtColor(image, hsi, CV_BGR2HSV);
////        imshow("",hsi);
//        vector<int> mp = getHistogram_self("Hist", hsi);
//        vector<int>  T = TransHisto(hsi, mp);
//        Mat newhsiimage = applyHistoToimage(hsi,T);
//        Mat newimage;
////        转成BGR图像来看
//        cvtColor(newhsiimage, newimage, CV_HSV2BGR);
//        imshow("hist_image_color", newimage);
//    }
//};
//int main()
//{
//    srcimage1=imread("/Users/luyuncheng/Documents/图像/Homework/Hw2/cell.jpeg",CV_8U);
//    srcimage2=imread("/Users/luyuncheng/Documents/图像/Homework/Hw2/Hand.jpg",1);
//    if(!srcimage1.data || !srcimage2.data){
//        cout<<"no image data"<<endl;
//        return -1;
//    }
//
//    Histogram_gray h;
//    Histogram_color hc;
//    h.solve(srcimage1);
//    hc.solve(srcimage2);
//    waitKey();
//
//}