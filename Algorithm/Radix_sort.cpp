////
//// Created by 鲁蕴铖 on 16/4/7.
////
//
//#include<iostream>
//#include <vector>
//using namespace std;
//const int maxn = 1000;
//int a[maxn];
//int b[maxn][2];
//vector<pair<int,int> > c[10];
//int main() {
//    int n;
//    // d为基 如果为10 那么复杂度不对,d进制应该是最接近n的2的整数次幂 是最好的,这样用n来做基底,那么算法复杂度o 就是线性的
//    while (cin >> n) {
//        for (int i = 0; i < n; i++) {
//            cin>>a[i];
//        }
//        // allocate
//        int mx = 0;
//        for(int i=0; i<n; i++) {
//            int tmp = a[i]%10;
//            c[tmp].push_back(make_pair(a[i],a[i]/10));
//            mx = max(mx,a[i]/10);
//        }
//        // sort
//        while(mx>0) {
//            mx = 0;
//            int con = 0;
//            for (int i = 0; i < 10; i++) {
//                for (int j = 0; j < c[i].size(); j++) {
//// [0]为a[i] [1]为除数(方便计算)
//                    b[con][0] = c[i][j].first;
//                    b[con][1] = c[i][j].second;
//                    con++;
//                }
//            }
//            for(int i=0; i < 9; i++) c[i].clear();
//
//            for(int i=0; i < n; i++) {
//                int tmp = b[i][1]%10;
//                c[tmp].push_back(make_pair(b[i][0],b[i][1]/10));
//                mx = max(mx,b[i][1]/10);
//            }
//        }
//        int con = 0;
//        for (int i = 0; i < 10; i++) {
//            for (int j = 0; j < c[i].size(); j++) {
//
//                b[con][0] = c[i][j].first;
//                b[con][1] = c[i][j].second;
//                con++;
//            }
//        }
//        for(int i=0; i<n; i++) {
//            cout<<b[i][0]<<" ";
//        }
//    }
//}