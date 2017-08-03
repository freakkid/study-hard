using System;

class Test
{
    public static void StaticMethod()
    {
        Console.WriteLine("我是静态方法");
    }
    public void InstanceMethod()
    {
        Console.WriteLine("我是实例方法");
    }
    static void Main()
    {
        Test.StaticMethod();
        Test test = new Test();
        test.InstanceMethod();
    }
}