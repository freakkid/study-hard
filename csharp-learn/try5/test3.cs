using System;

abstract class BaseClass
{
    // 虚方法
    public virtual void VirtualMethod()
    {
        Console.WriteLine("BaseClass.VirtualMethod");
    }
    // 抽象方法
    public abstract void AbstractMethod();
}

class SubClass : BaseClass
{
    // 重写虚方法
    public override void VirtualMethod()
    {
        Console.WriteLine("SubClass.VirtualMethod");
    }
    public override void AbstractMethod()
    {
        Console.WriteLine("重写抽象方法");
    }
}

class Test
{
    static void Main()
    {
        // 声明类型为基类， 实际类型为子类
        // 实际类型决定调用子类还是父类方法
        BaseClass baseClass = new SubClass();
        baseClass.VirtualMethod();
        baseClass.AbstractMethod();
    }
}