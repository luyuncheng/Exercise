////
//// Created by 鲁蕴铖 on 16/4/14.
////
//
//#include <iostream>
//#include <cmath>
//#include <algorithm>
//using namespace std;
//
//int findKth(int* a, int resta, int* b, int restb, int k)
//{
//    if(resta > restb) return findKth(b, restb, a, resta, k);
//    if(0 == resta) return b[k - 1];
//    if(1 == k) return min(a[0], b[0]);
//    int left = min((k >> 1), resta);
//    int right = k - left;
//
//    if(a[left - 1] < b[right - 1]) return findKth(a + left, resta - left, b, restb, k - left);
//    else if(a[left - 1] > b[right - 1]) return findKth(a, resta, b + right, restb - right, k - right);
//    else return a[left - 1];
//}
//
//int main()
//{
//    int ans = findKth(nums1, nums1Size, nums2, nums2Size, len);
//}