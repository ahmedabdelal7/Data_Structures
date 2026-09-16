using System;
using System.Collections.Generic;


class Program
{
    static void Main()
    {
        // List initialization
        List<int> numbers = new List<int> { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};


        // Adding an element at the end
        numbers.Add(11); // o(1)
        Console.WriteLine("After adding 11: " + string.Join(", ", numbers));

        //When adding at the end of list then its O(1) otherwise its O(n)
        //because you have to shift elements if an element is added in middle of list for example.
        // Inserting an element at a specific position
        numbers.Insert(0, 0); // o(n)
        Console.WriteLine("After inserting 0 at the beginning: " + string.Join(", ", numbers));


        // Inserting multiple elements
        numbers.InsertRange(5, new List<int> { 55, 56 });
        Console.WriteLine("After inserting 55 and 56 at index 5: " + string.Join(", ", numbers));


        // Waiting for a key press
        Console.ReadKey();
    }
}