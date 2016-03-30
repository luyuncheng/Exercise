////
////  双边滤波.cpp
////  testOpenCv
////
////  Created by 鲁蕴铖 on 15/6/14.
////  Copyright (c) 2015年 鲁蕴铖. All rights reserved.
////
///*
//#include <iostream>
//#include <opencv2/core/core.hpp>
//#include <opencv2/highgui/highgui.hpp>
//#include <opencv2/imgproc/imgproc.hpp>
//using namespace  std;
//using namespace cv;
//
//Mat srcimage,cloe,out;
//int g_nBilateralFilterValue=10;  //双边滤波参数值
//static void on_bilaterFilter(int , void *)
//{
////    void bilateralFilter(InputArray src, OutputArraydst, int d, double sigmaColor, double sigmaSpace, int borderType=BORDER_DEFAULT)
////    第一个参数，InputArray类型的src，输入图像，即源图像，需要为8位或者浮点型单通道、三通道的图像。
////    第二个参数，OutputArray类型的dst，即目标图像，需要和源图片有一样的尺寸和类型。
////    第三个参数，int类型的d，表示在过滤过程中每个像素邻域的直径。如果这个值我们设其为非正数，那么OpenCV会从第五个参数sigmaSpace来计算出它来。
////    第四个参数，double类型的sigmaColor，颜色空间滤波器的sigma值。这个参数的值越大，就表明该像素邻域内有更宽广的颜色会被混合到一起，产生较大的半相等颜色区域。
////    第五个参数，double类型的sigmaSpace坐标空间中滤波器的sigma值，坐标空间的标注方差。他的数值越大，意味着越远的像素会相互影响，从而使更大的区域足够相似的颜色获取相同的颜色。当d>0，d指定了邻域大小且与sigmaSpace无关。否则，d正比于sigmaSpace。
////    第六个参数，int类型的borderType，用于推断图像外部像素的某种边界模式。注意它有默认值BORDER_DEFAULT。
////
//    bilateralFilter(srcimage, out, g_nBilateralFilterValue, g_nBilateralFilterValue*2, g_nBilateralFilterValue/2);
//    imshow("双边滤波",out);
//}
//
//
//int main()
//{
//    srcimage=imread("/Users/luyuncheng/Downloads/opencvcnblogdemo/OpenCVdemo6/OpenCVdemo6/1.jpg");
//    if(!srcimage.data){
//        cout<<"no image data"<<endl;
//        return 0;
//    }
//    cloe=srcimage.clone();
//    namedWindow("双边滤波",1);
//    //第一个参数表示轨迹条名字，第二个窗口名字，
//    //第三个参数是整形的指针表示滑块的位置，创建时，滑块的初始位置就是变量的值
//    //第四个参数表示滑块的最大位置的值，最小值始终为0
//    //第五个参数这是一个回调函数的指针，每次滑块位置改变时，这个函数都会进行回调，并且这个函数原型必须为void(int , void *)其中第一个参数是轨迹条的位置，第二个参数是用户数据。如果是null则没有回调函数的调用
//    //第六个参数 void＊类型的userdata默认为0，是用户传給回调函数的数据，用来处理轨迹条事件，如果使用的第三个参数value实参时全局变量的话可以不管
//    //此方法知识创建一个轨迹条，当变化时候它调用回调函数来改变
//    createTrackbar("参数值", "双边滤波", &g_nBilateralFilterValue, 50,on_bilaterFilter);
//    on_bilaterFilter(g_nBilateralFilterValue, 0);
//    while(char(waitKey(1))!= 'q') {}
//}
//*/