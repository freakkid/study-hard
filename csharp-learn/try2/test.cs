using System;
public class Test
{
    static void Main()
    {
        // 元素个数为3的int类型数组
        int[] ages = new int[3];
        // 3 * 3的多维数组
        int[, ] i = new int[3, 3];
        // 交错数组
        int[][] j = new int[2][];
        j[0] = new int[2] {3, 4};
        j[1] = new int[3] {1,2,3};
        // 输出4
        Console.WriteLine(j[0][1]);
        Console.WriteLine(j[1][0]);
        Console.WriteLine(j[1][1]);
        Console.WriteLine(j[1][2]);
    }
}