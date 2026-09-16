using System;
using System.Collections.Generic;
using System.Linq;

class Program
{
    
    static void Main()
    {
        List<decimal> sales = new List<decimal>
        {
            1200.50m,
            850.00m,
            2300.75m,
            450.25m,
            1750.00m,
            3200.50m,
            950.00m
        };

        //Display All Sales:
        Console.WriteLine($"Sales Are: {string.Join(" | ", sales)}\n");


        // Display the total number of sales
        int count = sales.Count();  
        Console.WriteLine($"Total Number Of Sales = {count}");

        // Calculate and display the total revenue
        decimal sum = sales.Sum();
        Console.WriteLine($"Total Revenue = {sum}");

        // Calculate and display the average sale amount
        decimal average = sales.Average();
        Console.WriteLine($"Average Sale Amount = {average}");

        // Display the smallest and largest sale amounts
        decimal smallestSaleAmount = sales.Min();
        decimal largestSaleAmount = sales.Max();

        Console.WriteLine($"Smallest Sale Amount = {smallestSaleAmount}");
        Console.WriteLine($"Largest Sale Amount = {largestSaleAmount}");


        // Display sales that are above the average
        Console.WriteLine("Sales that are above the average: ");
        foreach (int sale in sales)
        {
            if (sale > average)
                Console.WriteLine(sale);
        }

        // Count sales greater than 1000
        int salesGraterThan1000 = 0;
        foreach(int sale in sales)
        {
            if (sale > 1000)
                salesGraterThan1000++;

        }

        Console.WriteLine($"Sales Grater Than 1000 Is = {salesGraterThan1000}");

        //Statistics
        DisplaySalesStatistics(sales);

        Console.ReadKey();
    }
    static void DisplaySalesStatistics(List<decimal> sales)
    {
        //Total Sales: ...
        //Total Revenue: ...
        //Average Sale: ...
        //Minimum Sale: ...
        //Maximum Sale: ...
        Console.WriteLine("\n----------Sales Statistics--------");
        Console.WriteLine($"Total Sales: {sales.Count()}");
        Console.WriteLine($"Total Revenue: {sales.Sum()}");
        Console.WriteLine($"Average Sale: {sales.Average()}");
        Console.WriteLine($"Minimum Sale: {sales.Min()}");
        Console.WriteLine($"Maximum Sale: {sales.Max()}");


    }
}