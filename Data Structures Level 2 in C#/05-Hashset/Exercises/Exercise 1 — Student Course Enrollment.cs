using System;
using System.Collections.Generic;
using System.Linq;

class Program
{
    static void Main()
    {
        HashSet<string> students = new HashSet<string>
        {
            "Ahmed",
            "Omar",
            "Mona",
            "Sara",
            "Ali",
            "Youssef"
        };

        // Add Hany and display the total number of students.
        students.Add("Hany");

        Console.WriteLine("Students After Add 'Hany': ");
        foreach (var student in students)
        {
            Console.WriteLine(student);
        }
        Console.WriteLine();


        // Try to add Ahmed again and display whether the student was added.
        students.Add("Ahmed");

        Console.WriteLine("Students After Add 'Ahmed': ");
        foreach (var student in students)
        {
            Console.WriteLine(student);
        }
        Console.WriteLine();

        // Check whether Mona is enrolled and display the result.
        if (students.Contains("Mona"))
        {
            Console.WriteLine("Yes Mona is enrolled.");
        }else
            Console.WriteLine("No Mona is not enrolled.");
        Console.WriteLine();

        // Remove Omar and display all remaining students.
        students.Remove("Omar");

        Console.WriteLine("Students After Remove 'Omar': ");
        foreach (var student in students)
        {
            Console.WriteLine(student);
        }
        Console.WriteLine();

        // Display students whose names start with the letter A.
        Console.WriteLine("Students Starts With 'A':");
        foreach (var student in students)
            if(student.StartsWith("A"))
                Console.WriteLine(student);
        Console.WriteLine();


        // Display all students sorted alphabetically.
        Console.WriteLine("Students Ordered: ");
        foreach(var student in students.OrderBy(s =>s))
        {
            Console.WriteLine(student);
        }
        Console.WriteLine();

        // Display all student names in uppercase.
        foreach (var student in students)
        {
            Console.WriteLine(student.ToUpper());
        }

        Console.ReadKey();
    }
}