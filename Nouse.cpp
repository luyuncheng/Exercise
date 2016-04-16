//////
////// Created by 鲁蕴铖 on 16/4/12.
//////
////
//#include <iostream>
//#include <algorithm>
//using namespace std;
//struct node {
//    int id;
//    int num;
//}a[110];
//int cmp(node a1,node a2) {
//    return a1.num<a2.num;
//}
//int main()
//{
//    int n;
//    while(cin>>n) {
//        int mx = 0;
//        node my;
//        for(int i=1;i<=n;i++) {
//            if(i>1) {
//                cin>>a[i].num;
//                a[i].id = i;
//                mx = max(mx,a[i].num);
//            }else {
//                cin>>my.num;
//                my.id = i;
//            }
//        }
//        int ans =0;
//        sort(a+2,a+1+n,cmp);
//        if(my.num > mx) {
//            cout << 0<<endl;
//        } else {
//            while(my.num <= mx ) {
//                a[n].num --;
//                my.num++;
//                sort(a+2,a+1+n,cmp);
//                mx = a[n].num;
//                ans ++;
//            }
//        }
//        cout<<ans<<endl;
//    }
//}
//#include <iostream>
//using namespace std;
//int main()
//{
//    string mp[3];
//    for(int i=0;i<3;i++){
//        cin>>mp[i];
//    }
//    int con1 = 0;
//    int con2 = 0;
//    for(int i=0;i<3;i++) {
//        for(int j=0;j<3;j++) {
//            if(mp[i][j] == 'X')  con1++;
//            if(mp[i][j] == '.')  con2++;
//        }
//    }
//    // 判断水平
//    int win = 0;
//    for(int i = 0; i < 3;i++) {
//        char pre =mp[i][0];
//        int flag = 1;
//        for(int j =1 ;j<3;j++) {
//            if(pre != mp[i][j]) {
//                flag = 0;break;
//            }
//        }
//        if(flag) win = (pre == 'X')? 1 : 2;break;
//    }
//    // 垂直
//    for(int  j = 0; j  < 3;j++) {
//        char pre =mp[j][0];
//        int flag = 1;
//        for(int i =1 ;i<3;i++) {
//            if(pre != mp[i][j]) {
//                flag = 0;break;
//            }
//        }
//        if(flag) win = (pre == 'X')? 1 : 2;break;
//    }
//    //对角
//    int pre = mp[0][0];
//    if(pre == mp[1][1] && pre == mp[2][2]) {
//        win = (pre == 'X')? 1 : 2;
//    }
//    pre = mp[0][2];
//    if(pre == mp[1][1] && pre == mp[2][0]) {
//        win = (pre == 'X')? 1 : 2;
//    }
//    if(con1-con2 <=1) {
//        cout <<合法;
//    }
//    cout<<win<<endl;
//}