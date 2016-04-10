////
//// Created by 鲁蕴铖 on 16/4/9.
////
//
//#pragma comment(linker, "/STACK:1024000000,1024000000")
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
//#define rep(i,a,n) for (int i=a;i<n;i++)
//#define repn(i,a,n) for (int i=a;i<=n;i++)
//
//typedef long long LL;
//typedef unsigned long long ULL;
//
//const LL LINF = (1LL <<60);
//const int INF = 1 << 30;
//
//const int NS = 21;
//const int MS = NS + 1;
//const int MOD = 1000000007;
//const double PI = acos(-1.0);
//
//#define form(_i, L, R) for (int (_i) = L; (i) <= (R); ++(_i))
//inline bool isdigit(char ch){return ((ch<='9')and(ch>='0'));}
//inline void read(int &x){
//    char ch;
//    bool flag=false;
//    for (ch=getchar();!isdigit(ch);ch=getchar()) if (ch=='-') flag=true;
//    for (x=0;isdigit(ch);x=x*10+ch-'0',ch=getchar());
//    x=flag?-x:x;
//}
//
//int n;
//char str[NS + 10];
//int dp[MS][(1 << NS) + 5];
//
//int getNext(int cur, int len)
//{
//    int nxt = cur;
//    int mL, mR;
//    int L = 0, R = len - 1;
//    while(L < R)
//    {
//        mL = (cur >> L) & 1;
//        mR = (cur >> R) & 1;
//        if(mL == mR)
//        {
//            nxt ^= (1 << L);
//            nxt ^= (1 << R);
//        }
//        L++, R--;
//    }
//    if(L == R)
//    {
//        nxt ^= (1 << L);
//    }
//    return nxt;
//}
//
//string transto2(int x)
//{
//    return (bitset<NS>(x)).to_string();
//}
//
//queue<int> que;
//int solve(char* sk)
//{
//    n = strlen(sk);
//    int cx = 0;
//    for(int i = 0; i < n; i++)
//    {
//        if('+' == sk[i])
//        {
//            cx |= (1 << i);
//        }
//    }
//    if(-1 != dp[n][cx]) dp[n][cx];
////    cout<<"n = "<<n<<" cx = "<<transto2(cx)<<endl;
//    int res = ((1 << n) - 1);
//
//    while(!que.empty()) que.front();
//    dp[n][res] = 0;
//    que.push( res );
//
//    int nxt, cur;
//    while(!que.empty())
//    {
//        cur = que.front(); que.pop();
//        int step = dp[n][cur];
//        //   cout<<"cur = "<<transto2(cur)<<endl;
//        for(int i = 1; i <= n; i++)
//        {
//            nxt = getNext(cur, i);
//            //       cout<<"i = "<<i<<" nxt = "<<transto2(nxt)<<endl;
//            if(-1 == dp[n][nxt])
//            {
//                dp[n][nxt] = step + 1;
//                que.push(nxt);
//            }
//        }
//    }
//    return dp[n][cx];
//}
//
//int main()
//{
//    memset(dp, -1, sizeof(dp));
//    freopen("/Users/luyuncheng/ClionProjects/CPP_lyc/OJ_Problem/GCJ2016/Blarge.in", "r", stdin);
//    freopen("/Users/luyuncheng/ClionProjects/CPP_lyc/OJ_Problem/GCJ2016/Blarge_force.out", "w", stdout);
//    int nCase;
//    while(cin>>nCase)
//    {
//        for(int nT = 1; nT <= nCase; nT++)
//        {
//            scanf("%s", str);
//            int ans = solve(str);
//            cout<<"Case #"<<nT<<": "<<ans<<endl;
//        }
//    }
//    return 0;
//}
//
//
////   __typeof(val.begin()) it = val.begin();
////ios::sync_with_stdio(false);
////cout<<setprecision(30);
