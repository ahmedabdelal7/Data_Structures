using System;
using System.Collections.Generic;


class Program
{
    static void Main()
    {

        List<string> customers = new List<string>
        {
            "Ahmed",
            "Mohamed",
            "Omar",
            "Youssef"
        };

        //New Customer arrived, add him to the end of queue :
        customers.Add("Khaled");

        Console.WriteLine($"List After Insert Khaled at end: \n{string.Join(" | ",customers)}");

        //New VIP Customer arrived, add him to front of queue :
        customers.Insert(0, "Ali");
        Console.WriteLine($"List After Insert Ali at front: \n{string.Join(" | ",customers)}");

        //Customers has arrived:
        customers.InsertRange(3,new List<string> { "Sara", "Hany"});
        Console.WriteLine($"List After Insert (Sara, Hany) after Mohamed:\n{string.Join(" | ",customers)}");



        // Waiting for a key press
        Console.ReadKey();
    }
}