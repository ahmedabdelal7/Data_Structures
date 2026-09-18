using System;
using System.Collections.Generic;
using System.Linq;

class Program
{
    static void Main()
    {
        Dictionary<string, int> sales = new Dictionary<string, int>
        {
            { "Laptop", 12 },
            { "Mouse", 35 },
            { "Keyboard", 20 },
            { "Monitor", 8 },
            { "Headset", 27 },
            { "Webcam", 15 },
            { "Printer", 5 },
            { "Tablet", 18 }
        };

        Dictionary<string, string> categories = new Dictionary<string, string>
        {
            { "Laptop", "Electronics" },
            { "Mouse", "Accessories" },
            { "Keyboard", "Accessories" },
            { "Monitor", "Electronics" },
            { "Headset", "Accessories" },
            { "Webcam", "Accessories" },
            { "Printer", "Office" },
            { "Tablet", "Electronics" }
        };

        // Update Laptop, Mouse, and Printer sales, then display their new quantities.
        /*
            Laptop: subtract 3
            Mouse: subtract 10
            Printer: subtract 2
        */

        sales["Laptop"] -= 3;
        sales["Mouse"] -= 10;
        sales["Printer"] -= 2;

        Console.WriteLine("Dictionary After Updated Products Sales:");
        DisplayDictionary(sales);

        // Calculate and display the total, average, highest, and lowest sales.
        double totalSales = sales.Sum(s => s.Value);
        double avgSales = sales.Average(s => s.Value);
        int highestSale = sales.Max(s => s.Value);
        int lowestSale = sales.Min(s => s.Value);

        Console.WriteLine($"\nTotal sales: {totalSales}");
        Console.WriteLine($"Average sales: {avgSales}");
        Console.WriteLine($"Highest sale: {highestSale}");
        Console.WriteLine($"Lowest sale: {lowestSale}");

        // Display products with sales above 15, sorted from highest to lowest sales.
        var filteredProducts = sales.Where(s => s.Value > 15).OrderByDescending(s => s.Value);
        Console.WriteLine();
        foreach (var kvp in filteredProducts)
        {
            Console.WriteLine($" - {kvp.Key}: {kvp.Value}");
        }
        Console.WriteLine();

        // Group products by category and display the total sales for each category.
        var groupedProducts = categories.GroupBy(c => c.Value);

        foreach (var group in groupedProducts)
        {
            int totalSales1 = group.Sum(product =>
                sales.TryGetValue(product.Key, out int quantity) ? quantity : 0);

            Console.WriteLine($"Category: {group.Key}");
            Console.WriteLine($"Total Sales: {totalSales1}");
        }
        Console.WriteLine();

        // Display products with sales above 10, including category and sales, sorted by category and name.
        var groupedProducts1 = categories
            .OrderBy(c => c.Value)
            .GroupBy(c => c.Value);

        foreach (var group in groupedProducts1)
        {
            foreach (var product in group.OrderBy(p => p.Key))
            {
                if (sales.TryGetValue(product.Key, out int sale) && sale > 10)
                {
                    Console.WriteLine(
                        $"Product: {product.Key}, Category: {product.Value}, Sales: {sale}");
                }
            }
        }
        Console.ReadKey();

    }
    static void  DisplayDictionary(Dictionary<string,int> dictionary)
    {
        foreach (var kvp in dictionary)
        {
            Console.WriteLine($" - {kvp.Key}: {kvp.Value}");
        }
    }
}