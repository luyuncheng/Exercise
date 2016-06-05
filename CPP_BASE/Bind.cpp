//
// Created by 鲁蕴铖 on 16/6/5.
//
/*
#include <memory>
#include <functional>
#include <iostream>

double my_divide (double x, double y) {return x/y;}

struct myPair {
    double a,b;
    double multi() {return a*b;}
};

namespace test {
    class a {
    public:
        void funa() {}
    };

    class b : public a {
    public:
        void funb() { }
    };
    struct c {
        void func() {}
    };
}
int main()
{
    auto fn_five = std::bind(my_divide,10,2);
    std::cout<< fn_five() << '\n';
    test::b b1;
    test::c c1;
    //error
    //auto it1 = std::bind(&(test::c::func),&c1);
    auto it2 = std::bind(&test::c::func,&c1);
    auto it3 = std::bind(&test::a::funa, &b1);
    //error
    //auto it4 = std::bind(&(test::a::funa),&b1);

}
 */