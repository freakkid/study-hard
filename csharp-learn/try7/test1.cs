using System;

namespace MyTest
{
    public class MyClass
    {
        public static string Test(string s)
        {
            if (String.IsNullOrEmpty(s))
                return "is null or empty";
            else
                return String.Format("(\"{0}\") is neither null nor empty", s);
        }

        public static string FirstCharToUpper(string input)
        {
            if (String.IsNullOrEmpty(input))
                throw new ArgumentException("ARGH!");
            return input.First().ToString().ToUpper() + input.Substring(1);
        }
        
        static void Main()
        {
            // private enum animals = {dog, cat, pig};
            string teststring = "dog";
            // string first = teststring.First();
            Console.WriteLine(Test(teststring));
            Console.WriteLine(FirstCharToUpper(teststring));

        }
        
    }
}