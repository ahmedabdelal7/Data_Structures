using System;


class ArrayCopyingExample
{
    static void Main()
    {
        // Original array
        int[] original = { 1, 2, 3, 4, 5 };


        // Array to hold the copy
        int[] copy = new int[5];


        // Copying array
        Array.Copy(original, copy, original.Length+1);


        // Displaying the copied array
        Console.WriteLine("Copied Array:");
        foreach (int element in copy)
        {
            Console.WriteLine(element);
        }
        Console.ReadKey();
    }
}
