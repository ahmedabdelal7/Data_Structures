using System;


class CommonArrayOperations
{
    static void Main()
    {
        // Initializing an array
        int[] numbers = { 1, 2, 3, 4, 5 };


        // Accessing and modifying elements
        numbers[0] = 10;


        // Using for loop for iteration
        for (int i = 0; i < numbers.Length; i++)
        {
            Console.WriteLine("Element at index " + i + ": " + numbers[i]);
        }
        Console.ReadKey();
    }
}
