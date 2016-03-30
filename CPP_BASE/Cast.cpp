////
//// Created by 鲁蕴铖 on 16/3/30.
////
//#include <iostream>
//using namespace std;
//
//class B {
//public:
//    int m_iNum;
//    void foo(){}
//};
//
//class D:public B {
//public:
//    char* m_szName[100];
//};
//
//void func(B* pb) {
//    D* pd1=static_cast<D*>(pb);
//    D* pd2=dynamic_cast<D*>(pb);
//    printf("%d\n",pd1);
//    printf("%d\n",pd2);
//}
//
////交叉编译(cross cast)
//class A {
//public:
//    int m_iNum;
//    virtual void f(){}
//};
//class B : public A {
//
//};
//class D:public A {
//
//};
//void foo() {
//    B *pb = new B;
//    pb->m_iNum=100;
//    D *pd1 = static_cast<D*>(pb);//compile error
//    D *pd2 = dynamic_cast<D*>(pb);//pd2is NULL
//    delete pb;
//}
////在函数foo中，使用static_cast进行转换是不被允许的，将在编译时出错，而使用 dynamic_cast的转换则是允许的，结果是空指针。
//
//
//int main()
//{
//    B *b = new B() ;
//    D *d = new D() ;
//    func(b);
//}