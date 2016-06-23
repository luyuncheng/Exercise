//
// Created by 鲁蕴铖 on 16/6/23.
//

#include <iostream>
#include <algorithm>
#include <time.h>
#include <vector>
#include <set>
using namespace std;

struct Node {
    Node *pre;
    Node *nxt;

    struct NodeLevel {
        Node *lpre;
        Node *lnxt;
        NodeLevel() {
            lpre = lnxt = NULL;
        }
    }*level;
    int val;
    Node(){ pre = nxt = NULL; }
    Node(int v) : val(v) { Node(); }
    Node(int v, int len) {
        val = v;
        level = new NodeLevel[len];
        pre = nxt = NULL;
    }
    void addnxt(Node *p,int i) {
        p->level[i].lnxt = level[i].lnxt;
        p->level[i].lpre = this;
        if(p->level[i].lnxt)
            p->level[i].lnxt->level[i].lpre = p;
        this->level[i].lnxt = p;
    }
    void delcur(int i){
        level[i].lpre->level[i].lnxt = level[i].lnxt;
        level[i].lnxt->level[i].lpre = level[i].lpre;
    }
};

struct SkipList{
#define SKIPLIST_MAXLEVEL 16

    Node *head;
    Node *tail;
    int Level;
    unsigned long length;

