////
//// Created by 鲁蕴铖 on 16/4/16.
////
//#include <iostream>
//#include <cstdio>
//#include <cmath>
//#include <cstdlib>
//#include <thread>
//#include <random>
//#include <set>
//using namespace std;
//set<string>  st;
//string str;
//
//void solve(string s,int pos) {
////    cout<<"s:"<<s<<endl;
//    if(s.size() == str.size()) {
//        st.insert(s);
//        return;
//    }
//    string tmp = s;
//    if(str[pos] >= s[0]) {
//        tmp.insert(tmp.begin(),1,str[pos]);
//    } else {
//        tmp.push_back(str[pos]);
//    }
////    string tmp1 = s;
////    tmp1.push_back(str[pos]);
//////    cout<<tmp1<<endl;
////    string tmp2 = s;
////    tmp2.insert(tmp2.begin(),1,str[pos]);
//////    cout<<tmp
//    solve(tmp,pos+1);
////    solve(tmp2,pos+1);
//}
//int main()
//{
//////#ifndef ONLINE_JUDGE
////    freopen("/Users/luyuncheng/Downloads/A-large.in", "r", stdin);
////    freopen("/Users/luyuncheng/Downloads/A-large.out", "w", stdout);
//////#endif
//    int T;
//    while(cin>>T) {
//        int cas = 1;
//        while(T--) {
//            st.clear();
//            cin>>str;
//            string tmp;
//            tmp.push_back(str[0]);
//            solve(tmp,1);
//            cout << "Case #" << cas++ <<": ";
//            auto it = st.end();
//            it--;
//            cout<<*it<<endl;
//        }
//    }
//}