using System;
using System.Collections;


class Program
{
    static void Main(string[] args)
    {
        ArrayList list = new ArrayList();
        list.Add(10);
        list.Add("Ahmed");
        list.Add(false);


        Console.WriteLine("Elements in ArrayList:");
        foreach (var item in list)
        {
            Console.WriteLine(item);
        }


        list.Remove(10); // Removing an element
        Console.WriteLine("After removing an element:");
        foreach (var item in list)
        {
            Console.WriteLine(item);
        }
        Console.ReadKey();
    }
}
