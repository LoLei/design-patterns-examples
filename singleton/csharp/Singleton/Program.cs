using System;

namespace Singleton
{
    class Program
    {
        static void Main()
        {
            Singleton singleton1 = Singleton.Instance();

            Console.WriteLine("Member: " + singleton1.member);

            singleton1.member++;

            Singleton singleton2 = Singleton.Instance();

            Console.WriteLine("Member: " + singleton2.member);

            // Wait for user
            Console.ReadKey();
        }
    }
}
