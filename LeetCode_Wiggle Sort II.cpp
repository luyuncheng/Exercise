//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//class Solution {
//public:
//    void wiggleSort(vector<int>& nums) {
//        int len=nums.size();
//        //O(n) time to find the mid_val
//        int mid = len/2;
//        nth_element(nums.begin(), nums.begin()+len/2, nums.end());
//        cout<<"mid:"<<mid<<endl;
//        cout<<"nth:"<<endl;
//        for(int i=0;i<nums.size();i++){
//            cout<<nums[i]<<", ";
//        }
//        cout<<endl;
//        if(mid%2==1){
//            for(int i=1,j=mid; i<mid,j<len; i+=2,j+=2) {
//
//                printf("nums[%d]=%d,nums[%d]=%d\n",i,nums[i],j,nums[j]);
//                swap(nums[i],nums[j]);
//            }
//            if(len%2==0){
//                //swap(nums[mid],nums[len-1]);
//            }
//        }
//        if(mid%2==0){
//            for(int i=1,j=mid; i<mid,j<len; i+=2,j+=2) {
//                swap(nums[i],nums[j]);
//            }
//        }
//        // for(int i=0;i<len-1;i++) {
//        //     if(i%2 == 1) {
//        //         if(nums[i+1]>nums[i])
//        //             swap(nums[i],nums[i+1]);
//        //     } else {
//        //         if(nums[i+1]<nums[i])
//        //             swap(nums[i],nums[i+1]);
//        //     }
//        // }
//
//    }
//};
////https://leetcode.com/discuss/77115/o-n-time-o-1-space-solution-with-detail-explanations
//class Solution2 {
//public:
//    void wiggleSort(vector<int>& nums) {
//        if (nums.empty()) {
//            return;
//        }
//        int n = nums.size();
//
//        // Step 1: Find the median
//        vector<int>::iterator nth = next(nums.begin(), n / 2);
//        nth_element(nums.begin(), nth, nums.end());
//        int median = *nth;
//
//        // Step 2: Tripartie partition within O(n)-time & O(1)-space.
//        auto m = [n](int idx) { return (2 * idx + 1) % (n | 1); };
//        int first = 0, mid = 0, last = n - 1;
//        cout<<"median:"<<median<<endl;
//        while (mid <= last) {
//            cout<<"midpos:"<<m(mid)<<"  val:"<<nums[m(mid)]<<endl;
//            cout<<"firpos:"<<m(first)<<"  val:"<<nums[m(first)]<<endl;
//            cout<<"laspos:"<<m(last)<<"  val:"<<nums[m(last)]<<endl;
//            if (nums[m(mid)] > median) {
////                奇数都是大数
//                swap(nums[m(first)], nums[m(mid)]);
//                ++first;
//                ++mid;
//            }
//            else if (nums[m(mid)] < median) {
//                // 偶数都是小数
//                swap(nums[m(mid)], nums[m(last)]);
//                --last;
//            }
//            else {
//                ++mid;
//            }
//        }
//    }
//};
////where (n | 1) calculates the nearest odd that is not less than n.
//int map_index(int idx, int n) {
//
//    return (2 * idx + 1) % (n | 1);
//}
//int main()
//{
//
//
//    Solution a1;
//    Solution2 a2;
////    int b[]={1,2,1,2,1,1,2,2,1,2};
//    int b[]={0,1,2,3,4,5,6,7,8,9};
//    for (int i=0; i<10; i++) {
//        cout<<"i:"<<i<<" "<<map_index(i,10)<<endl;
//    }
//    vector<int>a=vector<int>(b,b+10);
//    vector<int>aa=vector<int>(b,b+10);
//    a1.wiggleSort(a);
//    a2.wiggleSort(aa);
//    for(int i=0;i<a.size();i++){
//        cout<<a[i]<<", ";
//    }
//    for(int i=0;i<a.size();i++){
//        cout<<aa[i]<<", ";
//    }
//    cout<<endl;
//}