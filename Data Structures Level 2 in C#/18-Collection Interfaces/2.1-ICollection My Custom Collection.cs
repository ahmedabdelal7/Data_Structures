using System;
using System.Collections;
using System.Collections.Generic;

public class SimpleCollection2<T> : ICollection<T>
{
    T[] arr;

    int _Size = 0;
    public int Capacity = 0;
    public int Count => _Size;
    public bool IsReadOnly => false;
    public SimpleCollection2(int capacity)
    {
        Capacity = capacity;
        arr = new T[Capacity];
        
    }

    public void Add(T item)
    {
        arr[_Size] = item;
        _Size++;
    }
    
    public bool Remove(T item)
    {
        int index = _GetItemIndex(item);
        if (index == -1)
            return false;

        //if item is not the last item?
        //SHift elements
        if(index != _Size - 1)
        {
            for (int i = index; i < _Size - 1; i++)
            {
                arr[i] = arr[i + 1];
            }
            
        }
        //Set default value for last item after remove
        arr[_Size-1] = default(T);
            _Size--;
        return true;

    }

    public void Clear()
    {
        Array.Clear(arr, 0, _Size);
        _Size = 0;
    }

    public bool Contains(T item)
    {
        return _GetItemIndex(item) != -1;
    }

    public void CopyTo(T[] array, int arrayIndex)
    {
        Array.Copy(arr, 0, array, arrayIndex, _Size);
    }

    private int _GetItemIndex(T item)
    {
        int itemIndex = -1;
        for (int i = 0; i < _Size; i++)
        {
            if (arr[i].Equals(item))
            {
                itemIndex = i;
                return itemIndex;
            }
        }
        return -1;
    }

    public IEnumerator<T> GetEnumerator()
    {
        for(int i = 0;i < _Size; i++)
        {
            yield return arr[i];
        }
    }

    IEnumerator IEnumerable.GetEnumerator()
    {
        return GetEnumerator();
    }
}


class Program
{
    static void Main(string[] args)
    {
        
        SimpleCollection2<int> myCollection = new SimpleCollection2<int>(5);

        myCollection.Add(1);
        myCollection.Add(2);
        myCollection.Add(3);
        myCollection.Add(4);
        myCollection.Add(5);

        Console.WriteLine("Collection Elements: ");
        foreach (int i in myCollection)
        {
            Console.WriteLine(i);
        }

        Console.WriteLine($"\nCount: {myCollection.Count}");
        Console.WriteLine($"\nCapacity: {myCollection.Capacity}");

        Console.WriteLine($"\nIs Contains(6): {myCollection.Contains(6)}");
        Console.WriteLine($"Is Contains(1): {myCollection.Contains(1)}");

        if (myCollection.Remove(1))
            Console.WriteLine("\nDone Removing 1.");
        else
            Console.WriteLine("\nNumber 1 is not found.");

        Console.WriteLine($"\nCount: {myCollection.Count}");
        Console.WriteLine($"\nCapacity: {myCollection.Capacity}");

        Console.WriteLine("\nCollection After Remove (1): ");
        foreach (int i in myCollection)
        {
            Console.WriteLine(i);
        }

        myCollection.Add(10);
        Console.WriteLine("\nCollection After Add(10): ");
        foreach (int i in myCollection)
        {
            Console.WriteLine(i);
        }

        myCollection.Clear();
        Console.WriteLine("\nCollection After Clear: ");
        foreach (int i in myCollection)
        {
            Console.WriteLine(i);
        }


        Console.ReadKey();
    }
}

