using System;

namespace MyTest
{
    public class MyClass
    {
        static void Main()
        {
            Random ran = new Random();
            int n = ran.Next(1, 4);
            Console.WriteLine(n);
            Console.Write(String.Empty + "lalala");
        }
    }
}