using System;


class ArraysIntroduction
{
    static void Main()
    {
        // Declaring an integer array
        int[] numbers = new int[5];

        // Initializing an array with values
        string[] names = { "Alice", "Bob", "Charlie" };

        // Display the names
        foreach (string name in names)
        {
            Console.WriteLine(name);
        }
        Console.ReadKey();
    }
}
