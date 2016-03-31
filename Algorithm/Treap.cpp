////
//// Created by 鲁蕴铖 on 16/3/31.
////
//
//#include <iostream>
//#include <cstdio>
//#include <cstring>
//#include <cstdlib>
//#include <algorithm>
//#include <set>
//using namespace std;
//const int maxn=1000100;
//struct node
//{
//    node *ch[2];
//    int r;
//    int v;
//    int s;
//    //node (int v):v(v){ch[0]=ch[1]=NULL;r=rand();s=1;}
//    int cmp(int x) const
//    {
//        if(x==v)return -1;
//        return x<v?0:1;
//    }
//    void maintain()
//    {
//        s=1;
//        if(ch[0]!=NULL)s+=ch[0]->s;
//        if(ch[1]!=NULL)s+=ch[1]->s;
//    }
//};
//multiset<int> has;
//node *root =NULL;
//int fl;
//struct treap
//{
//    node tree[maxn];
//    int tot;
//    void clear()
//    {
//        //memset(tree,0,sizeof(tree));
//        tot=0;
//        root=NULL;
//    }
//    node* newnode(int x)
//    {
//        node*p=&tree[tot++];
//        //p(x);
//        p->ch[0]=p->ch[1]=NULL;
//        //随机左右值
//        p->r=rand();
//        p->s=1;
//        p->v=x;
//        return p;
//    }
//    void rotate(node* &o,int d)
//    {
//        node* k=o->ch[d^1];
//        o->ch[d^1]=k->ch[d];
//        k->ch[d]=o;
//        o->maintain();
//        k->maintain();
//        o=k;
//    }
//    void insert(node* &o,int x)
//    {
//        //if(o==NULL)o=new node(x);
//        if(o==NULL) o=newnode(x);
//        else
//        {
//            int d=(x < o->v ? 0:1);
//            insert(o->ch[d],x);
//            if(o->ch[d]->r >o->r)
//                rotate(o,d^1);
//        }
//        o->maintain();
//    }
//    void remove(node* &o,int x)
//    {
//        if(fl)return;
//        if(o==NULL)
//        {
//            fl=1;
//            return;
//        }
//        int d=o->cmp(x);
//        if(d==-1)
//        {
//            node* u=o;
//            if(o->ch[0]!=NULL && o->ch[1]!=NULL)
//            {
//                int d2=(o->ch[0]->r > o->ch[1]->r ? 1:0);
//                rotate(o,d2);
//                remove(o->ch[d2],x);
//            }
//            else
//            {
//                if(o->ch[0]==NULL)
//                    o=o->ch[1];
//                else
//                    o=o->ch[0];
//                //delete u;
//            }
//        }
//        else
//            remove(o->ch[d],x);
//        if(o!=NULL)	o->maintain();
//        //if(o==NULL){fl=1;return;}
//    }
//    //k小值
//    int find(node* o,int k)
//    {
//        if(o==NULL || k<=0 || k>o->s)return -1;
//        int s=(o->ch[0] == NULL ? 0:o->ch[0]->s);
//        if(k==s+1)
//            return o->v;
//        else if(k<=s)return find(o->ch[0],k);
//        else    return find(o->ch[1],k-s-1);
//    }
//    /*int getmin(node *o)
//    {
//    	if(o==NULL)return 0;
//    	while(o->ch[0]!=NULL)
//    		o=o->ch[0];
//    	//这里只是id，排序的键值是v
//    	int ans=o->id;
//    	return ans;
//    } */
//    /*int getmax(node *o)
//    {
//    	if(o==NULL)return 0;
//    	while(o->ch[1]!=NULL)
//    		o=o->ch[1];
//    	//这里只是id，排序的键值是v
//    	int ans=o->id;
//    	return ans;
//    }*/
//    //找小于x的个数，即确定x的排名
//    int less_than(node *o,int x)
//    {
//        if(o==NULL)return -1;
//        if(o->v <= x)
//        {
//            if(o->ch[0]!=NULL)//左儿子节点+本身+右边节点
//                return o->ch[0]->s+1+less_than(o->ch[1],x);
//            else//如果左儿子为空，本身加上右儿子节点
//                return 1+less_than(o->ch[1],x);
//        }
//        return less_than(o->ch[0],x);
//    }
//    //找大于x的个数，即确定x的逆序排名
//    int more_than(node *o,int x)
//    {
//        if(o==NULL)return -1;
//        if(o->v >=x)
//        {
//            if(o->ch[1]!=NULL)
//                return o->ch[1]->s+1+more_than(o->ch[0],x);
//            else
//                return 1+more_than(o->ch[0],x);
//        }
//        return more_than(o->ch[1],x);
//    }
//};
//treap tre;
//struct que
//{
//    int op;
//    int v;
//} qu[maxn];
//int main()
//{
//    int T;
//    int n,k;
////    scanf("%d",&T);
//    while(scanf("%d%d",&n,&k)!=EOF)
//    {
//        has.clear();
//        tre.clear();
//        int ind=0;
//        char op[100];
//        int t;
//        while(n--)
//        {
//            scanf("%s",op);
//            //cin>>op>>t;
//            if(op[0]=='I')
//            {
//                scanf("%d",&t);
//                qu[ind].op=1;
//                qu[ind++].v=t;
//            }
//            else
//            {
//                qu[ind].op=0;
//                qu[ind++].v=0;
//            }
//        }
////        cout<<"haha"<<endl;
//        for(int cas=0; cas<ind; cas++)
//        {
//            fl=0;
//            t=qu[cas].v;
//            if(qu[cas].op==0)
//            {
////                cout<<":"<<root<<endl;
//                int siz=has.size();
//                int sz;
////				cout<<"sz:"<<siz<<" :::"<<siz-k+1<<endl;
//                int ans=tre.find(root,siz-k+1);
//                printf("%d\n",ans);
//            }
//            else
//            {
//
//                has.insert(t);
//                tre.insert(root,t);
//
//            }
//        }
//        for(int i=0; i<=tre.tot; i++)
//        {
//            tre.tree[i].ch[0]=tre.tree[i].ch[1]=NULL;
//            tre.tree[i].r=tre.tree[i].v=tre.tree[i].s=0;
//        }
//        //cout<<"cas1"<<endl;
//    }
//
//}