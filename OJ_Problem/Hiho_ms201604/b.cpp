////
//// Created by 鲁蕴铖 on 16/4/6.
////
//
//#include<cstdio>
//#include<cstring>
//#include<algorithm>
//#include<iostream>
//#include<vector>
//#include<set>
//#include<map>
//#include<cmath>
//#include<queue>
//#include<sstream>
//#include<string>
//#include<bitset>
//#include<utility>
//#include<numeric>
//#include<assert.h>
//
//using namespace std;
//
//int str2i(string s) {
//    int num=0;
//    for(int i=0; i<s.size(); i++) {
//        num= num*10 + (s[i]-'0');
//    }
//    return num;
//}
//string change(int num) {
//    string ret = "";
//    while(num) {
//        int t = num%2;
//        ret.push_back(t+'0');
//        num/=2;
//    }
//    while(ret.size()<8){
//        ret.push_back('0');
//    }
//    reverse(ret.begin(),ret.end());
//    return ret;
//}
//string solve(string ip) {
//    int pos  = 0;
//    int pos2 = 0;
//    string num ;
//    int mask =-1;
//    while(pos < ip.size()) {
//        if(ip[pos]=='.')pos++;
//        pos2 = ip.find('.',pos);
//        if(pos2 != -1) {
//            string tmp = ip.substr(pos, pos2 - pos);
//            int nn = str2i(tmp);
////            cout << "tmp" << tmp << endl;
//            string tnum = change(nn);
//            pos = pos2;
//            num += tnum;
//        } else {
//            int pos3;
//            pos3 = ip.find('/',pos);
//            if(pos3 == -1) {
//                string tmp = ip.substr(pos,ip.size()-pos);
//                int nn = str2i(tmp);
////                cout << "tmp:" << tmp << endl;
//                string tnum = change(nn);
//                pos = pos2;
//                num += tnum;
//                break;
//            } else {
//                string tmp = ip.substr(pos,pos3-pos);
//                int nn = str2i(tmp);
////                cout<<"tmpend:"<<tmp<<endl;
//                string tnum = change(nn);
//                num += tnum;
//                string maskstring = ip.substr(pos3+1,ip.size()-pos3);
////                cout<<"mask:"<<maskstring<<endl;
//                mask = str2i(maskstring);
//                break;
//            }
//        }
//    }
//    if(mask==0) {
//        return "";
//    }if(mask == -1) {
//        return num;
//    } else {
//        return num.substr(0,mask);
//    }
////    cout<<num<<endl;
//}
//struct Trie
//{
//    Trie *next[2];
//    string v ;   //根据需要变化
//    int id;
//    Trie() {
//        next[0] = next[1] = NULL;
//        id = 0x3f3f3f3f;
//        v = "";
//    }
//};
//void createTrie(string str,Trie *root,string op,int idx)
//{
//
//    int len = str.size();
//    Trie *p = root;
//    if(len == 0) {
//        p->id = min(idx,p->id);
//        return;
//    }
////    cout<<"len:"<<len<<endl;
//    for(int i=0; i<len; ++i)
//    {
//        int id = str[i]-'0';
////        cout<<i<<" id:"<<id<<endl;
//        if(p->next[id] == NULL)
//        {
////            cout<<"new"<<endl;
//            Trie *q = new Trie();
//            p->next[id] = q;
//            p = q;
//        }
//        else
//        {
////            cout<<"exit"<<endl;
//            p = p->next[id];
//        }
//    }
////    cout<<"end create"<<endl;
//    p->v = op;
//    p->id = min(idx,p->id);
//}
//int findTrie(string str,Trie *root,int mx)
//{
//    int len = str.size();
//    string nofind = "notfind";
//    Trie *p = root;
//    int ret = 0x3f3f3f3f;
//    if(root->id >=0) ret = root->id;
//    for(int i=0; i<len; ++i)
//    {
//        int id = str[i]-'0';
//        p = p->next[id];
//        if(p == NULL)
//            break;
//        if(p->v.size()>0 || p->id<0x3f3f3f3f) {
//            ret = min(ret,p->id);
//        }
//    }
//    if(ret >= 0x3f3f3f3f)
//        return -1;
//    else
//        return ret;
//}
//void del(Trie *root) {
//    Trie *p = root;
//    if(p == NULL) return;
//    for(int i=0;i<2;i++) {
//        if(p->next[i]) {
//            del(p->next[i]);
//        }
//    }
//    delete(p);
//}
//int main()
//{
////    cout<<stoi("128")<<endl;
////    cout<<solve("128.127.4.1/1")<<endl;
//    ios::sync_with_stdio(false);
//    int n,m;
//    while(cin>>n>>m) {
//        map<int,string> mp;
//        Trie *root = new Trie();
//        string op,ip;
//        string mas="";
//        for(int i=0;i<n;i++) {
//            cin>>op>>ip;
//            string bin = solve(ip);
////            cout<<"ip: "<<bin<<" op:"<<op<<endl;
//            mp[i] = op;
//            createTrie(bin, root, op,i);
//        }
////        cout<<"splite"<<endl;
//        for(int i=0;i<m;i++) {
//            cin>>ip;
//            string ipp = solve(ip);
////            cout<<"ipp:"<<ipp<<endl;
//
//            int res = findTrie(ipp,root,n);
////            cout<<"res:"<<res<<endl;
//            if(res == -1 || mp.find(res) == mp.end()) {
//                cout<<"YES"<<endl;
//            } else {
//                if(mp[res]=="deny")
//                    cout<<"NO"<<endl;
//                else
//                    cout<<"YES"<<endl;
//            }
//        }
//        del(root);
//    }
//}
//
////   __typeof(val.begin()) it = val.begin();
////ios::sync_with_stdio(false);cout<<setprecision(30);