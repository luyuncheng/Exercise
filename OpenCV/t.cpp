//#include<cstdio>
//#include<cstring>
//#include<algorithm>
//#include<iostream>
//#include<vector>
//#include<string>
//using namespace std;
//
//typedef long long LL;
//
//
//const int NS = 200010;
//const int EDGE_MAX = NS;
//struct graphEdge{
//    int pst;
//    int next;
//    int val;
//};
//
//struct ForwardStart{
//    int top;
//    int head[EDGE_MAX];
//    graphEdge edge[EDGE_MAX << 1];
//    
//    void init()
//    {
//        top = 0;
//        memset(head, -1, sizeof(head));
//    }
//    
//    void addEdge(int u, int v, int val)
//    {
//        edge[top].pst = v;
//        edge[top].val = val;
//        
//        edge[top].next = head[u];
//        head[u] = top++;
//    }
//    
//    /*void printAll()
//    {
//        printf("top = %d\n", top);
//        for(int i = 1; i < EDGE_MAX; i++)
//        {
//            if(-1 != head[i])
//            {
//                printf("head[%2d]'son:%2d", i, edge[head[i]].pst);
//                for(int j = edge[head[i]].next; j != -1; j = edge[j].next)
//                {
//                    printf(",%2d", edge[j].pst);
//                }
//                puts("");
//            }
//        }
//    }*/
//}cTree;
//
//int n, m, q;
//int fav[NS];
//LL val[NS];
//LL tot;
//LL cnt[NS];
//
//void dfs(int rt, int fa)
//{
//    fav[rt] = fa;
//    cnt[rt] = 1;
//    
//    for(int i = cTree.head[rt]; i != -1; i = cTree.edge[i].next)
//    {
//        
//        int curson = cTree.edge[i].pst;
//        if(curson == fa) continue;
//        
//        dfs(curson, rt);
//        cnt[rt] += cnt[curson];
//        
//        LL left = cnt[curson];
//        LL right = n - left;
//        
//        val[curson] = cTree.edge[i].val;
//        tot += left * right * val[curson];
//    }
//}
//
//void update(int u, int v, int k)
//{
//    if(fav[u] == v)
//    {
//        LL left = cnt[u];
//        LL right = n - left;
//        tot -= left * right * val[u];
//        
//        val[u] = k;
//        tot += left * right * val[u];
//    }
//    else
//    {
//        
//        LL left = cnt[v];
//        LL right = n - left;
//        tot -= left * right * val[v];
//        
//        val[v] = k;
//        tot += left * right * val[v];
//    }
//}
//
//int main()
//{
//    
//    while(scanf("%d %d", &n, &m)!=EOF)
//    {
//        cTree.init();
//        int u, v, k;
//        for(int i = 1; i < n; i++)
//        {
//            scanf("%d %d %d", &u, &v, &k);
//            cTree.addEdge(u, v, k);
//            cTree.addEdge(v, u, k);
//        }
//        
//        tot = 0;
//        dfs(1, -1);
//        
//        int a,b,c;
//        char ch[10];
//        for(int i = 1; i <= m; i++)
//        {
//            scanf("%s", ch);
//            if('E' == ch[0])
//            {
//                scanf("%d %d %d", &a, &b, &c);
//                update(a, b, c);
//            }
//            else
//            {
//                printf("％d\n",tot);
//            }
//        }
//    }
//    return 0;
//}
