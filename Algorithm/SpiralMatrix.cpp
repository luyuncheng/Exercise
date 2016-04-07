////
//// Created by 鲁蕴铖 on 16/4/3.
////
//
//#include <iostream>
//#include <stdio.h>
//#include <string.h>
//#define M 20
//int a[M][M];
//
//int main(int argc, const char * argv[]) {
//    int n;
//    printf("Please input n(n<=M):");
//    scanf("%d",&n);
//    int x,y,tot=0;
//    memset(a,0,sizeof(a));
//    tot=1;
//    a[0][0]=1;
//    while(tot<n*n){
//        while(y+1<n && !a[x][y+1]) a[x][++y]=++tot;
//        while(x+1<n && !a[x+1][y]) a[++x][y]=++tot;
//        while(y-1>=0 && !a[x][y-1]) a[x][--y]=++tot;
//        while(x-1>=0 && !a[x-1][y]) a[--x][y]=++tot;
//    }
//
//    for(x=0;x<n;x++)
//        for(y=0;y<n;y++)
//            printf("%3d",a[x][y]);
//
//    return 0;
//}