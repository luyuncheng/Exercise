//
//#include<iostream>
//#include<string>
//
//using namespace std;
//
//
//int n, p, h, w;
//int A[2000];
//
//bool check(int sz)
//{
//    int cont = w / sz;
//    int page = (h / sz) * p;
//    if(cont <= 0 || page <= 0) return false;
//    int sum = 0;
//    for(int i = 0; i < n; i++)
//    {
//        sum += (A[i] + cont - 1) / cont;
//    }
//    return bool(sum <= page);
//}
//
//
//int main()
//{
//    int T;
//    cin>>T;
//        for(int cas = 1; cas <= T; cas++)
//        {
//            cin>>n>>p>>w>>h;
//            for(int i = 0; i < n; i++)
//                cin>>A[i];
//            int low = 1, high = 10000000;
//            int ans =-1;
//            for(int t = 0; t < 100; t++)
//            {
//                int mid = (low + high) / 2;
//                if(check(mid))
//                    low = mid;
//                else
//                    high = mid - 1;
//            }
//            int L = max(1, low - 5);
//            int R = high + 5;
//            for(int i = R; i >= L; i--){
//                if(check(i)) {ans = i;break;}
//            }
//            if(ans == -1) {
//                ans =low;
//            }
//            cout<<ans<<endl;
//        }
//
//    return 0;
//}
//
