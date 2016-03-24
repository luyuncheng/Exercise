//
//  detect.cpp
//  testOpenCv
//
//  Created by 鲁蕴铖 on 15/6/22.
//  Copyright (c) 2015年 鲁蕴铖. All rights reserved.
//
/*
#include <opencv2/objdetect/objdetect.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <iostream>
#include <vector>
#include <cstdio>
#include <cmath>
#include <cstdlib>
using namespace std;
using namespace cv;

// 函数声明 /
void detectAndDisplay( Mat frame );

// 全局变量 /
string face_cascade_name = "/Users/luyuncheng/Downloads/opencv-2.4.11/data/haarcascades/haarcascade_frontalface_alt.xml";
string eyes_cascade_name = "/Users/luyuncheng/Downloads/opencv-2.4.11/data/haarcascades/haarcascade_eye_tree_eyeglasses.xml";
CascadeClassifier face_cascade;
CascadeClassifier eyes_cascade;
string window_name = "Capture - Face detection";
RNG rng(12345);
// @主函数 /
int main( int argc, const char** argv )
{
    
    //-- 1. 加载级联分类器文件
    if( !face_cascade.load( face_cascade_name ) ){ printf("--(!)Error loading\n"); return -1; };
    if( !eyes_cascade.load( eyes_cascade_name ) ){ printf("--(!)Error loading\n"); return -1; };

    Mat in=imread("/Users/luyuncheng/Pictures/com.tencent.ScreenCapture/test10.png");
    
    cvtColor(in, in, CV_BGR2BGRA);//三通道转四通道设置透明值
    cout<<"in chanels:"<<in.channels()<<endl;
    detectAndDisplay(in);
    waitKey();
    return 0;
}
void int2str(const int &int_tmp,string &string_tmp){
    stringstream stream;
    stream<<int_tmp;
    string_tmp=stream.str();
}
// @函数 detectAndDisplay /
void detectAndDisplay( Mat frame )
{
    
    vector<Rect> faces;
    faces.clear();
    Mat frame_gray;
    //将图像转化为灰度图
    cvtColor( frame, frame_gray, CV_BGRA2GRAY );
    equalizeHist( frame_gray, frame_gray );
    
    //-- 多尺寸检测人脸
    face_cascade.detectMultiScale( frame_gray, faces, 1.1, 2, 0|CV_HAAR_SCALE_IMAGE, Size(30, 30) );
    
    for( int i = 0; i < faces.size(); i++ )
    {
        Point center( faces[i].x + faces[i].width*0.5, faces[i].y + faces[i].height*0.5 );
        faces[i].height=faces[i].height;
        faces[i].width=faces[i].width;
        Mat faceROI = frame_gray( Rect( faces[i]));
        String num;
        int2str(i,num);
        string faceregion="faceregion"+num;
        
        imshow(faceregion, faceROI);
        //画轮廓
        //灰度处理并模糊操作
        Mat tmp=faceROI.clone();
        //cvtColor(tmp,tmp,CV_BGR2GRAY);
        blur(tmp,tmp,Size(3,3));
        Mat canny_out;
        vector< vector<Point> > contours;
        vector<Vec4i> hierarchy;
        Canny(tmp, canny_out, 100, 180,3);
        String cannyshow="canny"+num;
        imshow(cannyshow, canny_out);
        findContours(canny_out, contours, hierarchy, CV_RETR_TREE,                   CV_CHAIN_APPROX_SIMPLE,Point(0,0));
        Mat drawing=Mat::zeros(canny_out.size(), CV_8UC4);
        
        
        for(int i=0;i<contours.size();i++)
        {
            Scalar color=Scalar(0, 255, 255);
            drawContours(drawing, contours, i, color,1,8,hierarchy,2,Point());
        }
        Mat imageRoi=frame(faces[i]);
        cout<<imageRoi.cols<<" "<<imageRoi.rows<<endl;
        cout<<drawing.cols<<" "<<drawing.rows<<endl;
        cout<<"channels:  "<<imageRoi.channels()<<endl;
        cout<<"channels:  "<<drawing.channels()<<endl;
        //cvtColor(drawing,drawing, CV_BGR2GRAY); //注意如果addweighted需要两个图的通道数相同
        //因为要加权后上图需透明，所以把aa［3］＝0改为透明色
        for(int i=0;i<drawing.cols;i++)
        {
            for(int j=0;j<drawing.rows;j++)
            {
                Vec4b aa = drawing.at<Vec4b>(i,j);
                aa[3]=0;
                if(aa[0]!=0 && aa[1]!=128 && aa[2]!=255)
                {
                    aa[0]=0;
                    aa[1]=0;
                    aa[2]=0;
                    aa[3]=0;
                }
            }
            //cout<<endl;
        }
        
        addWeighted(imageRoi, 1, drawing, 1, 0, imageRoi);
        //drawing.copyTo(faceROI,tmp);
        String faceshow="face"+num;
        imshow(faceshow, drawing);
        Scalar colors=Scalar(0,128,256);
        ellipse( frame, center, Size( faces[i].width*0.5, faces[i].height*0.5), 0, 0, 360, colors, 4, 8, 0 );

        std::vector<Rect> eyes;
        //-- 在每张人脸上检测双眼
        eyes_cascade.detectMultiScale( faceROI, eyes, 1.1, 2, 0 |CV_HAAR_SCALE_IMAGE, Size(30, 30) );
        
        for( int j = 0; j < eyes.size(); j++ )
        {
            Point center( faces[i].x + eyes[j].x + eyes[j].width*0.5, faces[i].y + eyes[j].y + eyes[j].height*0.5 );
            int radius = cvRound( (eyes[j].width + eyes[i].height)*0.25 );
            circle( frame, center, radius, Scalar( 255, 0, 0 ), 4, 8, 0 );
        }
    }
    //-- 显示结果图像
    imshow( window_name, frame );
    imwrite("/Users/luyuncheng/Pictures/com.tencent.ScreenCapture/test13.png",frame);
}*/