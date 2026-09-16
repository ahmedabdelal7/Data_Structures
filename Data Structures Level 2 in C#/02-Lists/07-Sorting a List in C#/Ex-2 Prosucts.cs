using System;
using System.Collections.Generic;
using System.Linq;

class Program
{
    class Product
    {
        public string Name { get; set; }
        public string Category { get; set; }
        public decimal Price { get; set; }
        public int Stock { get; set; }

        public Product(string name, string category, decimal price, int stock)
        {
            Name = name;
            Category = category;
            Price = price;
            Stock = stock;
        }
    }
    static void Main()
    {
        List<Product> products = new List<Product>
        {
            new Product("Laptop", "Electronics", 35000m, 5),
            new Product("Mouse", "Accessories", 750m, 20),
            new Product("Keyboard", "Accessories", 1200m, 12),
            new Product("Monitor", "Electronics", 8500m, 7),
            new Product("Headset", "Accessories", 2500m, 3),
            new Product("Printer", "Electronics", 6200m, 0),
            new Product("Webcam", "Accessories", 1800m, 10)
        };

        // Display all products
        Console.WriteLine("All Products: ");
        products.ForEach(p =>
        {
            Console.WriteLine($"{p.Name} - {p.Category} - {p.Price} - Stock = {p.Stock}");
        });


        // Display products sorted by price from lowest to highest
        Console.WriteLine("\nAll Products Sorted From Lowest To Highest: ");
        products.OrderBy(p => p.Price)
            .ToList()
            .ForEach(p =>
            {
                Console.WriteLine($"{p.Name} - {p.Category} - {p.Price} - Stock = {p.Stock}");
            });


        Console.WriteLine("\nAll Available products costing more than 2000 Sorted DESC: ");
        // Display available products costing more than 2000, sorted by price descending
        products.Where(p => (p.Stock > 0 && p.Price > 2000))
            .OrderByDescending(p => p.Price)
            .ToList()
            .ForEach(p =>
            {
                Console.WriteLine($"{p.Name} - {p.Category} - {p.Price} - Stock = {p.Stock}");
            });

        // Calculate the total value of all products currently in stock
        decimal totalValue =  products.Where(p => p.Stock > 0)
            .Sum(p => p.Price * p.Stock);


        Console.WriteLine($"\nTotal Value Of All Products = {totalValue}");




        Console.ReadKey();

    }
}