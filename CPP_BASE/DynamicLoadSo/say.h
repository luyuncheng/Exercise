#include "singleton.h"
#include <string>
using namespace std;
class Say : public Singleton<Say>
{
    public:
        void Sth(const std::string &str);
};
