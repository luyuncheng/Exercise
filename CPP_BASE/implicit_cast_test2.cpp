////
//// Created by 鲁蕴铖 on 16/3/30.
////
//
//#include <iostream>
//#include <cstdio>
//using namespace std;
//
//struct top{};
//struct mid_a :top{};
//struct mid_b :top{};
//struct bottom : public mid_a, public mid_b {};
//
//void foo(mid_a &){}
//void foo(mid_b &){}
//void bar(top &arg) {
//    // 想用调用void foo(mid_a &)
//    foo(static_cast<mid_a &>(arg));
////    foo(arg); //error
//}
//
//int main() {
//    top x;
//    bar(x);
//    return 0;
//}