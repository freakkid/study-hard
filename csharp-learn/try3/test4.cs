// get set 1.0
using System;
class MyClass
{
    int integer;
    public int Interger
    {
        get {return integer;}
        set {integer=value;}
    }
}

class Test
{
    public static void Main()
    {
        MyClass MyObject=new MyClass();
        Console.Write(MyObject.Interger);
        MyObject.Interger++;
        Console.WriteLine();
        Console.Write(MyObject.Interger);
    }
}