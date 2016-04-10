////
//// Created by 鲁蕴铖 on 16/4/9.
////
//
//#include <iostream>
//#include <cstring>
//#include <queue>
//#include <vector>
//using namespace std;
//int main()
//{
////#ifndef ONLINE_JUDGE
//    freopen("/Users/luyuncheng/ClionProjects/CPP_lyc/OJ_Problem/GCJ2016/B-large.in", "r", stdin);
//    freopen("/Users/luyuncheng/ClionProjects/CPP_lyc/OJ_Problem/GCJ2016/B-large.out", "w", stdout);
////#endif
//    int T;
//    while(cin>>T) {
//        int cas = 0;
//        while(T--) {
//
//            string str;
//            cin>>str;
//            int con = 0;
//            char pre = str[0];
//            int bz = 0;
//            for(int i=1;i<str.size();i++) {
//                if(str[i] == pre) continue;
//                else {
//                    con ++ ;
//                    pre = str[i];
//                }
//            }
//            if(pre == '-') con++;
//
//            cout << "Case #" << ++cas << ": "<< con << endl;
//        }
//    }
//}