////
//// Created by 鲁蕴铖 on 16/4/16.
////
//
//#include <iostream>
//#include <cstdio>
//#include <cmath>
//#include <cstdlib>
//#include <thread>
//#include <random>
//#include <queue>
//#include <set>
//using namespace std;
//int n;
//int a[110][100];
//int vis[100];
//int mp[110][100];
//queue<int> que;
//int con[3000];
//int main()
//{
//////#ifndef ONLINE_JUDGE
//    freopen("/Users/luyuncheng/Downloads/B-large.in", "r", stdin);
//    freopen("/Users/luyuncheng/Downloads/B-large.out", "w", stdout);
//////#endif
//    int T;
//    while(cin>>T) {
//        int cas = 1;
//        while(T--) {
//            cin>>n;
//            memset(a,0,sizeof(a));
//            memset(vis,0,sizeof(vis));
//            memset(con,0,sizeof(con));
//            int mi = 3000,miid;
//            for(int i = 0; i<2*n-1; i++) {
//                for (int j = 0; j < n; j++) {
//                    cin >> a[i][j];
//                    con[a[i][j]]++;
//                }
//                if(a[i][0] < mi) {
//                    mi = a[i][0];
//                    miid = i;
//                }
//            }
//
//            cout << "Case #" << cas++ <<":";
//            for(int i = 0; i<3000;i++) {
//                if(con[i]%2 == 1)
//                    cout<<" "<<i;
//            }
//            cout<<endl;
//
//        }
//    }
//}