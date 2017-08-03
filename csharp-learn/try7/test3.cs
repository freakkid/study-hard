using System;

public class Example
{
    public static void Main()
    {
        String s = "aaaaabbbcccccccdd";
        Char charRange = 'b';
        int startIndex = s.IndexOf(charRange);
        int endIndex = s.LastIndexOf(charRange);
        int length = endIndex - startIndex + 1;
        // Console.WriteLine("{0}.Substring({1}, {2} = {3})",
        //                 s, startIndex, endIndex, s.Substring(0, length));
        bool test1 = s.Substring(0, 2).Equals("aa");
        Console.WriteLine(test1);
    }
}