// button的click事件，
// 可以编写button_click等函数来作相应的驱动处理
// 事件与驱动函数对应关系是通过委托类来关联的
// 委托类似于c++中的函数指针
using System;
namespace MySample
{
    class TestClass
    {
        // 定义一个Delegate函数数据结构
        public delegate void GoDelegate();
        static void Main(string[] args)
        {
            // Delegates数据变量指向实例方法
            GoDelegate goDelegate = new GoDelegate(MyDelegateFunc);
            // 执行实例方法
            goDelegate();
            return;
        }

        public static void MyDelegateFunc()
        {
            Console.WriteLine("delegate function...");
        }
    }
}