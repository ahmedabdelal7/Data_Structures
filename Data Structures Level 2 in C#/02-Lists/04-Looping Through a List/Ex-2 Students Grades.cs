using System;
using System.Collections.Generic;


internal class Program
{
    static void DisplayGrades(List<int> grades)
    {
        Console.WriteLine($"Grades Are: {string.Join(", ",grades)}");
    }

    static void Main(string[] args)
    {
        List<int> grades = new List<int>
        {
            45, 78, 92, 61, 35, 88, 50, 73
        };

        // Display the total number of students
        DisplayGrades(grades);
        Console.WriteLine($"Total Number Of Students: {grades.Count}");


        // Display each student's grade with their student number
        for (int i = 0; i < grades.Count; i++)
        {
            Console.WriteLine($"Student {i+1}: {grades[i]}");
        }

        // Display only passing grades
        Console.WriteLine("Passing grades:");
        grades.ForEach(g => {
            if (g > 50)
                Console.WriteLine(g);
        });

        // Display each grade with its pass or fail status
        grades.ForEach(g =>
        {
            Console.WriteLine($"{g} - {(g > 50 ? "Passed" : "Failed")}");
        });

        // Calculate the total of all grades using for loop

        int total = 0; 
        for (int i = 0;i < grades.Count;i++)
        {
            total += grades[i];
        }

        Console.WriteLine($"Total Grades: {total}");


        // Count the number of students who passed using foreach
        int passedCount = 0;
        //grades.ForEach(g =>
        //{
        //    passedCount += (g > 50 ? 1 : 0);
        //});
        foreach (int grade in grades)
        {
            passedCount += (grade > 50 ? 1 : 0);
        }

        Console.WriteLine($"Total Passed Students Count: {passedCount}");



        // Waiting for a key press before closing the console window
        Console.ReadKey();
    }
}
