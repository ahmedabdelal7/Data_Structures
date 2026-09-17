using System;
using System.Collections.Generic;
using System.Linq;

class Program
{
    static void Main()
    {
        // List initialization
        List<int> numbers = new List<int> { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };


        // Converting the list to an array
        int[] numbersArray = numbers.ToArray();
        Console.WriteLine("Array elements: " + string.Join(", ", numbersArray));


        // Converting the Array to an List
        List<int> numbersList =  numbersArray.ToList();
        Console.WriteLine("List elements: " + string.Join(", ", numbersList));



        Console.ReadKey();
    }
}

