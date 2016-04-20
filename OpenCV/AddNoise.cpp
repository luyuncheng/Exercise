//
//
////
////  AddNoise.cpp
////  testOpenCv
////
////  Created by 鲁蕴铖 on 16/4/18.
////  Copyright © 2016年 鲁蕴铖. All rights reserved.
////
//
//#include "AddNoise.hpp"
//#include <iostream>
//#include <cmath>
//#include <vector>
//#include <algorithm>
//#include <opencv2/opencv.hpp>
//#include <opencv2/core/core.hpp>
//#include <cv.h>
//#include <highgui.h>
//#include <opencv2/highgui/highgui.hpp>
//#include <opencv2/imgproc/imgproc.hpp>
//using namespace std;
//using namespace cv;
////
//// 添加椒盐噪声子函数
////
//Mat Add_salt_pepper_Noise(const Mat &srcArr, float pa, float pb )
//{
//    Mat outs= srcArr.clone();
//    RNG rng; // rand number generate，实现随机数产生的类
//    int amount1=outs.rows*outs.cols*pa;
//    int amount2=outs.rows*outs.cols*pb;
//    for(int counter=0; counter<amount1; ++counter)
//    {
//        //随机令某个元素值为0即可看作是椒噪声，255为盐噪声
//        // rng.uniform( 0,srcArr.rows), rng.uniform(0, srcArr.cols)随机选取行列
//        outs.at<uchar>(rng.uniform( 0,outs.rows), rng.uniform(0, outs.cols)) =0;
//
//    }
//    for (int counter=0; counter<amount2; ++counter)
//    {
//        outs.at<uchar>(rng.uniform(0,outs.rows), rng.uniform(0,outs.cols)) = 255;
//    }
//    return outs;
//}
////
//// 添加高斯白噪声子函数
////
//Mat Add_gaussian_Noise(const Mat &srcArr,double mean,double sigma)
//{
//
//    Mat NoiseArr;
//    NoiseArr.create(srcArr.rows, srcArr.cols, srcArr.type());
//    Mat outs = NoiseArr.clone();
//    //    RNG rng;
//    //    rng.fill(NoiseArr, RNG::NORMAL, mean,sigma);  //产生高斯白噪声矩阵
//
//    randn(NoiseArr,mean,sigma); //同样可以使用randn函数产生高斯白噪声
//    add(srcArr, NoiseArr, outs);   //矩阵srcArr+NoiseArr->srcArr,至此，已经向srcArr添加高斯白噪声
//    return outs;
////    imshow("outs_gauss", outs);
//}
//
////
//// 均值滤波
////
//void mean_filter(string str,const Mat &src)
//{
//    // m n 为邻域
//    int m = 3, n = 3;
//    int tot = m*n;
////    算数均值
//    Mat image1 = src.clone();
//    for(int i = 1; i<image1.rows-1; i++)
//        for(int j = 1; j<image1.cols-1; j++) {
//            //邻域操作
//            int con = 0;
//            for(int k = -1; k <= 1; k++)
//                for(int l = -1; l <= 1; l++) {
//                    con+=(int)image1.at<uchar>(i+k, j+l);
//                }
//            image1.at<uchar>(i, j) = (con/tot)>=255 ? 255:(con/tot);
//        }
//    imshow(str+"mean1", image1);
//
////    几何均值
//    Mat image2 = src.clone();
//    typedef long long ll;
//    for(int i = 1; i<image2.rows-1; i++)
//        for(int j = 1; j<image2.cols-1; j++) {
//            //邻域操作
//            double con = 1;
//            double tot2 = m*n;
//            tot2 = 1.0/tot2;
//            for(int k = -1; k <= 1; k++)
//                for(int l = -1; l <= 1; l++) {
//                    if(image2.at<uchar>(i+k, j+l) != 0) {
//                        con = con * pow((ll)image2.at<uchar>(i+k, j+l),tot2);
//                    }
//                }
//            ll num = con+0.5;
//            image2.at<uchar>(i, j) = ( num >= 255 ? 255:num );
//        }
//    imshow(str+"mean2", image2);
//
////    谐波
//    Mat image3 = src.clone();
//    for(int i = 1; i<image3.rows-1; i++)
//        for(int j = 1; j<image3.cols-1; j++) {
//            double con = 0;
//
//            for(int k = -1; k <= 1; k++)
//                for(int l = -1; l <= 1; l++) {
//
//                    double tmp = image3.at<uchar>(i+k, j+l);
//                    if(tmp!=0)
//                        con+=(1.0 / tmp);
//                }
//            int num = tot*1.0 / con;
//            image3.at<uchar>(i, j) = (num >= 255 ? 255:num);
//        }
//    imshow(str+"mean3", image3);
//
////    逆谐波
//    double Q = 0;
//    Mat image4 = src.clone();
//    for(int i = 1; i<image4.rows-1; i++)
//        for(int j = 1; j<image4.cols-1; j++) {
//            double con1 = 0;
//            double con2 = 0;
//
//            for(int k = -1; k <= 1; k++)
//                for(int l = -1; l <= 1; l++) {
//                    double tmp = image4.at<uchar>(i+k, j+l);
//
//                    con1 += pow(tmp,Q+1);
//                    con2 += pow(tmp,Q);
//                }
//            double num = con1/con2;
//            image4.at<uchar>(i, j) = (num >= 255 ? 255:num);
//        }
//    imshow(str+"mean4", image4);
//}
////
//// 中值滤波
////
//void middle_filter(string str,const Mat &src)
//{
//    Mat image = src.clone();
//    for(int i = 1; i<image.rows-1; i++)
//        for(int j = 1; j<image.cols-1; j++) {
//            vector<int> que;
//            for(int k = -1; k <= 1; k++)
//                for(int l = -1; l <= 1; l++) {
//                    int tmp = image.at<uchar>(i+k, j+l);
//
//                    que.push_back(tmp);
//                }
////            nth_element(que.begin(), que.begin()+(que.size()/2), que.end());
//            sort(que.begin(),que.end());
//            uchar num = que[que.size()/2];
//            image.at<uchar>(i, j) = (num >= 255 ? 255:num);
//        }
//    imshow(str+"middle", image);
//}
//
////
//// 自适应均值滤波（局部降燥）
////
//void mean_regional(string str, const Mat &src)
//{
//    Mat image = src.clone();
//    int dn = 1000;
//    for(int i = 2; i<image.rows-2; i++)
//        for(int j = 2; j<image.cols-2; j++) {
//            double sum = 0;
//            double con = 0;
//            for(int k = -2; k<=2; k++)
//                for(int l = -2; l<=2; l++) {
//                    con++;
//                    sum+=image.at<uchar>(i+k,j+l);
//                }
//            double mean = sum/con;
//            double dl = 0;
//            for(int k = -2; k<=2; k++)
//                for(int l = -2; l<=2; l++) {
//                    int tmp = image.at<uchar>(i+k,j+l);
//                    dl += pow((tmp-mean),2.0);
//                }
//            double num = image.at<uchar>(i,j);
//            num = num - (dn/dl*(num-mean));
//            cout<<num-image.at<uchar>(i,j)<<endl;
//            if(num<0)num=0;
//            if(num>=255)num = 255;
//            image.at<uchar>(i,j)=num;
//        }
//    imshow(str+"mean_regional", image);
//}
////
//// 自适应中值滤波（局部降燥）
////
//void middle_regional(string str, const Mat &src)
//{
//    Mat image = src.clone();
//    for(int i = 2; i<image.rows-2; i++)
//        for(int j = 2; j<image.cols-2; j++) {
//            double mi = INT_MAX;
//            double mx = -1;
//            vector<int> que;
//            for(int k = -2; k<=2; k++)
//                for(int l = -2; l<=2; l++) {
//                    mi = min ((double)image.at<uchar>(i+k,j+l),mi);
//                    mx = max ((double)image.at<uchar>(i+k,j+l),mx);
//                    que.push_back(image.at<uchar>(i+k,j+l));
//                }
//            sort(que.begin(),que.end());
//            double mid = que[que.size()/2];
//            // process A did not change size of window
//            double a1 = mid - mi;
//            double a2 = mid - mx;
//            int num = image.at<uchar>(i,j);
////            process B
//            if(a1>0 && a2<0) {
//                double b1 = num - mi;
//                double b2 = num - mx;
//                if(b1>0 && b2<0)
//                    num = image.at<uchar>(i,j);
//                else
//                    num = mid;
//            } else {
//                //process A
//                num = mid;
//            }
//            if(num<0)num=0;
//            if(num>=255)num = 255;
//            image.at<uchar>(i,j)=num;
//        }
//    imshow(str+"middle_regional", image);
//}
////
//// 彩色图像均值滤波
////
//void color_mean_filter(string str,const Mat &src)
//{
//    // m n 为邻域
//    int m = 5, n = 5;
//    int tot = m*n;
//    //    算数均值
//    Mat image1 = src.clone();
//    for(int i = 2; i<image1.rows-2; i++)
//        for(int j = 2; j<image1.cols-2; j++) {
//            //邻域操作
//            int con1 = 0;
//            int con2 = 0;
//            int con3 = 0;
//            for(int k = -2; k <= 2; k++)
//                for(int l = -2; l <= 2; l++) {
//                    Vec3b tmp= image1.at<Vec3b>(i+k,j+l);
//                    con1+=tmp[0];
//                    con2+=tmp[1];
//                    con3+=tmp[2];
//                }
//            con1/=tot; con2/=tot; con3/=tot;
//            con1 = con1>=255? 255:con1;
//            con2 = con2>=255? 255:con2;
//            con3 = con3>=255? 255:con3;
//            Vec3b num(con1,con2,con3);
//            image1.at<Vec3b>(i, j) = num;
//        }
//    imshow(str+"color_mean1", image1);
//
//    //    几何均值
//    Mat image2 = src.clone();
//    typedef long long ll;
//    for(int i = 2; i<image2.rows-2; i++)
//        for(int j = 2; j<image2.cols-2; j++) {
//            //邻域操作
//            typedef long long ll;
//            double con1 = 1;
//            double con2 = 1;
//            double con3 = 1;
//            double tt = 0;
//            for(int k = -2; k <= 2; k++)
//                for(int l = -2; l <= 2; l++) {
//                    Vec3b tmp= image2.at<Vec3b>(i+k,j+l);
//                    if(tmp[0] != 0 && tmp[1] !=0 && tmp[2] !=0) {
//                        con1*= ((ll)tmp[0] == 0? 1:tmp[0]);
//                        con2*= ((ll)tmp[1] == 0? 1:tmp[1]);
//                        con3*= ((ll)tmp[2] == 0? 1:tmp[2]);
//                        tt ++;
//                    }
//                }
//            double t = 1.0/tt;
//            con1 = pow(con1,t);
//            con2 = pow(con2,t);
//            con3 = pow(con3,t);
//            con1 = con1>=255? 255:con1;
//            con2 = con2>=255? 255:con2;
//            con3 = con3>=255? 255:con3;
//            Vec3b num(con1,con2,con3);
//            image2.at<Vec3b>(i, j) = num;
//        }
//    imshow(str+"color_mean2", image2);
//}
//
//int main()
//{
//    Mat image = imread("/Users/luyuncheng/Documents/图像/Homework/Hw4/box_in_scene.png",CV_8U);
//    imshow("regional", image);
//    Mat gaussian_noise = Add_gaussian_Noise(image,60,10);
//    Mat salt_noise = Add_salt_pepper_Noise(image, 0.1, 0.1);
////    imshow("gaussian_noise", gaussian_noise);
////    imshow("salt_noise", salt_noise);
////    mean_filter("gauss",gaussian_noise);
////    mean_filter("salt",salt_noise);
////    middle_filter("gauss",gaussian_noise);
////    middle_filter("salt",salt_noise);
////    mean_regional("gauss", gaussian_noise);
////    mean_regional("salt_noise", salt_noise);
////    middle_regional("gauss", gaussian_noise);
////    middle_regional("salt_noise", salt_noise);
//    Mat image_color = imread("/Users/luyuncheng/Documents/图像/Homework/Hw4/lena.jpg");
//    imshow("color",image_color);
//    color_mean_filter("color", image_color);
//    waitKey();
//}