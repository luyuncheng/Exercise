#include <iostream>
#include <thread>
#include <mutex>
#include "load.h"
#include <sys/time.h>
#include <unistd.h>
#include "say.h"
#include <pthread.h>
#include <stdlib.h>
using namespace std;
class DoSth: public Singleton<DoSth>
{
    public:
        DoSth():m_so(new LoadSo("./test_old.so")){pre = 0;}
        DynamicSo_ptr Get()
        {

            DynamicSo_ptr _m_so;
            std::unique_lock<std::mutex> lck (mtx,std::defer_lock);
            lck.lock();
           std::cout<<"GET\n";
            return m_so;
        }
        void Reload()
        {
            std::unique_lock<std::mutex> lck (mtx,std::defer_lock);
            lck.lock();
            m_so->Close();
            if(pre == 1) {
                if(access(oldpth.c_str(),0) == 0){
                    std::cout<<"RELOAD 0\n";
                    pre = 0;
                    m_so.reset(new LoadSo(oldpth.c_str()));
                }
            } else {
                if(access(newpth.c_str(),0) == 0) {

                    std::cout<<"RELOAD 1\n";
                    pre = 1;
                    m_so.reset(new LoadSo(newpth.c_str()));
                }
            }
            lck.unlock();
        }
    protected:
        DynamicSo_ptr m_so;
        std::mutex mtx;
        int pre;
        string oldpth = "./test_old.so";
        string newpth = "./test_new.so"; 
};
void Say::Sth(const std::string &str)
{
    std::cout<< str << std::endl;
}
void test()
{
    for(int i = 0; i < 100; i++)
    {
        sleep(1);
        DoSth::getInstance().Reload();
    }
}
void test2()
{
    for(int i = 0; i < 100; i++)
    {
        sleep(1);
        DoSth::getInstance().Get()->run("12");
    }
}
int main()
{
    std::cout<<"run\n";
    std::thread thread1(test2);
    std::thread thread2(test);
//    pthread_t thread1;
//    pthread_t thread2;
//    int err = pthread_create(&thread1, NULL, test, NULL);
//    if(err < 0){
//        std::cout<<"thread1 error\n";
//        return 0;
//    }
//    err = pthread_create(&thread2, NULL, test2, NULL);
//    pthread_join(thread1, NULL);
//    pthread_join(thread2, NULL);
    thread1.join();
    thread2.join();
}
