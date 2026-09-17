using System;

class Program
{
    static void Main()
    {
        int valType = 10;

        //Boxing converting a value type to a reference type.
        //Wrapping a value type (like int, float, char) in an object or any interface type implemented by this value type.
        object objType = valType; // Boxing

        Console.WriteLine("Boxed Value: " + objType);

        //Unboxing is the reverse process of Boxing, where the value type is extracted from the object.
        //It's crucial to ensure the type being unboxed matches the type of the object.
        int unboxedValType = (int)objType; // Unboxing

        Console.WriteLine("Unboxed Value: " + unboxedValType);

        Console.ReadKey();
    }
}
