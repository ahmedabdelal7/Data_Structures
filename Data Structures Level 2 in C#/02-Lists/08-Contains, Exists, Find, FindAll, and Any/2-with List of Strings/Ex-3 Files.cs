using System;
using System.Collections.Generic;
using System.Linq;

class Program
{
    static void Main()
    {
        List<string> files = new List<string>
        {
            "report.pdf",
            "report2.pdf",
            "photo.jpg",
            "program.cs",
            "database.sql",
            "notes.txt",
            "logo.png",
            "main.cs",
            "backup.sql",
            "presentation.pptx",
            "resume.pdf",
            "data.csv",
            "config.json"
        };

        // Check if "database.sql" exists in the file list
        Console.WriteLine($"Is 'database.sql' Exists: " +
            $"{files.Contains("database.sql")}");

        // Find the first PDF file
        Console.WriteLine($"The first PDF file: " +
            $"{files.Find(f => f.EndsWith(".pdf"))}");

        // Display all C# source files
        Console.WriteLine("All files '.cs' Is: ");
        files.FindAll(f => f.EndsWith(".cs"))
            .ForEach(f => Console.WriteLine(f));

        // Check if any file starts with "backup"
        Console.WriteLine($"Is Any file starts with 'backup': " +
            $"{files.Exists(f => f.StartsWith("backup"))}");

        // Check if any file name is longer than 15 characters
        Console.WriteLine($"Is any file name longer than 15 char: " +
            $"{files.Any(f => f.Length > 15)}");

        // Display files containing "data" or "config"
        Console.WriteLine($"All files containing 'data' or 'config': ");
        files.FindAll(f => f.Contains("data") || f.Contains("config"))
            .ForEach(f => Console.WriteLine(f));

        // Find the first backup SQL file 
        Console.WriteLine($"First backup sql file: " +
            $"{files.Find(f => f.Contains("backup") && f.EndsWith(".sql"))}");

        // Display all files that are not PDF files
        Console.WriteLine($"All files not end with PDF: ");
        files.FindAll(f => !f.EndsWith(".pdf"))
            .ForEach(f => Console.WriteLine(f));

        // Check if there are any files with unsupported extensions
        // Allowed extinctions -> .pdf - .jpg - .png - .txt - .cs - .sql
        Console.WriteLine($"Is any file with unsupported extinction: " +
            $@"{files.Any(
                f => !(f.EndsWith(".pdf")
                || f.EndsWith(".jpg")
                || f.EndsWith(".png")
                || f.EndsWith(".txt")
                || f.EndsWith(".cs")
                || f.EndsWith(".sql")
                ))
            }");

        // Find the first file name containing a digit
        Console.WriteLine($"First file name containing a digit: " +
            $"{files.Find(f => f.Any(n => char.IsDigit(n)))}");

        Console.ReadKey();
    }
}