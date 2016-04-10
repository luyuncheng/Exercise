////
//// Created by 鲁蕴铖 on 16/4/9.
////
//
//#include <iostream>
//#include <cstdio>
//#include <cstring>
//#include <set>
//using  namespace std;
//
//long long T,RN;
//
//int main()
//{
////#ifndef ONLINE_JUDGE
//    freopen("/Users/luyuncheng/ClionProjects/CPP_lyc/OJ_Problem/GCJ2016/A-large.in", "r", stdin);
//    freopen("/Users/luyuncheng/ClionProjects/CPP_lyc/OJ_Problem/GCJ2016/A-large.out", "w", stdout);
////#endif
//    while(cin>>T) {
//
//        int cas = 1;
//        while (T--) {
//            cin >> RN;
////            if (RN > INT_MAX) cout << "input out:" << RN << endl;
//            set<long long> s;
//            s.clear();
//            long long k = 1;
//            long long N = RN;
////            long long con = 0;
//            long long res = 0;
//            int flag = 0;
//            while (s.size() < 10) {
//                long long num = N;
//                while (num && s.size() < 10) {
//                    long long tmp = num % 10;
////                cout<<"N:"<<N<<" tmp:"<<tmp<<endl;
//                    s.insert(tmp);
////                    con++;
//                    num /= 10;
//                }
//                res = N;
//                N = RN * (++k);
//                if (k > 1000000 || RN == 0) {
//                    flag = 1;
//                    break;
//                }
////                if (N > INT_MAX) cout << "out:" << RN << endl;
//            }
//            if (flag) {
//                cout << "Case #" << cas++ << ": INSOMNIA" << endl;
//            } else {
//                cout << "Case #" << cas++ << ": " << res << endl;
//            }
////        cout<<"N:"<<RN<<" con:"<<con<<" res:"<<res<<endl;
//
//        }
//    }
//}