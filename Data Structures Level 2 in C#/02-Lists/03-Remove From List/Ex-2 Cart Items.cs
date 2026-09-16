using System;
using System.Collections.Generic;


class Program
{
    static void Main()
    {
        //Shopping Cart:
        List<string> cart = new List<string>
        {
            "Laptop",
            "Mouse",
            "Keyboard",
            "Monitor",
            "Headset",
            "USB Cable"
        };

        // Clear() complexity -> value type -> O(1) 
        // Clear() complexity -> Reference type > O(n)

        Console.WriteLine($"Cart Before Editing Count = {cart.Count}: {string.Join(", ", cart)}");

        //Customer Cancelled 'Mouse':
        cart.Remove("Mouse");
        Console.WriteLine($"Cart After Cancel 'Mouse' Count = {cart.Count}: {string.Join(", ", cart)}");

        //Customer Removed First Item In cart:
        cart.RemoveAt(0);
        Console.WriteLine($"Cart After Remove First Item Count = {cart.Count}: {string.Join(", ", cart)}");

        //Remove all Items Contains "USB" or "Headset":
        cart.RemoveAll((item) => item.Contains("USB") || item.Contains("Headset"));
        Console.WriteLine($"Cart After Remove Items Contains \"USB\" or \"Headset\" Count = {cart.Count}: {string.Join(", ", cart)}");

        //Done Checkout now clear the cart:
        cart.Clear();
        Console.WriteLine($"Cart After Clear Count = {cart.Count}: {string.Join(", ", cart)}");


        // Waiting for a key press
        Console.ReadKey();
    }
}