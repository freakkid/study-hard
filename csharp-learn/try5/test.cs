using System;

class Test
{
    static void ValueParameter(int value)
    {
        value = 100;
    }
    static void RefParameter(ref int value)
    {
        value = 200;
    }
    static void OutParameter(out int value)
    {
        value = 100;
    }
    static void ParameterArray(params int[] array)
    {
        for (int i = 0; i < array.Length; i++)
        {
            Console.WriteLine(array[i]);
        }
    }

    static void Main()
    {
        int valueParameter = 0;
        int refParameter = 100;
        int outParameter;
        ValueParameter(valueParameter);
        RefParameter(ref refParameter);
        OutParameter(out outParameter);
        Console.WriteLine(valueParameter);
        Console.WriteLine(refParameter);
        Console.WriteLine(outParameter);
        int[] array = new int[4]{1, 2, 3, 4};
        ParameterArray(array);
    }
}
