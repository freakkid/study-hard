using System;

class A
{
    ~A()
    {
        Console.WriteLine("析构器执行");
    }
}
class Test
{
    static void Main()
    {
        A a = new A();
        a = null;
    }
}