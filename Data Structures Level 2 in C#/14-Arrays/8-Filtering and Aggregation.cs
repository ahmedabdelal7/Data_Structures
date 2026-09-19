using System;
using System.Linq;


class AdvancedLINQFilteringAndAggregation
{
    static void Main()
    {
        // Array of numbers
        int[] numbers = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };


        // Filtering to get only even numbers
        var evenNumbers = numbers.Where(n => n % 2 == 0);


        // Aggregating - calculating the sum of even numbers
        int sumOfEvenNumbers = evenNumbers.Sum();


        // Displaying the results
        Console.WriteLine("Even Numbers:");
        foreach (var num in evenNumbers)
        {
            Console.Write(num + " ");
        }
        Console.WriteLine($"\nSum of Even Numbers: {sumOfEvenNumbers}");
        Console.ReadKey();
    }
}
