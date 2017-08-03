using System;

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
            NumberChanger nc;
            NumberChanger nc1 = new NumberChanger(AddNum);
            NumberChanger nc2 = new NumberChanger(MultNum);
            
            nc = nc1;
            nc += nc2;
            // 使用委托对象调用方法
            nc(5);
            Console.WriteLine("Value of Num : {0}", getNum());
            Console.ReadKey();
        }
    }
}