using System;
using System.Collections.Generic;
using System.Linq;


class Program
{
    static void Main()
    {
        // Creates and initializes a list of integers
        List<int> numbers = new List<int> { 44, 22, 55, 666, 9, -6, 345, 11, 3, 3 };


        // Contains: Checks if the list contains a specific value
        Console.WriteLine("List contains 9: " + numbers.Contains(9));


        // Exists: Checks if at least one element matches a condition
        Console.WriteLine("List contains negative numbers: " + numbers.Exists(n => n < 0));


        // Find: Returns the first element that matches a condition
        Console.WriteLine("First negative number: " + numbers.Find(n => n < 0));


        // FindAll: Returns all elements that match a condition
        Console.WriteLine("All negative numbers: " + string.Join(", ", numbers.FindAll(n => n < 0)));


        // Any: Checks if at least one element matches a condition
        Console.WriteLine("Any numbers greater than 100: " + numbers.Any(n => n > 100));


        // Waits for a key press before closing the console
        Console.ReadKey();
    }
}