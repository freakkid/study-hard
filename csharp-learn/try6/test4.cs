using System;

namespace MyTry
{
    public delegate void MyDelegate();
    class MyClass
    {
        public static void Process()
        {
            Console.WriteLine("Begin()");
            Console.WriteLine("End()");
        }
    }
    class Test
    {
        static void Main()
        {
            MyDelegate myDelegate = new MyDelegate(MyClass.Process);
            myDelegate();
        }
    }
}