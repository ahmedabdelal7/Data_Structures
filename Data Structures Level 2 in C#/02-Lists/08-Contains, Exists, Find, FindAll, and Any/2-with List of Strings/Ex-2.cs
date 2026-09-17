using System;
using System.Collections.Generic;
using System.Linq;

class Program
{
    static void Main()
    {
        //Registered Users:
        List<string> usernames = new List<string>
        {
            "ahmed_dev",
            "mohamed123",
            "admin",
            "sara_cs",
            "omar2004",
            "test_user",
            "hany_dev",
            "root"
        };

        // Check if the username "admin" is already registered
        Console.WriteLine($"Is 'admin' Registered: {usernames.Contains("admin")}");

        // Find the first username containing "dev"
        Console.WriteLine($"FIrst UserName Contains 'dev': {usernames.Find(u=> u.Contains("dev"))}");
        
        // Find all usernames containing at least one digit
        Console.WriteLine("User Names Contains at least one digit: ");
        usernames.FindAll(u => u.Any(c => char.IsDigit(c)))
            .ForEach(u => Console.WriteLine(u));


        // Check if any username violates the registration rules
        //Long at least 8 char and don't start with 'admin' or 'root'
        Console.WriteLine("Is any user name violates rules: " +
            usernames.Exists(u => u.Length < 8
                || u.StartsWith("admin")
                || u.StartsWith("root"))
        );


        Console.ReadKey();
    }
}