////
//// Created by 鲁蕴铖 on 16/4/7.
////
//// 计数排序
//#include <iostream>
//using namespace std;
//const int maxn = 10000;
//int a[maxn];
//int b[maxn];
//int c[maxn];
//int main()
//{
//    int n;
//    while(cin>>n) {
//        memset(a,0,sizeof(a));
//        memset(b,0,sizeof(b));
//        memset(c,0,sizeof(c));
//        for(int i=0;i<n;i++) {
//            cin>>a[i];
//        }
//        int k = maxn;
//        int mx = 0;
//        for(int i=0;i<n;i++) {
//            c[a[i]]++;
//            mx = max(a[i],mx);
//        }
////        表示输出位置b中的最后一个位置(比方说1 1 2 那么1 放在1 因为0 1 放两个)
//        for(int i=0;i<=mx;i++) {
//            c[i] += c[i-1];
//        }
////        for(int i=n-1;i>=0;i--) 从后往前扫描 保证原有的顺序的引用(c的意义决定)
//        for(int i=0;i<=mx;i++) {
//            // 每次将c中的值-- 那么就会有第一个1放倒1的位置,第二个1 放倒0的位置
//            b[ c[a[i]]-- ] = a[i];
//        }
//        for(int i=1;i<=n;i++) {
//            cout<<b[i]<<" ";
//        }
//    }
//}
