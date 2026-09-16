using System;
using System.Collections.Generic;


class Program
{
    static void Main()
    {

        List<string> students = new List<string>
        {
            "Ahmed",
            "Mohamed",
            "Omar",
            "Ali",
            "Hassan"
        };


        Console.WriteLine($"List Before Editing Count = {students.Count}: {string.Join(", ", students)}");

        //Remove Omar from Course:
        students.Remove("Omar");
        Console.WriteLine($"List After Remove 'Omar' Count = {students.Count}: {string.Join(", ", students)}");


        //Remove The First Student:
        students.RemoveAt(0);
        Console.WriteLine($"List After Remove First Student Count = {students.Count}: {string.Join(", ", students)}");

        //Remove All Students There Name Starts With 'A':
        students.RemoveAll((s) => s.StartsWith("A"));
        Console.WriteLine($"List After Remove Students Start With 'A' Count = {students.Count}: {string.Join(", ", students)}");

        //At The End Of The Day, Remove All Students:
        students.Clear();
        Console.WriteLine($"List After Clear Count = {students.Count}: {string.Join(", ", students)}");


        // Waiting for a key press
        Console.ReadKey();
    }
}