#include "make_so.h"
extern "C"
{
    void Enter(const std::string &str)
    {
        Say::getInstance().Sth(str+ "def");
    }
}
