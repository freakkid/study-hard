using System;

class MyClass
{
    private int num = 0;
    private int Num
    {
        set
        {
            num=value;
        }
    }
}

class MyClassDerived : MyClass
{
    public int Num
    {
        get
        {
            return num;
        }
    }
}

class Test
{
    public static void Main()
    {
        MyClassDerived MyObject = new MyClassDerived();
        // MyObject.Num = 1;错误
        ((MyClass)MyObject).Num = 1;
    }
}