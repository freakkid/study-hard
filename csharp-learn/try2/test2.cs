using System;

public class Test
{
    static void Main()
    {
        System.Text.StringBuilder stringBuilder = 
                            new System.Text.StringBuilder();
        for (int i = 0; i < 1000; i++)
        {
            stringBuilder.Append(i.ToString() + "|");
        }
        Console.WriteLine(stringBuilder.ToString());
    }
}