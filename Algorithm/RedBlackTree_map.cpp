////
//// Created by 鲁蕴铖 on 16/3/31.
////
//
//#include<iostream>
//#include<string>
//#include<cstring>
//#include<algorithm>
//#include<cstdio>
//using namespace std;
//
///* 0 => black , 1 => red */
//
//#define black 0
//#define red   1
//#define right ch[1]
//#define left  ch[0]
//
//
//template<typename T,typename M>
////template<typename T>
//class rb_tree{
//    /* Note:
//     * kth()由于是模版函数当超出值的时候返回faultkey->key，这个方法是在实现的时候需要自己定义错误
//     */
//private:
//    struct node{
//        node *ch[2],*pa;//child[2] parent
//        int s;//sun
//        bool c;//flag
//        T key;
//        M data;
//        node(const T&k,const M&d,node*p){
//            pa=p;s=1,c=1,key=k,data=d;
//        }
//        node(){
//            s=0,c=0;
//            ch[0]=ch[1]=pa=this;
//        }
//        //void setkey(const T&d){key=d;}
//    }*nil,*root;
//    node *faultkey;
//    inline void rotate(node*o,bool d){
//        node *father=o->pa;
//        if(!father->s){
//            root=o->ch[!d];
//        }
//        else{
//            if(o==father->right)
//                father->right=o->ch[!d];
//            else
//                father->left=o->ch[!d];
//        }
//        o->ch[!d]->pa=o->pa;
//        o->pa=o->ch[!d];
//        o->ch[!d]=o->pa->ch[d];
//        o->pa->ch[d]=o;
//        if(o->ch[!d]->s)o->ch[!d]->pa=o;
//        o->pa->s=o->s;
//        o->s=o->ch[0]->s+o->ch[1]->s+1;
//    }
//    inline void setkey(node*o,const T&key){
//        o->key=key;
//    }
//    inline node *find(node*o,const T&key){
//        while(o->s&&o->key!=key){
//            if(o->key<key)o=o->right;
//            else            o=o->left;
//        }
//        if(o->s>0)return o;
//        else  return 0;
//    }
//    /**
//     * 插入修复情况1：如果当前结点的父结点是红色且祖父结点的另一个子结点（叔叔结点）是红色
//     * 解决策略是：将当前节点的父节点和叔叔节点涂黑，祖父结点涂红，
//     * 把当前结点指向祖父节点，从新的当前节点重新开始算法。
//
//     * 插入修复情况2：当前节点的父节点是红色,叔叔节点是黑色，当前节点是其父节点的右子
//     * 解决对策是：当前节点的父节点做为新的当前节点，以新当前节点为支点左旋。
//
//     * 插入修复情况3：当前节点的父节点是红色,叔叔节点是黑色，当前节点是其父节点的左子
//     * 解决对策是：父节点变为黑色，祖父节点变为红色，在祖父节点为支点右旋。
//     *
//     */
//    inline void insert_fix(node*&o){
//        while(o->pa->c==red){//如果父亲节点颜色是red，前提条件
//            bool d=o->pa==o->pa->pa->ch[0];//判断祖父左儿子右儿子，1为左儿子，0为右儿子，为的是后面取uncle的时候反用01。
//            node *uncle=o->pa->pa->ch[d];//爷爷的另外儿子，父亲兄弟
//            if(uncle->c==red){//case1
//                uncle->c=o->pa->c=black;//父亲和叔叔都是黑色
//                o->pa->pa->c=red;//爷爷为红色
//                o=o->pa->pa;
//            }else{
//                if(o==o->pa->ch[d]){//case2
//                    o=o->pa;
//                    rotate(o,!d);
//                }
//                o->pa->c=black; //把父亲的颜色置为黑色
//                o->pa->pa->c=red;//祖父为红色
//                rotate(o->pa->pa,d);//case3
//            }
//        }
//        root->c=black;//跟节点总为黑色
//    }
//
//    /**
//     * 删除修复情况1：当前节点是黑+黑且兄弟节点为红色(此时父节点和兄弟节点的子节点分为黑)
//     * 解法把父节点染成红色，把兄弟结点染成黑色，之后重新进入算法。
//     *
//     * 删除修复情况2：当前节点是黑加黑且兄弟是黑色且兄弟节点的两个子节点全为黑色
//     * 解法：把当前节点和兄弟节点中抽取一重黑色追加到父节点上，把父节点当成新的当前节点，重新进入算法。
//     *
//     * 删除修复情况3：当前节点颜色是黑+黑，兄弟节点是黑色，兄弟的左子是红色，右子是黑色
//     * 解法：把兄弟结点染红，兄弟左子节点染黑，之后再在兄弟节点为支点解右旋，之后重新进入算法。
//     *
//     * 删除修复情况4：当前节点颜色是黑-黑色，它的兄弟节点是黑色，但是兄弟节点的右子是红色，兄弟节点左子的颜色任意
//     * 解法：把兄弟节点染成当前节点父节点的颜色，把当前节点父节点染成黑色，兄弟节点右子染成黑色，之后以当前节点的父节点为支点进行左旋，此时算法结束，红黑树所有性质调整正确
//     *
//     **/
//
//    inline void erase_fix(node*&x){
//        while(x!=root&& (x->c)==black) //当前节点非root且为黑色
//        {
//            bool d=x==x->pa->ch[0];
//            node *w=x->pa->ch[d];//当前节点的兄弟节点
//            if(w->c==red){//case1
//                w->c=black;
//                x->pa->c=red;
//                rotate(x->pa,!d);
//                w=x->pa->ch[d];
//            }
//            if(w->ch[0]->c==black && w->ch[1]->c==black){//case2
//                w->c=red;x=x->pa;
//            }else{
//                if(w->ch[d]->c==black){//case3,4合并
//                    w->ch[!d]->c=black;
//                    w->c=red;
//                    rotate(w,d);
//                    w=x->pa->ch[d];
//                }
//                w->c=x->pa->c;
//                w->ch[d]->c=x->pa->c=black;
//                rotate(x->pa,!d);
//                break;
//            }
//        }
//        x->c=black;
//    }
//    void clear(node*&o){
//        if(o->s){
//            clear(o->ch[0]);
//            clear(o->ch[1]);
//            delete(o);
//        }
//    }
//    inline void dfsprint(node*&x){
//        if(x==nil)return;
//        cout<<"root:"<<(x->key)<<"("<<x->data<<")";
//        if(x->ch[0]!=nil)cout<<"   l:"<<(x->ch[0]->key)<<"("<<(x->ch[0]->data)<<")";
//        else
//            cout<<"  end";
//        if(x->ch[1]!=nil)cout<<"   r:"<<(x->ch[1]->key)<<"("<<(x->ch[1]->data)<<")"<<endl;
//        else
//            cout<<"  end"<<endl;
//        dfsprint(x->ch[0]);
//        dfsprint(x->ch[1]);
//    }
//    inline int depthdfs(node *&x)
//    {
//        if(x==nil)return 0;
//        int mx=0;
//        mx=max(mx,depthdfs(x->ch[0]));
//        mx=max(mx,depthdfs(x->ch[1]));
//        return mx+1;
//    }
//public:
//    //构造函数初始化 new 节点
//    rb_tree():nil(new node),root(nil),faultkey(new node){}
//    ~rb_tree(){clear(root),delete nil;}
//    inline void clear(){clear(root),root=nil;}
//    inline void insert(const T&key,const M&data){
//        node *o=root;
//        if(!o->s){
//            root=new node(key,data,nil);
//            root->ch[0]=root->ch[1]=nil;
//        }else{
//            for(;;){
//                o->s++;
//                bool d=(o->key)<key;//左0右1
//                if(o->ch[d]->s)o=o->ch[d];//儿子还能有儿子
//                else{
//                    //否则就新建节点
//                    o->ch[d]=new node(key,data,o),o=o->ch[d];
//                    o->ch[0]=o->ch[1]=nil;
//                    break;
//                }
//            }
//        }
//        insert_fix(o);
//    }
//    inline void insert(const T&key){
//
//        node *o=root;
//        if(!o->s){
//            root=new node(key,"",nil);
//            root->ch[0]=root->ch[1]=nil;
//        }else{
//            for(;;){
//                o->s++;
//                bool d=(o->key)<key;//左0右1
//                if(o->ch[d]->s)o=o->ch[d];//儿子还能有儿子
//                else{
//                    //否则就新建节点
//                    o->ch[d]=new node(key,"",o),o=o->ch[d];
//                    o->ch[0]=o->ch[1]=nil;
//                    break;
//                }
//            }
//        }
//        insert_fix(o);
//    }
//
//    inline bool erase(const T&key){
//        node *o=find(root,key);
//        if(!o)return 0;
//        node *t=o,*p;
//        if(o->ch[0]->s&&o->ch[1]->s){
//            t=o->ch[1];
//            while(t->ch[0]->s)t=t->ch[0];
//        }
//        p=t->ch[!t->ch[0]->s];
//        p->pa=t->pa;
//        if(!t->pa->s)root=p;
//        else t->pa->ch[t->pa->ch[1]==t]=p;
//        if(t!=o)o->key=t->key;
//        for(o=t->pa;o->s;o=o->pa)o->s--;
//        if(!t->c)erase_fix(p);
//        delete t;
//        return 1;
//    }
//    inline bool find(const T&key){
//        return find(root,key);
//    }
//    //0开始的排名
//    inline int rank(const T&key){
//        int cnt=0;
//        for(node *o=root;o->s;)
//            if(o->key<key)cnt+=o->ch[0]->s+1,o=o->ch[1];
//            else o=o->ch[0];
//        return cnt;
//    }
//    //kth由于是模版函数当超出值的时候返回faultkey->key的key，这个方法是错误的，需要给定值
//    inline const T&kth(int k){
//        for(node *o=root;;)
//            if(k<=o->ch[0]->s){
//                if(k<0)return faultkey->key;
//                o=o->ch[0];
//            }
//            else if(k==o->ch[0]->s+1)return o->key;
//            else {
//                k-=o->ch[0]->s+1,o=o->ch[1];
//                if(k<0 || o==nil)return faultkey->key;
//            }
//    }
//    inline const M&kth_data(int k){
//        for(node *o=root;;){
//            if(k<=o->ch[0]->s){
//                if(k<0)return faultkey->key;
//                o=o->ch[0];
//            }
//            else if(k==o->ch[0]->s+1)return o->data;
//            else{
//                k-=o->ch[0]->s+1,o=o->ch[1];
//                if(k<0 || o==nil)return faultkey->key;
//            }
//        }
//    }
//    inline const T&operator[](const T&k){
//        if(find(k)){
//            return kth_data(rank(k)+1);
//        }
//    }
//    //这里pre并没有做有值判断，所以可能某个值是没有的，那么可以先find一次
//    inline const T&preorder(const T&key){
//        node *x=root,*y=0;
//        while(x->s)
//            if(x->key<key){y=x,x=x->ch[1];}
//            else{
//                x=x->ch[0];
//                // 这里key值唯一，那么如果右儿子为空那么就是fault
//                if(x==nil)return faultkey->key;
//            }
//        if(y){
//            //   if(y==nil)return faultkey->key;
//            return y->key;
//        }
//        return key;
//    }
//    //这里pre并没有做有值判断，所以可能某个值是没有的，那么可以先find一次
//    inline const T&nextorder(const T&key){
//        node *x=root,*y=0;
//        while(x->s)
//            if(key<x->key)y=x,x=x->ch[0];
//            else x=x->ch[1];
//        if(y)return y->key;
//        return key;
//    }
//    inline int size(){return root->s;}
//
//    inline void print(){
//        dfsprint(root);
//    }
//    //设置错误的返回值
//    inline void setfault(const T&key){
//        setkey(faultkey,key);
//    }
//
//    inline int depth(){
//        return depthdfs(root);
//    }
//    inline void change(const T&key1,const T&key2){
//        erase(key1);
//        insert(key2);
//    }
//    //第一个为第几个数，第二个为值
//    inline pair<int,T> lower_bound(const T&key){
//        int cnt=0;
//        T v=0;
//        for(node *o=root;o->s;){
//            if(o->key<key){
//                cnt+=o->ch[0]->s+1;
//                o=o->ch[1];
//            }
//            else {
//                o=o->ch[0];
//            }
//            if(o!=nil){
//                v=o->key;
//            }
//        }
//        return make_pair(cnt,v);
//    }
//};
//int main()
//{
//    rb_tree<int,string> a;
//    for(int i=1;i<=1024;i++)
//        a.insert(i,"");
//    cout<<"depth"<<a.depth()<<endl;
//    //a.insert(2);
//    //a.insert(4,"c");
//    //a.insert(5,"d");
//    //a.setfault(-1);
//    //cout<<a[50]<<endl;
//
//    //cout<<a.preorder(2)<<endl;
//    //cout<<a.preorder(-2)<<endl;
//    //cout<<a.preorder(1)<<endl;
//    //cout<<a.nextorder(-1)<<endl;
//    //cout<<a.nextorder(101)<<endl;
//    //cout<<"find:"<<a.find(40)<<endl;
//    //cout<<"rank:"<<a.rank(1)<<endl;
//    //cout<<"kth :"<<a.kth(50)<<endl;
//
//    //a.print();
//    //cout<<endl<<"dep:"<<a.depth()<<endl;
//    //a.change(2,5);
//    //a.print();
//    //pair<int,int> pr=a.lower_bound(6);
//    //cout<<"pair"<<endl;
//    //cout<<pr.first<<" "<<pr.second<<endl;
//}
