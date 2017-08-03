using System;
using MyMethods;

class MyClient
{
    public static void Main(string[] args)
    {
        Console.WriteLine("Calling methods from MyLibrary.DLL:");
        if (args.Length != 2)
        {
            Console.WriteLine("Usage: MyClient <num1> <num2>");
            return;
        }
        long num1 = long.Parse(args[0]);
        long num2 = long.Parse(args[1]);
        long sum = AddClass.Add(num1, num2);
        long product = MultiplyClass.Multiply(num1, num2);
        Console.WriteLine("The sum of {0} and {1} is {2}", num1, num2, sum);
        Console.WriteLine("The product of {0} and {1} is {2}", num1, num2, product);
    }
}