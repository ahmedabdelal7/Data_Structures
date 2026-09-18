using System;
using System.Collections.Generic;
using System.Linq;

class Program
{
    static void Main()
    {
        HashSet<string> mySkills = new HashSet<string>
        {
            "C#",
            ".NET",
            "SQL",
            "LINQ",
            "Entity Framework",
            "Git",
            "WinForms"
        };

        HashSet<string> jobSkills = new HashSet<string>
        {
            "C#",
            ".NET",
            "SQL",
            "Entity Framework",
            "REST API",
            "Docker",
            "Git"
        };
        // IntersectWith -> Items that exist in both sets
        // UnionWith -> All items in both sets + *in HashSet without redundant
        // ExceptWith -> (Difference) Items in set1 that not exist in set2
        // SymmetricExceptWith -> (Symmetric Difference) Items that exist in only one of tow sets

        // Display the skills that exist in both sets.

        Console.WriteLine("Display the skills that exist in both sets.");
        mySkills.IntersectWith(jobSkills);
        foreach (var skill in mySkills)
        {
            Console.WriteLine(skill);
        }
        Console.WriteLine();

        // Display the job skills that are missing from my skills.
        Console.WriteLine("Display the job skills that are missing from my skills.");
        jobSkills.ExceptWith(mySkills);

        foreach (var skill in jobSkills)
            Console.WriteLine(skill);
        Console.WriteLine();

        // Display my skills that are not required by the job.
        Console.WriteLine("Display my skills that are not required by the job.");
        mySkills.ExceptWith(jobSkills);
        foreach (var skill in mySkills)
            Console.WriteLine(skill);
        Console.WriteLine();

        // Display all unique skills from both sets.
        Console.WriteLine("Display all unique skills from both sets.");
        mySkills.UnionWith(jobSkills);
        foreach (var skill in mySkills)
            Console.WriteLine(skill);
        Console.WriteLine();

        // Display skills that exist in only one of the two sets.
        Console.WriteLine("Display skills that exist in only one of the two sets.");
        mySkills.SymmetricExceptWith(jobSkills);
        foreach(var skill in mySkills)
            Console.WriteLine(skill);

        Console.ReadKey();
    }
}