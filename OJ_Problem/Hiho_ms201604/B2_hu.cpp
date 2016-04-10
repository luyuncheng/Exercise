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
//const int NS = 110;
//const int MS = 19;
//const int MOD = 1000000007;
//const double PI = acos(-1.0);
//
//LL powmod(LL a,LL b)
//{
//    LL res=1;
//    a%=MOD;
//    for(; b; b>>=1)
//    {
//        if(b&1)res=res*a%MOD;
//        a=a*a%MOD;
//    }
//    return res;
//}
//
//#define form(_i, L, R) for (int (_i) = L; (i) <= (R); ++(_i))
//inline bool isdigit(char ch)
//{
//    return ((ch<='9')and(ch>='0'));
//}
//inline void read(int &x)
//{
//    char ch;
//    bool flag=false;
//    for (ch=getchar(); !isdigit(ch); ch=getchar()) if (ch=='-') flag=true;
//    for (x=0; isdigit(ch); x=x*10+ch-'0',ch=getchar());
//    x=flag?-x:x;
//}
//
//int n, m;
//set< pair<LL, int> > mask[NS][2];
//char op[NS], ips[NS];
//
//pair<LL, int> ipHandle(char str[NS])
//{
//   // printf("%s\n", str);
//    LL val = 0;
//    int be = 32;
//    int sLen = strlen(str);
//    int tmp = 0, ismask = 0;
//    for(int j = 0; j < sLen; j++)
//    {
//        if('.' == str[j] || '/' == str[j])
//        {
//        //    printf("%d%c", tmp, str[j]);
//            val <<= 8;
//            val += tmp;
//            tmp = 0;
//            if('/' == str[j])
//            {
//                ismask = 1;
//            }
//        }
//        else
//        {
//            tmp = tmp * 10 + (str[j] - '0');
//        }
//    }
//   // printf("%d\n", tmp);
//    if(ismask)
//    {
//        val >>= (32 - tmp);
//        be = tmp;
//        tmp = 0;
//    }
//    else
//    {
//        val <<= 8;
//        val += tmp;
//    }
//
//    return make_pair(val, be);
//}
//
//int solve()
//{
//
//}
//
//int main()
//{
//#ifndef ONLINE_JUDGE
//    freopen("B.in", "r", stdin);
////    freopen("test.out", "w", stdout);
//#endif
//    while(~scanf("%d %d", &n, &m))
//    {
//        for(int i = 0; i <= 32; i++)
//        {
//            mask[i][0].clear();
//            mask[i][1].clear();
//        }
//
//        for(int i = 0; i < n; i++)
//        {
//            scanf("%s %s", op, ips);
//            int fv = 'd' == op[0]? 1 : 0;
//            pair<LL, int> mpk = ipHandle(ips);
//            LL val = mpk.first;
//            int be = mpk.second;
//            mask[be][fv].insert( make_pair(val, i) );
//     //       printf("%I64d %d\n", mpk.first, mpk.second);
//        }
//
//        for(int i = 0; i < m; i++)
//        {
//            scanf("%s", ips);
//            pair<LL, int> mpk = ipHandle(ips);
//            LL val = mpk.first;
//
//            int ans = INF, fv = 0;
//            for(int j = 0; j <= 32; j++)
//            {
//                pair<LL, int> fd = make_pair((val >> (32 - j)), -1);
//                set< pair<LL, int> >::iterator it = mask[j][0].lower_bound(fd);
//                if(it != mask[j][0].end() && it->first == fd.first)
//                {
//             //       printf("0:id = %d\n", it->second);
//                    if(it->second < ans)
//                    {
//                        ans = it->second;
//                        fv = 0;
//                    }
//                }
//
//                it = mask[j][1].lower_bound(fd);
//                if(it != mask[j][1].end() && it->first == fd.first)
//                {
//                 //   printf("1:id = %d\n", it->second);
//                    if(it->second < ans)
//                    {
//                        ans = it->second;
//                        fv = 1;
//                    }
//                }
//            }
//            if(!fv)
//            {
//                printf("YES\n");
//            }
//            else
//            {
//                printf("NO\n");
//            }
//
//        }
//    }
//    return 0;
//}
//
//
////   __typeof(val.begin()) it = val.begin();
////ios::sync_with_stdio(false);cout<<setprecision(30);
