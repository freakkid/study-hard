using System.Diagnostics;
using System;
using System.Collections;


class MyTestClass
{
    static void Main()
    {
        int[] nArray = new int[5]{1,2,3,4,5};
        ArrayList nArraylist = new ArrayList();
        nArraylist.AddRange(nArray);



        for (int i = nArraylist.Count - 1; i >= 0; i--)
        {
            int n = (int)nArraylist[i];
            if (n == 5 || n == 4)
                nArraylist.RemoveAt(i);
            Debug.WriteLine(n.ToString());
            Console.WriteLine(n.ToString());
        }
        Console.WriteLine("--------------");
        foreach (int i in nArraylist)
        {
            Console.WriteLine(i.ToString());
        }
    }
}