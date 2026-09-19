using System;


class MultidimensionalArraysExample
{
    static void Main()
    {
        // Declaring a 2D array
        int[,] matrix =
        {
            { 1, 2, 3 },
            { 4, 5, 6 }
        };


        // Iterating over a 2D array
        for (int i = 0; i < matrix.GetLength(0); i++)
        {
            for (int j = 0; j < matrix.GetLength(1); j++)
            {
                Console.Write(matrix[i, j] + " ");
            }
            Console.WriteLine();
        }
        Console.ReadKey();
    }
}
