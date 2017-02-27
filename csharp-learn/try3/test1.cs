using System.Diagnostics;
using System;
public class Test
{
	static void Main()
	{
		int[] nArray = new int[5]{2, 3, 4, 6, 7};
		Console.WriteLine("1.");
		foreach (int i in nArray)
		{
			nArray.Remove(i);
			Debug.WriteLine(i.ToString());
			Console.WriteLine(i.ToString());
		}

		Console.WriteLine("2.");
		for (int i = 0; i < nArray.Length; i++)
			Console.WriteLine(nArray[i].ToString());
		
		Console.WriteLine("\n3.");
		int nLength = nArray.Length; 
		for (int i = 0; i < nLength; i++)
			Console.WriteLine(nArray[i].ToString());
	}
}