    SkipList() {
        Level = 1;
        length = 0;
        head = new Node(INT_MIN,SKIPLIST_MAXLEVEL);
        tail = new Node(INT_MAX,SKIPLIST_MAXLEVEL);
        for(int i = 0; i < SKIPLIST_MAXLEVEL; i++)
            head->addnxt(tail,i);
    }
    ~SkipList() {
        FreeList(head);
    }
//    void Init(vector<int> a) {
//        sort(a.begin(),a.end());
//        Node *cur = head;
//        for(int i = 0; i < a.size(); i++) {
//            Node *node = new Node(a[i]);
//            cur->addnxt(node);
//            cur = node;
//        }
//    }
    int Insertval(int v) {
        Node *UpdateRoute[SKIPLIST_MAXLEVEL];
        Node *cur = head;
        // 当前层都能满足level可达
        for(int i = Level-1; i>=0; i--) {
            while(cur->level[i].lnxt && cur->level[i].lnxt->val < v) {
                cur = cur->level[i].lnxt;
            }
            if(cur == tail) return -1;
            UpdateRoute[i] = cur;
        }
        int lev = RandomLevel();
        // 如果需要阔level, 则多余的地方更新全部在head
        if(lev > Level) {
            for(int i = Level; i < lev; i++){
                UpdateRoute[i]=head;
            }
            Level = lev;
        }
        cur = new Node(v,lev);
        for(int i = 0; i < lev; i++) {
            UpdateRoute[i]->addnxt(cur,i);
        }
        ++length;
        return 0;
    }
    int Deleteval(int v) {
        Node *UpdateRoute[SKIPLIST_MAXLEVEL];
        Node *cur = head;
        for(int i = Level - 1; i >= 0; i--) {
            while(cur->level[i].lnxt && cur->level[i].lnxt->val < v) {
                cur = cur->level[i].lnxt;
            }
            if(cur == tail) return -1;
            UpdateRoute[i]=cur;
        }
        cur = UpdateRoute[0]->level[0].lnxt;
        if(cur->val == v) {
            for (int i = 0; i < Level; i++) {
                if (UpdateRoute[i]->level[i].lnxt == cur && UpdateRoute[i]->level[i].lnxt->val ==v)
                    UpdateRoute[i]->level[i].lnxt->delcur(i);
            }
        } else {
            return -2;
        }
        if(cur != head && cur != tail) {
            delete (cur);
        } else {
            return -3;
        }
        cur = head;
        while(cur->level[Level-1].lnxt == tail) {
            --Level;
        }
        --length;
    }
    bool Find(int v) {
        Node *cur = head;
        for(int i = Level - 1; i >= 0; i--) {
            while(cur->level[i].lnxt && cur->level[i].lnxt->val < v) {
                cur = cur->level[i].lnxt;
            }
            if(cur == tail) return false;
            if(cur->level[i].lnxt->val == v) {
                return true;
            }
        }
        return false;
    }
    void Display() {
        printf("length:%lu\n",length);
        for(int i = Level; i >= 0; i--){
            int con = 1;
            Node *cur = head->level[i].lnxt;
            printf("level(%d):%d -> ",i,head->val);
            while(cur){
                con++;
                printf("%d -> ",cur->val);
                cur = cur->level[i].lnxt;
                if(con % 8 == 0 && cur) {
                    printf("\nlevel(%d):",i);
                }
            }
            printf("NULL\n\n");
        }
    }
    int CheckLevel0(vector<int> &a) {
        Node *cur = head;
        cur = cur->level[0].lnxt;
        for(int i = 0; i < a.size(); i++) {
            if(cur->val != a[i]) {
                printf("check level error\n");
                return -1;
            }
            cur = cur->level[0].lnxt;
            if(cur == NULL) {
                printf("alread to NULL\n");
                return -2;
            }
        }
        //printf("check ok\n");
        return 0;
    }
    int RandomLevel() {
        int level = 1;
        while( ((rand()&0xFFFF) < (0.5 * 0xFFFF)) && (level < SKIPLIST_MAXLEVEL) )
            ++level;
        return (level < SKIPLIST_MAXLEVEL) ? level : SKIPLIST_MAXLEVEL;
    }
    void FreeList(Node *Thead){
        Node *cur = Thead->level[0].lnxt;
        while(cur) {
            Node *nxt = cur->level[0].lnxt;
            delete(cur);
            cur = nxt;
        }
        delete(Thead);
        return;
    }
};
void deltecheck(vector<int> &a, SkipList &list) {
    int len = a.size()/2;
    for(int i = 0; i < len; i++) {
        printf("id: %d\n",i);
        int idx = rand()%a.size();
        int tmp = a[idx];
        a.erase(a.begin()+idx);
        //printf("erase val = %d\n",tmp);
        list.Deleteval(tmp);
        //list.Display();
        if(list.CheckLevel0(a) < 0) {
            printf("deltel check error");
        }
    }
    printf("deltecheck end\n");
}
void findcheck(vector<int> &a, SkipList &list) {
    int len = a.size()/2;
    for(int i = 0; i < len; i++) {
        //printf("id: %d\n",i);
        int idx = rand()%a.size();
        int tmp = a[idx];

        if(list.Find(tmp) == false) {
            printf("find check error");
        }
    }
    printf("find end\n");
}
void multicheck(vector<int> &a, SkipList &list) {
    int len = a.size()/2;
    while(len--) {
        int op = rand()%3;
        //0 insert , 1 delete , 2 find
        if(op == 0) {
            int tmp = rand()%(len*2);
            list.Insertval(tmp);
            a.push_back(tmp);
            sort(a.begin(),a.end());
            if(list.CheckLevel0(a) < 0) {
                printf("insert check error\n");
            }
        } else if(op == 1) {
            int idx = rand()%a.size();
            int tmp = a[idx];
            a.erase(a.begin()+idx);
            list.Deleteval(tmp);
            if(list.CheckLevel0(a) < 0) {
                printf("delte check error\n");
            }
        } else if(op ==2) {
            // 0 find ok, 1 find rand
            int op2 = rand()%2;
            if(op2==0) {
                int idx = rand()%a.size();
                int tmp = a[idx];
                if(list.Find(tmp)==false) {
                    printf("find check 0 error\n");
                }
            } else {
                int tmp = rand()%a.size();
                bool ck = list.Find(tmp);
                bool ck2;
                int id = lower_bound(a.begin(),a.end(),tmp)-a.begin();
                if(a[id] == tmp) {
                    ck2 = true;
                } else {
                    ck2 = false;
                }
                if(ck != ck2) {
                    printf("find check 1 error\n");
                }
            }
        }
    }
}
void timecheck(vector<int>a, SkipList &list){

    multiset<int> st;
    int len = a.size();
    for(int i = 0; i < a.size(); i++) {
        st.insert(a[i]);
    }
    vector<int>que,ans1,ans2;
    for(int i = 0; i < len; i++) {
        que.push_back(rand()%a.size());
    }
    unsigned long stime1 = clock();
    for(int i = 0; i< que.size(); i++) {
        if(st.find(que[i]) != st.end()) {
            ans1.push_back(1);
        } else {
            ans1.push_back(-1);
        }
    }
    unsigned long endtime1 = clock();

    unsigned long stime2 = clock();
    for(int i = 0; i < que.size(); i++) {
        if(list.Find(que[i]) == true) {
            ans2.push_back(1);
        } else {
            ans2.push_back(-1);
        }
    }
    unsigned long endtime2 = clock();
    printf("time1: %ul\n",endtime1 - stime1);
    printf("time2: %ul\n",endtime2 - stime2);
    for(int i = 0; i< ans1.size(); i++) {
        if(ans1[i] != ans2[i]) {
            printf("error\n");
        }
    }
    printf("time check end\n");

}
int main() {
    SkipList list;
    vector<int> a;
    const int maxn = 100000;
    srand(time(0));
    for(int i = 0; i < maxn; i++) {
        int tmp = rand()%maxn;
        a.push_back(tmp);
        list.Insertval(tmp);
    }
    cout<<"haha"<<endl;
    sort(a.begin(),a.end());
    list.CheckLevel0(a);
//    list.Display();
//    for(int i = 0; i < a.size(); i++) {
//        cout<<a[i]<<" ";
//    }
//    deltecheck(a,list);
//    findcheck(a,list);
//    multicheck(a,list);
//    timecheck(a,list);
}