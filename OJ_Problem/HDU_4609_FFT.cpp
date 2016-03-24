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
////
//void fft (vector<comp> &y,int len,int on=1)
//{
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
//
//const int maxn = 400040;
//vector<comp> x1;
//int a[maxn/4];
//long long num[maxn];
//long long sum[maxn];
//
//int main()
//{
//    int T,n;
//    cin>>T;
//    while(T--)
//    {
//        cin>>n;
//        memset(num,0, sizeof(num));
//        for(int i=0; i<n; i++) {
//            cin>>a[i];
//            num[a[i]]++;
//        }
//        sort(a,a+n);
//        int len1 = a[n-1]+1;
//        int len = 1;
//        while(len < 2*len1)
//            len <<=1;
//        x1.clear();
//        x1.resize(len,comp(0,0));
//        for(int i=0; i<len1; i++) {
//            x1[i] = comp(num[i],0);
//        }
//        fft(x1,len,1);
//        for(int i=0;i<len;i++)
//            x1[i] = x1[i]*x1[i];
//        fft(x1,len,-1);
//        for(int i = 0;i < len;i++)
//            num[i] = (long long)(x1[i].real()+0.5);
//        len = 2*a[n-1];
//        // 减去两个相同的组合
//        for(int i=0; i<n; i++) {
//            num[a[i]+a[i]]--;
//        }
////        选择的无序 /2
//        for(int i=1;i<=len;i++) {
//            num[i]/=2;
//        }
//        sum[0] = 0;
//        for(int i=1; i<=len; i++) {
//            sum[i] = sum[i-1] + num[i];
//        }
//        long long cnt = 0;
//        for(int i=0; i<n; i++) {
//            cnt += sum[len] - sum[a[i]];
//            cnt-= (long long) (n-1-i)*i;
//            cnt -= (n-1);
//            cnt -= (long long) (n-1-i)*(n-i-2)/2;
//        }
//        long long tot = (long long) n*(n-1)*(n-2)/6;
//        printf("%.7lf\n",(double)cnt/tot);
//    }
//}