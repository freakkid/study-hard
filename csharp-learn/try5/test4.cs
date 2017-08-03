using System;

class Test
{
    static void F()
    {
        Console.WriteLine("F()");
    }
    static void F(int x)
    {
        Console.WriteLine("F(int x)");
    }
    static void F(double x)
    {
        Console.WriteLine("F(double x)");
    }
    static void F(object x)
    {
        Console.WriteLine("F(object x)");
    }
    static void F(double x, double y)
    {
        Console.WriteLine("F(double x, double y)");
    }
    
    static void Main()
    {
        F();
        F(1);
        F(1.0);
        F("ieh");
        F(2.4, 5.6);
    }
}
