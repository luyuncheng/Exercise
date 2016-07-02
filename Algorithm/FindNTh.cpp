//
// Created by 鲁蕴铖 on 16/7/2.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int Partition(vector<int> &a,int p,int r) {
    int x = a[r];
    int i = p-1;
    for(int j = p; j <= r-1; j++) {
        if(a[j] <= x) {
            i++;
            swap(a[i],a[j]);
        }
    }
    swap(a[i+1],a[r]);
    return i+1;
}
int randompartition(vector<int> &a,int p,int r) {
    int i = rand()%(r-p)+p;
    swap(a[i],a[r]);
    return Partition(a,p,r);
}
int select(vector<int> &a,int l,int r,int n){

    int pos = randompartition(a,l,r);
    if(pos == n) {
        return a[pos];
    }
    if(pos < n) {
        return select(a,pos,r,n);
    } else {
        return select(a,l,pos,n);
    }
}
int main()
{
    vector<int> a;
    for(int i = 0; i < 10; i++) {
        a.push_back(rand()%10);
    }
    for(int i = 0; i < a.size(); i++) {
        cout<<a[i]<<" ";
    }
    cout<<endl<<select(a,0,a.size()-1,1);
}