namespace first {  // 命名空间声明
  namespace second {  // 命名空间的嵌套
    void func();
  }
}
// 内联命名空间（C++11）
// 内联命名空间会被视为父命名空间的成员，first::func()将调用
// namespace为secondNew下的func
// 可以将内联命名空间作为版本控制机制，以管理对库的公共接口的更改
inline namespace secondNew {
  void func();
}
// 嵌套命名空间（C++17）
// 等同于 namespace muduo { namespace net {}}
namespace muduo::net {}
// 命名空间别名
namespace a_very_long_namespace_name { class Foo {}; }
namespace AVLNN = a_very_long_namespace_name;
void Bar(AVLNN::Foo foo){ }
// 匿名空间
// 使变量声明对于其他文件中的代码不可见
namespace  // 注意，没有名字
{
    int MyFunc(){}
}
