////
//// Created by 鲁蕴铖 on 16/3/20.
////
//
//#include <iostream>
//#include <cstdio>
//#include <cstring>
//#include <set>
//#include <map>
//#include <algorithm>
//#include <vector>
//using namespace std;
//typedef set<int> se;
//multimap <int,pair<se,int>> dp[50];
//int main()
//{
//    int n;
//    while(cin>>n)
//    {
//        vector<int> a;
//        for (int i = 0; i < n; i++) {
//            int tmp=1;
//            cin >> tmp;
//            a.push_back(tmp);
//        }
//        sort(a.begin(), a.end());
//        int midpos = a.size()/2;
//        int mid;
//        if (midpos % 2 == 0) {
//            mid = (a[midpos] + a[midpos - 1]);
//        } else {
//            mid = a[midpos];
//        }
//        //cout<<"mid:"<<mid<<endl;
//        se zero;zero.insert(-1);
//        dp[0].insert(make_pair(0, make_pair(zero,0)));
//        int ans = 0;
//        for (int i = 1; i <= n; i++)
//        {
//            for (auto it = dp[i - 1].begin(); it != dp[i - 1].end(); it++)
//            {
//                for (int j = 0; j < n; j++)
//                {
//                    if(it->second.first.count(j)==0)
//                    {
//
//                        if ( (a[j] + it->first)/i <= mid)
//                        {
//                            int tmp = a[j] + it->first;
//                            int con = it->second.second;
//                            if (dp[i].find(tmp) != dp[i].end())
//                            {
//                                auto it3 = dp[i].find(tmp);
//                                for(;it3!=dp[i].end() && it3->first == tmp;it3++) {
//                                    if(it3->second.first.count(j)==0) {
//                                        auto it4 = it3;
//                                        it4->second.second += 1;
//                                        ans = max(it4->second.second, ans);
//                                        it4->second.first.insert(j);
//                                    }
//                                }
//                            } else {
//                                ans = max(ans,con+1);
//                                se tset;
//                                tset.insert(j);
//                                dp[i].insert(make_pair(tmp, make_pair(tset,con+1)));
//                            }
//                        }
//                    }
//                }
//            }
//        }
//        ans = 0;
//        for(int i=1;i<=n;i++) {
//            ans += dp[i].size();
////            cout<<"i:"<<i<<" :"<<dp[i].size()<<endl;
//        }
//        cout<< ans<<endl;
//    }
//}
//
