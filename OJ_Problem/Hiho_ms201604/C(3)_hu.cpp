//#include<cstdio>
//#include<cstring>
//#include<algorithm>
//#include<iostream>
//#include<vector>
//#include<set>
//#include<map>
//#include<cmath>
//#include<queue>
//
//using namespace std;
//
//
//
//
//int n, m;
//bool mp[110][110];
//char str[110];
//int dp[110][110][2];
//
//bool isInMap(int x, int y)
//{
//    return (x >= 1 && x <= n && y >= 1 && y <= m);
//}
//
//int solve()
//{
//    if(1 == n && 1 == m) return 0;
//
//    memset(dp, INF, sizeof(dp));
//   // printf("%d %d\n", dp[0][0][0], INF);
//
//    dp[1][1][1] = 0;//(false == mp[1][1]? 1 : 0);//����
//  //  mp[1][1] = true;
//    for(int row = 1; row <= n; row++)
//    {
//        for(int col = 1; col <= m; col++)
//        {
//            for(int dir = 0; dir <= 1; dir++)
//            {
//                if(dp[row][col][dir] >= INF) continue;
//
//          //      printf("row = %2d col = %2d dir = %d\n", row, col, dir);
//                int lim, val = dp[row][col][dir];
//                int dx, dy, curd = 1 ^ dir;
//                if(0 == curd)
//                {
//                    lim = m;
//                    dx = 0, dy = 1;
//                }
//                else
//                {
//                    lim = n;
//                    dx = 1, dy = 0;
//                }
//                int fv, nx, ny, px = row, py = col, cnt = 0;
//                while(isInMap(px, py))
//                {
//                    nx = px + dx, ny = py + dy;
//                    if(isInMap(nx, ny) && mp[nx][ny]) fv = 1;
//                    else fv = 0;
//
//                    dp[px][py][curd] = min(dp[px][py][curd], val + fv + cnt);
//
//                    px = nx, py = ny;
//                    if(!mp[px][py]) cnt++;
//                }
//            }
//        }
//    }
//
//    for(int row = 1; row <= n; row++)
//    {
//        for(int col = 1; col <= m; col++)
//        {
//            for(int dir = 0; dir <= 1; dir++)
//            {
//                if(dp[row][col][dir] >= INF) continue;
//
//          //      printf("row = %2d col = %2d dir = %d\n", row, col, dir);
//                int lim, val = dp[row][col][dir];
//                int dx, dy, curd = 1 ^ dir;
//                if(0 == curd)
//                {
//                    lim = m;
//                    dx = 0, dy = 1;
//                }
//                else
//                {
//                    lim = n;
//                    dx = 1, dy = 0;
//                }
//                int fv, nx, ny, px = row, py = col, cnt = 0;
//                while(isInMap(px, py))
//                {
//                    nx = px + dx, ny = py + dy;
//                    if(isInMap(nx, ny) && mp[nx][ny]) fv = 1;
//                    else fv = 0;
//
//                    dp[px][py][curd] = min(dp[px][py][curd], val + fv + cnt);
//
//                    px = nx, py = ny;
//                    if(!mp[px][py]) cnt++;
//                }
//            }
//        }
//    }
//
//    return min(dp[n][m][0], dp[n][m][1]);
//}
//
//int main()
//{
//    while(~scanf("%d %d", &n, &m))
//    {
//        memset(mp, false, sizeof(mp));
//        for(int row = 1; row <= n; row++)
//        {
//            scanf("%s", str + 1);
//            for(int col = 1; col <= m; col++)
//            {
//                mp[row][col] = (str[col] == '.'? true : false);
//            }
//        }
//
//        int ans = solve();
//        printf("%d\n", ans);
//    }
//    return 0;
//}
//
