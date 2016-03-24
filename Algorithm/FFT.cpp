////
//// Created by 鲁蕴铖 on 16/3/20.
////
//
//#include <cstdio>
//#include <iostream>
//#include <cstring>
//#include <algorithm>
//#include <cmath>
//#include <complex>
//#include <vector>
//using namespace std;
//
//const double PI = acos(-1.0);
//typedef complex<double> comp;
////
////进行反转操作
////位置i和反转后的位置互换
////len必须是2的幂次
////
//void change (vector<comp> &y,int len)
//{
//    for(int i=1, j = len/2,k; i<len-1; i++) {
//        if(i<j) swap(y[i],y[j]);
//        //交换互为小标反转的元素，i<j保证交换一次
//        //i做正常的+1，j左反转类型的+1,始终保持i和j是反转的
//        k = len / 2;
//        while(j>=k) {
//            j-=k;
//            k/=2;
//        }
//        if(j < k)
//            j += k;
//    }
//}
////
////做FFT
////len必须为2^k形式，
////on==1时是DFT，on==-1时是IDFT
////x in , y out
////
//void fft (vector<comp> &y,vector<comp> &x,int len,int on=1)
//{
//    y.resize(2*len,comp(0,0));
//    for(int i=0;i<len;i++)
//        y[i]=x[i];
//    change(y,len);
//    for(int h = 2; h<=len; h<<=1) // 树的层数
//    {
//        comp wn(cos(-on*2*PI/h),sin(-on*2*PI/h));
//        for(int j = 0; j < len; j+=h)
//        {
//            comp w(1,0);
//            for(int k = j; k< j+h/2; k++)
//            {
//                comp u = y[k];
//                comp t = w*y[k+h/2];
//                y[k] = u+t;
//                y[k+h/2] = u-t;
//                w = w*wn;
//            }
//        }
//    }
//    if(on == -1)
//        for(int i=0;i<len;i++)
//            y[i]=comp(y[i].real()/len,y[i].imag());
//}
//void fft2d(vector<comp> &y,vector,int numRows, int numColls)
//{
//
//}
//const int maxn = 400040;
//vector<comp> x1;
//
//int main()
//{
//}