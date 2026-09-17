using System;
using System.Collections.Generic;
using System.Linq;

class Program
{
    static void Main()
    {
        //Positive numbers = Deposits
        //Negative numbers = Withdrawals

        List<int> transactions = new List<int>
        {
            250, -100, 500, -50, 1200, 300, -250, 75, 900, -700
        };

        // Check if the transaction 1200 exists
        Console.WriteLine($"Is Transaction 1200 Exists: {transactions.Contains(1200)}");

        // Find the first withdrawal greater than 200 in absolute value
        Console.WriteLine($"First Withdrawal > 200 in Absolute: " +
            $"{transactions.Find(t => t < 0 && Math.Abs(t) > 200)}");

        // Find all transactions with an absolute value of at least 500 and sort them descending
        Console.WriteLine($"Transactions with an absolute value of at least 500 Desc: ");
            transactions.FindAll(t => Math.Abs(t) >= 500)
            .OrderByDescending(t => t)
            .ToList()
            .ForEach(t => Console.WriteLine(t));

        // Check if there is any suspicious withdrawal greater than 600
        Console.WriteLine($"Is There is any withdrawal > 600: " +
            $"{transactions.Any(t => t < 0 && Math.Abs(t) > 600)}"); 

        Console.ReadKey();
    }
}