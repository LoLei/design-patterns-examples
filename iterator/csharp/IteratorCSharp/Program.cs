using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace IteratorCSharp
{
    class Program
    {
        static void Main(string[] args)
        {
            ConcreteArrayCollection a = new ConcreteArrayCollection();
            a[0] = 1;
            a[1] = 2;
            a[2] = 3;
            a[3] = 4;
            a[4] = 5;

            Iterator i = a.CreateIterator();

            while(i.Next())
            {
                Console.WriteLine(i.CurrentItem());
            }

            Console.ReadKey();
        }
    }
}
