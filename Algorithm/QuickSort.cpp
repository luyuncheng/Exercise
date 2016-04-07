////
//// Created by 鲁蕴铖 on 16/3/31.
////
//
//#include <iostream>
//#include <cstdio>
//#include <vector>
//using  namespace std;
//
//vector<int> a;
//vector<int> b;
//int maintain(int key,int l,int r) {
//    while( l < r) {
//        while(l < r && a[r] >= key) {
//            --r;
//        }
//        a[l] = a[r];
//
//        while(l<r && a[l] <= key) {
//            ++l;
//        }
//        a[r] = a[l];
//    }
//    a[l] = key;
//    return l;
//}
//void quicksort(int l,int r) {
//    if(l >= r) return;
//    int invoke = (rand()%(r-l+1))+l;
////    int invoke = l;
//    swap(a[invoke],a[l]);
//
//    int mid = maintain(a[l],l,r);
//    quicksort(l,mid-1);
//    quicksort(mid+1,r);
//}
//int main()
//{
//    int n;
//    cin>>n;
//    for(int i=0;i<n;i++) {
//        int tmp = rand();
////        cin>>tmp;
//        a.push_back(tmp);
//        b.push_back(tmp);
//    }
//    time_t st = time(0);
//    quicksort(0,a.size()-1);
//    time_t ed = time(0);
//    cout<<ed-st<<endl;
//
//    st = time(0);
//    sort(b.begin(),b.end());
//    ed = time(0);
//    cout<<ed-st<<endl;
//    for(int i=0;i<a.size();i++){
//        if(a[i] != b[i]) cout <<"i:"<<i<<" error"<<endl;
//    }
//    cout<<endl;
//
//}
