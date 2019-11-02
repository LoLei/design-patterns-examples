using System;

namespace CSharpIteratorDotNetCore
{
    class Program
    {
        static void Main(string[] args)
        {
            ConcreteCollection a = new ConcreteCollection();
            a.AddItem(1);
            a.AddItem(2);
            a.AddItem(3);
            a.AddItem(4);
            a.AddItem(5);

            foreach (var element in a)
            {
                Console.WriteLine(element);
            }

            Console.ReadKey();
        }
    }
}
