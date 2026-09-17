using System;
using System.Collections.Generic;

class Program
{
    static void Main()
    {
        Dictionary<string, int> inventory = new Dictionary<string, int>
        {
            { "Laptop", 10 },
            { "Mouse", 25 },
            { "Keyboard", 15 },
            { "Monitor", 8 },
            { "Headset", 20 }
        };

        // Display the quantity of the Keyboard and handle if it does not exist.
        if (inventory.TryGetValue("Keyboard",out int quantity))
        {
            Console.WriteLine($"Keyboard quantity : {quantity}");
        }
        else
        {
            Console.WriteLine("Keyboard is not founded");
        }

        // Add the Webcam with a quantity of 12 and confirm the addition.
        inventory.Add("Webcam", 12);
        Console.WriteLine("Webcam Added Successfully");

        // Update the Mouse quantity to 30 and display all products.
        inventory["Mouse"] = 30;

        Console.WriteLine("\nDic after changing mouse quantity from 25 to 30: ");

        foreach (KeyValuePair<string, int> item in inventory)
        {
            Console.WriteLine($"{item.Key} quantity: {item.Value}");
        }


        // Remove the Monitor and display the updated inventory.
        if (inventory.Remove("Monitor"))
        {
            Console.WriteLine("\nMonitor removed successfully.");
        }else
            Console.WriteLine("\nFailed to remove, Monitor is not founded!");

        foreach (KeyValuePair<string, int> item in inventory)
        {
            Console.WriteLine($"{item.Key} quantity: {item.Value}");
        }


        // Search for the Printer and handle if it does not exist.
        if (inventory.TryGetValue("Printer", out int q))
        {
            Console.WriteLine($"\nPrinter quantity : {q}");
        }
        else
        {
            Console.WriteLine("\nPrinter is not founded");
        }


        Console.ReadKey();
    }
}