#ifndef LOAD_SO_H
#define LOAD_SO_H
#include <iostream>
#include <memory>
#include <dlfcn.h>
#include <functional>
using namespace std;

class LoadSo
{
    typedef std::function<void*(const std::string &)> FUNC;
    typedef void (*Func)(const std::string &suid);
public:
    LoadSo(const char * so_file)
    {
        //load(so_file);
        Fload<void *(const string &)>(so_file);
    }

    void Close()
    {
        dlclose(m_handle);
    }

    void run( const std::string &str )
    {
        m_func(str);
    }
public:
    bool load(const char * so_file)
    {
        m_handle = dlopen(so_file, RTLD_LAZY);
        if (!m_handle) {
            std::string error("Cannot open library: ");
            throw std::runtime_error(error + dlerror());
            return false;
        }

        dlerror();
        m_func = (Func) dlsym(m_handle, "Enter");
        const char *dlsym_error = dlerror();
        if (dlsym_error) {
            dlclose(m_handle);
            std::string error("Cannot load symbol: ");
            throw std::runtime_error(error + dlsym_error);
            return false;
        }
        return true;
    }

    template< typename Signature>
        std::function<Signature> Dload(const char * so_file)
        {
            // only for static method
            m_handle = dlopen(so_file, RTLD_LAZY);
            if (!m_handle) {
                std::string error("Cannot open library: ");
                throw std::runtime_error(error + dlerror());
                return false;
            }
            dlerror();
            void* const result = dlsym(m_handle, "Enter");
            if(!result)
            {
                const char *dlsym_error =dlerror();
                if (dlsym_error) {
                    dlclose(m_handle);
                    std::string error("Cannot load symbol: ");
                    throw std::runtime_error(error + dlsym_error);
                    return false;
                }
            }
            return reinterpret_cast<Signature>(result);

        }

private:
    FUNC _func;
    Func m_func;
    void* m_handle;
};
typedef std::shared_ptr<LoadSo> DynamicSo_ptr;

#endif
