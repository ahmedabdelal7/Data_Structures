using System;
using System.Collections.Generic;
using System.Linq;

class Program
{
    static void Main()
    {
        HashSet<string> tags = new HashSet<string>
        {
            "CSharp",
            "DotNet",
            "SQL",
            "LINQ",
            "EntityFramework",
            "ASP.NET",
            "Git",
            "GitHub",
            "CSharp",
            "SQL"
        };


        // Display the number of unique tags.
        Console.WriteLine($"Unique Tags : {tags.Count}");
        Console.WriteLine();

        Console.WriteLine("Display tags containing more than 4 characters.");
        // Display tags containing more than 4 characters.
        var filteredTags = tags.Where(t => t.Length > 4);
        foreach (var tag in filteredTags)
            Console.WriteLine(tag);
        Console.WriteLine();

        Console.WriteLine("Display all tags in uppercase and sorted alphabetically.");
        // Display all tags in uppercase and sorted alphabetically.
        var sortedTags = tags.Select(t => t.ToUpper()).OrderBy(t => t);
        foreach(var tag in sortedTags)
            Console.WriteLine(tag);
        Console.WriteLine();

        // Display tags containing the text "Net".
        Console.WriteLine("Display tags containing the text \"Net\".");
        var tagsContainNet = tags.Where(t => t.Contains("Net"));
        foreach (var tag in tagsContainNet)
            Console.WriteLine(tag);
        Console.WriteLine();

        // Remove tags containing "Git" and display the remaining tags.
        Console.WriteLine("Remove tags containing \"Git\" and display the remaining tags.");
        tags.RemoveWhere(t => t.Contains("Git"));

        foreach (var tag in tags)
            Console.WriteLine(tag);


        Console.ReadKey();  
    }
}