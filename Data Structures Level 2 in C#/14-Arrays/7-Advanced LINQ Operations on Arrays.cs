using System;
using System.Linq;


class AdvancedLINQOperations
{
    class People
    {
        public string Name { get; set; }
        public string City { get; set; }
        public int Age { get; set; }
    }
    static void Main()
    {
        // Array of people with Name and Age
        var people = new[]
        {
            new People{ Name = "Alice", Age = 30, City = "Egypt" },
            new People{ Name = "Bob", Age = 25 ,  City = "America" },
            new People{ Name = "Charlie", Age = 35 , City = "Jordan" },
            new People{ Name = "Diana", Age = 30 ,  City = "Mexico" },
            new People{ Name = "Ethan", Age = 25 ,  City = "Jordan" }
        };



        // Grouping people by Age, then ordering within each group
        var groupedByCity = people.GroupBy(p => p.City)
            .Select(group => new { GroupCity = group.Key, People = group });

        // Displaying the results
        foreach(var group in groupedByCity)
        {
            Console.WriteLine($"City: {group.GroupCity}");
            foreach(var person in group.People)
            {
                Console.WriteLine($" - Name: {person.Name}, Age: {person.Age}");
            }
        }

        Console.ReadKey();
    }
}
