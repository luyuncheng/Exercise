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
//void bar(bottom &arg) {
//    // 想用调用void foo(mid_a &)
////    foo(static_cast<mid_a &>(arg));//ok
////    foo(arg);//error
//}
//
//int main() {
//    bottom x;
//    bar(x);
//    return 0;
//}