////
//// Created by 鲁蕴铖 on 16/3/10.
////
//#include <iostream>
//using namespace std;
//
//class Base {
//public:
//    Base(){};
//    void  pri(){
//        printf("Base public static function\n");
//    }
//    int s;
//};
//class Dri : public Base {
//public:
//    Dri(){};
//    void  pri2(){
//        printf("Dri public static function\n");
//    }
//    int b;
//};
//int main1()
//{
//    Base *p = new Base();
//    Dri *p2 ;
//    //p2 = (Dri *)p;
//    p2= static_cast<Dri *> (p);
//    p2->pri();
//}