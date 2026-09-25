using System;
using System.Collections.Generic;

class PriorityQueueNode
{
    public string Name { get; set; }
    public int Priority { get; set; }
    public PriorityQueueNode(string name, int priority)
    {
        Name = name; Priority = priority;
    }
}

class MinHeapPriorityQueue
{

    List<PriorityQueueNode> Heap = new List<PriorityQueueNode>();

    public void Insert(string value, int priority)
    {
        PriorityQueueNode node = new PriorityQueueNode(value, priority);

        Heap.Add(node);

        HeapifyUp(Heap.Count - 1);
    }

    private void HeapifyUp(int index)
    {
        while (index > 0) {

            int parentIndex = (index - 1) / 2;

            if (Heap[index].Priority >= Heap[parentIndex].Priority) break;

            (Heap[index], Heap[parentIndex]) = (Heap[parentIndex], Heap[index]);

            index = parentIndex;
        }
    }

    public PriorityQueueNode Peek()
    {
        if (Heap.Count == 0)
            throw new InvalidOperationException("Priority queue is empty.");

        return Heap[0];
    }

    public PriorityQueueNode ExtractMin()
    {
        if (Heap.Count == 0)
            throw new InvalidOperationException("Priority queue is empty.");

        PriorityQueueNode minNode = Heap[0];

        Heap[0] = Heap[Heap.Count - 1];

        Heap.RemoveAt(Heap.Count - 1);

        HeapifyDown(0);

        return minNode;
    }

    private void HeapifyDown(int index)
    {

        while(index < Heap.Count)
        {
            int leftChildIndex = index * 2 + 1;
            int rightChildIndex = index * 2 + 2;

            int smallestValueIndex = index;

            if (leftChildIndex < Heap.Count && Heap[leftChildIndex].Priority < Heap[smallestValueIndex].Priority) 
                smallestValueIndex = leftChildIndex;

            if (rightChildIndex < Heap.Count && Heap[rightChildIndex].Priority < Heap[smallestValueIndex].Priority)
                smallestValueIndex = rightChildIndex;


            if(smallestValueIndex == index) break;

            (Heap[smallestValueIndex], Heap[index]) = (Heap[index], Heap[smallestValueIndex]);

            index = smallestValueIndex;

        }

    }
}

public class Program
{
    public static void Main()
    {
        MinHeapPriorityQueue pq = new MinHeapPriorityQueue();

        Console.WriteLine("Inserting elements into the Priority Queue...\n");

        Console.WriteLine("Inserting (Task 1, 5)");
        Console.WriteLine("Inserting (Task 2, 3)");
        Console.WriteLine("Inserting (Task 3, 4)");
        Console.WriteLine("Inserting (Task 4, 1)");
        Console.WriteLine("Inserting (Task 5, 2)");

        pq.Insert("Task 1", 5);
        pq.Insert("Task 2", 3);
        pq.Insert("Task 3", 4);
        pq.Insert("Task 4", 1);
        pq.Insert("Task 5", 2);

        // Peek the minimum priority element
        Console.WriteLine("\nPeek Minimum Priority Element: Name = " + pq.Peek().Name + ", Priority = " + pq.Peek().Priority);

        // Extract elements based on priority
        Console.WriteLine("\nExtracting elements from the Priority Queue:");
        var extractedNode = pq.ExtractMin();
        Console.WriteLine("\nExtracted Element: Name = " + extractedNode.Name + ", Priority = " + extractedNode.Priority);

        extractedNode = pq.ExtractMin();
        Console.WriteLine("Extracted Element: Name = " + extractedNode.Name + ", Priority = " + extractedNode.Priority);

        extractedNode = pq.ExtractMin();
        Console.WriteLine("Extracted Element: Name = " + extractedNode.Name + ", Priority = " + extractedNode.Priority);

        extractedNode = pq.ExtractMin();
        Console.WriteLine("Extracted Element: Name = " + extractedNode.Name + ", Priority = " + extractedNode.Priority);

        extractedNode = pq.ExtractMin();
        Console.WriteLine("Extracted Element: Name = " + extractedNode.Name + ", Priority = " + extractedNode.Priority);


        Console.ReadKey();
    }
}
