/**
 * \brief sample07 C++单例设计模式 */
#include <iostream>

using namespace std;
/** 懒汉式 */
/***************************************************************************/
class Singleton {
private:
    Singleton() {
        cout << "调用 Singleton 构造函数" << endl;
    }
public:
    static Singleton* getInstance() {
        if (!singleton_) {
            singleton_ = new Singleton();
        }
        return singleton_;
    }
    static void freeInstance() {
        if(singleton_) {
            delete singleton_;
            singleton_ = nullptr;
        }
    }
private:
    static Singleton* singleton_;
};
Singleton* Singleton::singleton_ = nullptr;
/***************************************************************************/

/** 饿汉式 */
/***************************************************************************/
class Singleton02 {
private:
    Singleton02() {}
public:
    static Singleton02* getInstance() {
        return singleton02_;
    }
    static void freeInstance() {
        if(singleton02_) {
            delete singleton02_;
            singleton02_ = nullptr;
        }
    }
private:
    static Singleton02* singleton02_;
};
Singleton02* Singleton02::singleton02_ = new Singleton02();
/***************************************************************************/


/** 单例设计模式，类似一个工厂，传入一个类，该类即为单例设计模式类
 *  copied for muduo
 *  https://github.com/chenshuo/muduo/blob/master/muduo/base/Singleton.h */
#if 0
namespace muduo
{
    namespace detail
    {
// This doesn't detect inherited member functions!
// http://stackoverflow.com/questions/1966362/sfinae-to-check-for-inherited-member-functions
        template<typename T>
        struct has_no_destroy
        {
            template <typename C> static char test(decltype(&C::no_destroy));
            template <typename C> static int32_t test(...);
            const static bool value = sizeof(test<T>(0)) == 1;
        };
    }  // namespace detail
    template<typename T>
    class Singleton : noncopyable
    {
    public:
        Singleton() = delete;
        ~Singleton() = delete;

        static T& instance()
        {
            pthread_once(&ponce_, &Singleton::init);
            assert(value_ != NULL);
            return *value_;
        }
    private:
        static void init()
        {
            value_ = new T();
            if (!detail::has_no_destroy<T>::value)
            {
                ::atexit(destroy);
            }
        }

        static void destroy()
        {
            typedef char T_must_be_complete_type[sizeof(T) == 0 ? -1 : 1];
            T_must_be_complete_type dummy; (void) dummy;

            delete value_;
            value_ = NULL;
        }

    private:
        static pthread_once_t ponce_;
        static T*             value_;
    };

    template<typename T>
    pthread_once_t Singleton<T>::ponce_ = PTHREAD_ONCE_INIT;

    template<typename T>
    T* Singleton<T>::value_ = NULL;

}  // namespace muduo
#endif

int main() {
    // Singleton p0;  /** 错误，构造函数不可调用 */
    Singleton* p1 = Singleton::getInstance();
    Singleton* p2 = Singleton::getInstance();
    /** p1 = 0x55eff1152eb0, p2 = 0x55eff1152eb0 */
    cout << "p1 = " << p1 << ", p2 = " << p2 << endl;
    Singleton::freeInstance();

    Singleton02* p3 = Singleton02::getInstance();
    Singleton02* p4 = Singleton02::getInstance();
    /** p3 = 0x55ba33b23eb0, p4 = 0x55ba33b23eb0 */
    cout << "p3 = " << p3 << ", p4 = " << p4 << endl;
    Singleton02::freeInstance();
    return 0;
}
