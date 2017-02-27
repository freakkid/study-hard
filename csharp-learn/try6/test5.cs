using System;

namespace MyDelegate
{
    public class MyClass
    {
        public delegate void LogHandler(string message);

        public void Process(LogHandler logHandle)
        {
            if (logHandle != null)
            {
                logHandle("Begin");
            }
            
            if (logHandle != null)
            {
                logHandle("End");
            }    
        }
    }

    public class TestApplication
    {
        static void Logger(string s)
        {
            Console.WriteLine(s);
        }
        static void Main(string[] args)
        {
            MyClass myClass = new MyClass();
            MyClass.LogHandler mylog = new MyClass.LogHandler(Logger);
            myClass.Process(mylog);
        }
    }

}