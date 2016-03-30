//
// Created by 鲁蕴铖 on 16/3/30.
//
#include <iostream>
using namespace std;

class B {
public:
    int m_iNum;
    void foo(){}
};

class D:public B {
public:
    char* m_szName[100];
};

void func(B* pb) {
    D* pd1=static_cast<D*>(pb);
    D* pd2=dynamic_cast<D*>(pb);
    printf("%d\n",pd1);
    printf("%d\n",pd2);
}
int main()
{
    B *b = new B() ;
    D *d = new D() ;
    func(b);
}