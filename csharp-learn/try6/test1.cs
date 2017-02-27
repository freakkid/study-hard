using System;
using System.IO;

namespace DelegateApp1
{
    class PrintString
    {
        static FileStream fs;
        static StreamWriter sw;

        // ί������
        public delegate void printString(string s);

        // �÷�����ӡ������̨
        public static void WriteToStreen(string str)
        {
            Console.WriteLine("The String is: {0}", str);
        }

        // �÷�����ӡ���ļ�
        public static void WriteToFile(string s)
        {
            fs = new FileStream("msg.txt", FileMode.Append, FileAccess.Write);
            sw = new StreamWriter(fs);
            sw.WriteLine(s);
            sw.Flush();
            sw.Close();
            fs.Close();
        }

        // �÷�����ί����Ϊ��������ʹ�������÷���
        public static void sendString(printString ps)
        {
            ps("Hello World");
        }

        static void Main(string[] args)
        {
            printString ps1 = new printString(WriteToStreen);
            printString ps2 = new printString(WriteToFile);
            sendString(ps1);
            sendString(ps2);
            Console.ReadKey();
        }
    }
}
