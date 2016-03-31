////
//// Created by 鲁蕴铖 on 16/3/31.
////
//
//#include <iostream>
//const int maxn = 10000;
//int heap[maxn];
//int pos=0;
//void maintainup(int p) {
//    while(heap[p] > heap[p/2] && p > 1) {
//        std::swap(heap[p],heap[p/2]);
//        p = p/2;
//    }
//}
//void add(int val) {
//    heap[++pos] = val;
//    maintainup(pos);
//}
//int get() {
//    return heap[1];
//}
//void maintaindown(int p) {
//    if(p>pos)return;
//    if(heap[p] < heap[p*2] && heap[p] < heap[p*2+1]) {
//        if(heap[p*2] > heap[p*2+1]){
//            std::swap(heap[p],heap[p*2]);
//            maintaindown(p*2);
//        } else {
//            std::swap(heap[p],heap[p*2+1]);
//            maintaindown(p*2+1);
//        }
//    }
//}
//void pop() {
//    std::swap(heap[pos],heap[1]);
//    pos--;
//    maintaindown(1);
//}
//
//void increase(int p,int val) {
//    if(heap[p]<=val) return;
//    heap[p] = val;
//    maintainup(p);
////    while (heap[p] > heap[p/2] && p > 1) {
////        std::swap(heap[p],heap[p/2]);
////        p = p/2;
////    }
//}
//int main()
//{
//
//}