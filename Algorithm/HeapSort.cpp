//
// Created by 鲁蕴铖 on 16/7/2.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
const int maxn = 10000;
struct heap{
    int pool[maxn];
    int sz;
    int parent(int i){
        return i/2;
    }
    int left(int i) {
        return i*2;
    }
    int right(int i) {
        return i*2+1;
    }
    void maintain(int i) {
        int l = left(i);
        int r = right(i);
        int mx = i;
        if( l <= sz && pool[l] > pool[i]) {
            mx = l;
        }
        if( r <= sz && pool[r] > pool[mx]) {
            mx = r;
        }
        if(mx != i) {
            swap(pool[i],pool[mx]);
            maintain(mx);
        }
    }
    void build(vector<int> &a) {
        for(int i = 0; i < a.size(); i++) {
            pool[i+1] = a[i];
        }
        sz = a.size();
        for(int i = sz/2; i >= 1; i--) {
            maintain(i);
        }
    }
    void sort() {
        for(int i = sz; i >= 1; i--) {
            cout<<pool[1]<<" ";
            if(i == 1) break;
            swap(pool[1],pool[i]);
            sz --;
            maintain(1);
        }
    }
};
int main()
{
    vector<int> a;
    heap h;
    for(int i = 1; i <= 10; i++) {
        a.push_back(i);
    }
    h.build(a);
    h.sort();
}