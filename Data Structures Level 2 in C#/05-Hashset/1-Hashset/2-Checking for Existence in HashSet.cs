using System;
using System.Collections.Generic;


class Program
{
    static void Main()
    {
        // Creating and populating a HashSet
        HashSet<string> fruits = new HashSet<string> { "Apple", "Banana", "Cherry" };


        // Checking if "Apple" is in the HashSet
        if (fruits.Contains("Apple"))
        {
            Console.WriteLine("Apple is in the HashSet");
        }
        else
        {
            Console.WriteLine("Apple is not in the HashSet");
        }
    }
}
