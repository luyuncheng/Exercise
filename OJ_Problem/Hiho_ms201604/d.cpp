////
//// Created by 鲁蕴铖 on 16/4/7.
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
//#ifndef ONLINE_JUDGE
//const int NS = 4;
//#else
//const int NS = 100;
////    freopen("test.out", "w", stdout);
//#endif
//const int MS = 100010;
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
//int n, X[MS], Y[MS], Z[MS];
//int dp[NS + 2][NS + 2][NS + 2];
//
//void initData()
//{
//    memset(dp, 0x3f, sizeof(dp));
//    int lim = NS;
//    for(int i = 1; i <= lim; i++)
//    {
//        for(int j = 1; j <= lim; j++)
//        {
//            dp[i][j][0] = -1;
//            memset(dp[i][j] + 1, 0, sizeof(int) * lim);
//            // printf("dp[i][j][0] = %d\n", dp[i][j][0]);
////            for(int k = 1; k <= lim; k++)
////            {
////            }
//        }
//    }
//}
//
//struct Point
//{
//    int x, y, z;
//    Point() {};
//    Point(int _x, int _y, int _z)
//    {
//        x = _x, y = _y, z = _z;
//    }
//};
//queue<Point> que;
//
//bool isInMap(Point cur)
//{
//    return bool(cur.x <= NS && cur.x >= 1
//                && cur.y <= NS && cur.y >= 1
//                && cur.z <= NS && cur.z >= 1
//    );
//}
//
//int dir[6][3] = {{0, 0, 1}, {0, 0, -1}, {0, 1, 0}, {0, -1, 0}, {1, 0, 0}, {-1, 0, 0}};
//bool bfs(int id)
//{
//    Point nxt, cur;
//    while(!que.empty()) que.pop();
//    que.push( Point(X[id], Y[id], Z[id]) );
//
//    // printf("bfs::id = %d(%d, %d, %d)\n", id, X[id], Y[id], Z[id]);
//    while(!que.empty())
//    {
//        cur = que.front();
//        que.pop();
//        for(int di = 0; di < 6; di++)
//        {
//            nxt = Point(cur.x + dir[di][0], cur.y + dir[di][1], cur.z + dir[di][2]);
//            int val = dp[nxt.x][nxt.y][nxt.z];
//            if(val > id)
//            {
//                //       printf("(%d, %d, %d) val = %d\n", nxt.x, nxt.y, nxt.z, val);
//                return true;
//            }
//            else if(0 == val)
//            {
//                dp[nxt.x][nxt.y][nxt.z] = id;
//                if(isInMap(nxt))
//                {
//                    que.push(nxt);
//                }
//            }
//        }
//    }
//    return false;
//}
//
//int main()
//{
//#ifndef ONLINE_JUDGE
//    freopen("D.in", "r", stdin);
////    freopen("test.out", "w", stdout);
//#endif
//    int nCase;
//    scanf("%d", &nCase);
//    for(int nT = 1; nT <= nCase; nT++)
//    {
//        scanf("%d", &n);
//        initData();
//        bool ans = true;
//
//        for(int i = 1; i <= n; i++)
//        {
//            scanf("%d%d%d", &X[i], &Y[i], &Z[i]);
//            if(dp[X[i]][Y[i]][Z[i]] >= 1 && dp[X[i]][Y[i]][Z[i]] <= n)
//            {
//                ans = false;
//            }
//            else
//            {
//                dp[X[i]][Y[i]][Z[i]] = i;
//            }
//            bool fv = false;
//            if(1 == Z[i])
//            {
//                fv = true;
//            }
//            else
//            {
//                for(int di = 0; di < 6; di++)
//                {
//                    int nx = X[i] + dir[di][0];
//                    int ny = Y[i] + dir[di][1];
//                    int nz = Z[i] + dir[di][2];
//                    if((dp[nx][ny][nz] >= 1 && dp[nx][ny][nz] <= n) )
//                    {
//                        fv = true;
//                        break;
//                    }
//                }
//            }
//            ans &= fv;
//        }
//        for(int i = n; ans && i >= 1; i--)
//        {
//            if( !bfs(i) )
//            {
//                //     printf("ans::i = %d\n", i);
//                ans = false;
//                break;
//            }
//        }
//        puts(ans? "Yes" : "No");
//    }
//    return 0;
//}
//
//
////   __typeof(val.begin()) it = val.begin();
////ios::sync_with_stdio(false);cout<<setprecision(30);
