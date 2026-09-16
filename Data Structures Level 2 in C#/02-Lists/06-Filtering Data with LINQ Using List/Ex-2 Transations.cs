using System;
using System.Collections.Generic;
using System.Linq;

class Program
{
    static void Main()
    {
        //رقم موجب = Deposit
        //رقم سالب = Withdrawal
        List<decimal> transactions = new List<decimal>
        {
            2500m,
            -500m,
            1200m,
            -150m,
            3000m,
            -750m,
            450m,
            -100m,
            1800m,
            600m
        };

        //Display All Transaction:
        Console.WriteLine($"All Transaction: " + string.Join(" | ",transactions) );

        // Display all deposit transactions
        Console.WriteLine($"\nDeposit Trans: " + string.Join(" | ",
            transactions.Where((t) => t > 0)
        ));

        // Display all withdrawal transactions
        Console.WriteLine($"\nWithdraw Trans: " + string.Join(" | ",
            transactions.Where((t) => t < 0)
        ));

        // Display deposits greater than 1500
        Console.WriteLine($"\nDeposits greater than 1500: " + string.Join(" | ",
            transactions.Where(t => t > 1500) 
        ));

        // Display withdrawals greater than 300 in absolute value
        Console.WriteLine($"\nWithdrawals greater than 300: "+ string.Join(" | ",
            transactions.Where(t => t < 0 && Math.Abs(t) > 300 )
        ));

        // Display transactions between -500 and 2000
        Console.WriteLine("\nTransactions Between -500 and 2000: "+string.Join(" | ",
            transactions.Where(t => t <= 2000 && t >= -500)            
        ));

        // Calculate the total amount of deposits
        Console.WriteLine("\nTotal Of All Deposits: " + 
            transactions.Where(t => t > 0).Sum()
        );

        // Count the number of withdrawal transactions
        Console.WriteLine("\nTotal Of All Withdrawals: " +
            transactions.Where(t => t < 0).Count()
        );

        // Display transactions with an absolute value of at least 1000
        Console.WriteLine("\nTransactions with an absolute value of at least 1000: ");

        transactions
            .Where(t => Math.Abs(t) >= 1000)
            .ToList()
            .ForEach(t => Console.WriteLine(t));


        Console.ReadKey();

    }
}