using colAias  = System.Collections;
namespace System
{
	class TestClass
	{
		static void Main()
		{
			// searching the alias:
			colAias::Hashtable test = new colAias::Hashtable();

			// Add items to the table.
			test.Add("A", "1");
			test.Add("B", "2");
			test.Add("C", "3");

			foreach (string name in test.Keys)
			{
				// Searching the global namespace:
				global::System.Console.WriteLine(name + ' ' + test[name]);
			}
		}
	}
}