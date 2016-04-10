////
//// Created by 鲁蕴铖 on 16/4/9.
////
//
//#include <iostream>
//#include <string>
//#include <ctime>
//using  namespace std;
//int con = 0 ;
//void dfs(string s,int pos) {
//    if(pos >= s.size()) {
//        con++;
//        cout<<s<<endl;
//        return;
//    }
//    string tmp = s;
//
//    tmp[pos]='-';
////    cout<<tmp<<endl;
//    dfs(tmp,pos+1);
//    tmp[pos]='+';
////    cout<<tmp<<endl;
//    dfs(tmp,pos+1);
//}
//int main() {
//
//    freopen("/Users/luyuncheng/ClionProjects/CPP_lyc/OJ_Problem/GCJ2016/Blarge.in", "w", stdout);
////    freopen("/Users/luyuncheng/ClionProjects/CPP_lyc/OJ_Problem/GCJ2016/Blarge_hu.out", "w", stdout);
//    int T = 1<<20;
//    cout<<T<<endl;
////    srand(time(0));
//
//    string s = "--------------------";
//    {
//        string str = s;
//        dfs(s,0);
//        if(con == (1<<20)) cout<<"YEs"<<endl;
//    }
//}