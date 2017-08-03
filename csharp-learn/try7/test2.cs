using System;
using System.Linq;

namespace MyList
{
    public class MyClass
    {
        static void Main()
        {
            int[] numbers = {1, 4, 6, 7, 8, 4, 8, 0, 2, 3, 5, 7, 1, 3};
            int first = numbers.First();
            Console.WriteLine(first);
            // 第一个满足条件的元素
            int firstLagerFive = numbers.First(number => number > 5);
            Console.WriteLine(firstLagerFive);
        }
    }
}