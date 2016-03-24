////
//// Created by 鲁蕴铖 on 16/3/19.
////
//
//#include <iostream>
//#include <cmath>
//#include <vector>
//using namespace std;
//
//const double pi = acos(-1.0);
//const double e = exp(1);
//int RECURSVE_FFT(vector<int> &a)
//{
//    int n = a.size();
//    if (n == 1) return a;
//    double alpha = 2.0*pi/((double)n);
//    vector<int> a0,a1;
//    for(int i=0; i < n; i++) {
//        if(a[i] & 0x01) // odd
//            a1.push_back(a[i]);
//        else //even
//            a0.push_back(a[i]);
//    }
//    RECURSVE_FFT(a0);
//    RECURSVE_FFT(a1);
//
//    for(int k = 0;k<=n/2-1;k++) {
//        y[k]= y
//    }
//}
//
//
//int DFT(int dir, int m, double *x1, double *y1) {
//    long i, k;
//    double arg;
//    double cosarg, sinarg;
//    double *x2 = NULL, *y2 = NULL;
//    x2 = malloc(m * sizeof(double));
//    y2 = malloc(m * sizeof(double));
//    if (x2 == NULL || y2 == NULL)return (false);
//    for (i = 0; i < m; i++) {
//        x2[i] = 0;
//        y2[i] = 0;
//        arg = -dir * 2.0 * 3.141592654 * (double) i / (double) m;
//        for (k = 0; k < m; k++) {
//            cosarg = cos(k * arg);
//            sinarg = sin(k * arg);
//            x2[i] += (x1[k] * cosarg - y1[k] * sinarg);
//            y2[i] += (x1[k] * sinarg + y1[k] * cosarg);
//        }
//    }
///*Copythedataback*/
//    if (dir == 1) {
//        for (i = 0; i < m; i++) {
//            x1[i] = x2[i] / (double) m;
//            y1[i] = y2[i] / (double) m;
//        }
//    }
//    else {
//        for (i = 0; i < m; i++) {
//            x1[i] = x2[i];
//            y1[i] = y2[i];
//        }
//    }
//    free(x2);
//    free(y2);
//    return (true);
//}