using System;

class BaseClass
{
    public String Name = String.Empty;
    public Int32 Age = 0;
}
class SubClass : BaseClass
{
    public void ShowData()
    {
        Console.WriteLine("姓名：{0}\n年龄：{1}", base.Name, base.Age);
    }
}
class Test
{
    static void Main()
    {
        SubClass subClass = new SubClass();
        subClass.Name = "张狗蛋";
        subClass.Age = 20;
        subClass.ShowData();
    }
}