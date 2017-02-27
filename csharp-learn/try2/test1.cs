// 字符串
using System;

public class Test
{
    static void Main()
    {
        String name = "[ 小明";
        // 合并字符串
        name = name + "20岁";
        name = name + "男生     ]";
        Console.WriteLine(name);
        name = name.Replace(' ', '-');
        Console.WriteLine(name);
    }
}