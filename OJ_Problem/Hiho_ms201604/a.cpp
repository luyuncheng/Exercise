////
//// Created by 鲁蕴铖 on 16/4/6.
////
//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <cstdio>
//#include <cmath>
//#include <map>
//#include <set>
//
//int n,w,h,p;
//const int maxn = 2000;
//int a[maxn];
//using namespace std;
//int main()
//{
//    int T;
//    cin>>T;
//    while(T--) {
//        cin>>n>>p>>w>>h;
//        memset(a,0,sizeof(a));
//        for(int i=0;i<n;i++) {
//            cin>>a[i];
//        }
//        int l = 0, r = p*h;
//        while(l<r) {
//            int s = (l+r)/2;
//
//            int line = w/s;
//            int page = h/s;
//            int lines = 0;
//            for(int i=0;i<n;i++) {
//                lines += ceil((a[i]*1.0)/(line*1.0));
//            }
//            if(ceil((lines*1.0)/(1.0*page)) <= p) {
//                l = s;
//                cout<<"l:"<<l<<" r:"<<r<<endl;
//            }else {
//                r = s-1;
//                cout<<"r:"<<r<<" l:"<<l<<endl;
//            }
//
//        }
//        cout<<l<<endl;
//    }
//}
