using System;
using System.Collections.Generic;
using System.Linq;

public class Person
{
    public string Name { get; set; }
    public int Age { get; set; }

    public Person(string name, int age)
    {
        Name = name;
        Age = age;
    }
}

class Program
{
    static void Main()
    {
        List<Person> people = new List<Person>
        {
            new Person("Alice", 30),
            new Person("Bob", 25),
            new Person("Charlie", 35),
        };

        List<int> numbers = new List<int>
        {
            1, 2, 3, 4, 5, 6, 7, 8, 9, 10
        };


        // Find a value type
        int number = numbers.Find(n => n == 5);

        Console.WriteLine($"Found number: {number}");
        Console.WriteLine("Changing the variable value to 50...");

        int index = numbers.FindIndex(n => n == 5);

        if (index != -1)
        {
            numbers[index] = 50; // Update value Type
        }

        Console.WriteLine("\nNumbers in the list:");
        numbers.ForEach(n => Console.WriteLine(n));


        // Find a reference type object
        Person person = people.Find(p => p.Name == "Alice");

        Console.WriteLine($"\nFound person: {person.Name}, Age: {person.Age}");
        Console.WriteLine("Changing Alice's age to 44...");

        person.Age = 44; // Update Reference Type

        Console.WriteLine("\nPeople in the list:");
        people.ForEach(p => Console.WriteLine($"Name: {p.Name}, Age: {p.Age}"));

        Console.ReadKey();
    }
}
