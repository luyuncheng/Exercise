////
//// Created by 鲁蕴铖 on 16/6/6.
////
//#include <iostream>
//#include <algorithm>
//#include <cmath>
//using namespace std;
//const int maxn = 1010;
//int dp[maxn];
//
//struct node {
//    int w,v; // w weight v value
//} a[maxn];
//int cmp(node a1, node a2) {
//    return (a1.v/a1.w) > (a2.v/a2.w);
//}
////t 背包承重, m 物体数量
//void pack01(int t, int m) {
//
//    for(int i=1; i<=m; i++){
//        for(int j=t; j>=a[i].w; j--){
//            dp[j]=max(dp[j-a[i].w]+a[i].v, dp[j]);
//        }
//    }
//
//    printf("%d\n",dp[t]);
//}
//void partpack(int t, int m) {
//
//    sort(a+1, a+m+1, cmp);
//    int v = 0;
//    for(int i=0; i<m; i++) {
//        if(a[i].w < t) {
//            t-=a[i].w; v+=a[i].v;
//        } else {
//            v += (a[i].v/a[i].w)*t; t = 0; break;
//        }
//    }
//    printf("%d\n",v);
//}
//
//int main(){
//    int t,m;
//    memset(dp,0,sizeof(dp));
//    scanf("%d %d",&t,&m);
//
//    for(int i=1; i<=m; i++)
//        scanf("%d %d",&a[i].w,&a[i].v);
//    //pack01(t,m);
//    partpack(t,m);
//    printf("\n");
//    return 0;
//}