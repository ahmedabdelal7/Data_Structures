using System;


class AdvancedArrayOperations
{
    static void Main()
    {
        // Initializing an array
        int[] numbers = { 5, 3, 1, 4, 2 };


        // Sorting the array
        Array.Sort(numbers);
        
        
        // Display the sorted array
        Console.WriteLine("Sorted array:");
        foreach (int number in numbers)
        {
            Console.WriteLine(number);
        }


        // Searching for an element, this will return the index for the element you searched for.
        int index = Array.IndexOf(numbers, 4);
        Console.WriteLine("\nIndex of 4: " + index);
        Console.ReadKey();
    }
}
