using System;
using System.Collections;
using System.Collections.Generic;


namespace CustomCollectionExample
{
    public class CustomCollection<T> : IEnumerable<T>
    {
        private List<T> items = new List<T>();


        public IEnumerator<T> GetEnumerator()
        {
            for (int i = 0; i < items.Count; i++)
            {
                yield return items[i];
            }
        }


        IEnumerator IEnumerable.GetEnumerator()
        {
            return GetEnumerator();
        }


        public void Add(T item)
        {
            items.Add(item);
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            var myCollection = new CustomCollection<int>();
            myCollection.Add(1);
            myCollection.Add(2);
            myCollection.Add(3);


            foreach (var item in myCollection)
            {
                Console.WriteLine(item);
            }
            Console.ReadKey();
        }
    }
}
