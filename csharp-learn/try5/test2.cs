using System;
using System.Text;
public static class MyExtensions
{
    public static string UpperLower(this string str, bool upperFirst)
    {
        StringBuilder newString = new StringBuilder(str.Length);
        for (int i = 0; i < str.Length; i++)
        {
            newString.Append(upperFirst ? char.ToUpper(str[i] ):
                char.ToLower(str[i]));
            upperFirst = !upperFirst;
        }
        return newString.ToString();
    }

    static void Main()
    {
        string input = Console.ReadLine();
        Console.WriteLine("calling extension method for {0}: {1}", input, input);
    }
}

