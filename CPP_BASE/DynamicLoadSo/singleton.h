#ifndef SINGLETON
#define SINGLETON
template<typename T>
class Singleton
{
    friend T;
    Singleton() = default;
    virtual ~Singleton() = default;

public:
    static auto getInstance()
    -> T &
    {
        static T t;
        return t;
    }
};
/*
class Test : public Singleton<Test>
{
    friend Singleton<Test>;
    Test(){}
};*/
#endif
