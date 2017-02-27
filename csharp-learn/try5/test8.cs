// 类似c或c++中函数的指针
// 是存有对某个方法的引用的一种类型变量
// 特别用于实现事件和回调方法
using System;

// 声明委托
delegate int NumberChanger(int n);

namespace DelegateApp1
{
    class TestDelegate
    {
        static int num = 10;
        public static int AddNum(int p)
        {
            num += p;
            return num;
        } 
        
        public static int MultNum(int q)
        {
            num *= q;
            return num;
        }

        public static int getNum()
        {
            return num;
        }

        static void Main(string[] args)
        {
            // 创建委托实例
            NumberChanger nc1 = new NumberChanger(AddNum);
            NumberChanger nc2 = new NumberChanger(MultNum);

            // 使用委托对象调用方法
            nc1(25);
            Console.WriteLine("Value of Num : {0}", getNum());
            nc2(5);
            Console.WriteLine("Value of Num : {0}", getNum());
            Console.ReadKey();
        }

    }


}
