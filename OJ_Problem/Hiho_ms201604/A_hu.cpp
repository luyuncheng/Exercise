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
//#define rep(i,a,n) for (int i=a;i<n;i++)
//#define repn(i,a,n) for (int i=a;i<=n;i++)
//
//typedef long long LL;
//typedef unsigned long long ULL;
//
//const LL LINF = (1LL <<60);
//const int INF = 1 << 30;
//
//const int NS = 1010;
//const int MS = 19;
//const int MOD = 1000000007;
//const double PI = acos(-1.0);
//
//LL powmod(LL a,LL b) {LL res=1; a%=MOD; for(;b;b>>=1){if(b&1)res=res*a%MOD;a=a*a%MOD;}return res;}
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
//int n, p, h, w;
//int A[2000];
//
//bool isCan(int sz)
//{
//    int cnt = w / sz;
//    int pH = (h / sz) * p;
//    if(cnt <= 0 || pH <= 0) return false;
//    int sum = 0;
//   //     printf("cnt = %d pH  = %d\n", cnt, pH);
//    for(int i = 0; i < n; i++)
//    {
//        sum += (A[i] + cnt - 1) / cnt;
//    }
//    return bool(sum <= pH);
//}
//
//int solve()
//{
//    int low = 1, high = 10000000;
//    for(int t = 0; t < 100; t++)
//    {
//      //  printf("l = %d h = %d\n", low, high);
//        int mid = (low + high) / 2;
//        if(isCan(mid))
//        {
//            low = mid;
//        }
//        else
//        {
//            high = mid - 1;
//        }
//    }
//    int L = max(1, low - 5);
//    int R = high + 5;
//    for(int i = R; i >= L; i--)
//    {
//        if(isCan(i)) return i;
//    }
//    return low;
//}
//
//int main()
//{
//#ifndef ONLINE_JUDGE
//    freopen("A.in", "r", stdin);
////    freopen("test.out", "w", stdout);
//#endif
//    int nCase;
//    scanf("%d", &nCase);
//    for(int nT = 1; nT <= nCase; nT++)
//    {
//        scanf("%d%d%d%d", &n, &p, &w, &h);
//        for(int i = 0; i < n; i++)
//        {
//            scanf("%d", &A[i]);
//        }
//        int ans = solve();
//        printf("%d\n", ans);
//    }
//    return 0;
//}
//
//
////   __typeof(val.begin()) it = val.begin();
////ios::sync_with_stdio(false);cout<<setprecision(30);
