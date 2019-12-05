using System;
using System.Collections.Generic;
using System.Text;

namespace Singleton
{
    class Singleton
    {
        // Eager Initialization, when class is loaded for first time. 
        // Static means also thread safe
        // With readonly value cannot be overwritten
        private static readonly Singleton _instance = new Singleton();
        public int member = 0;

        protected Singleton()
        {
            //Hiding constructor
        }

        public static Singleton Instance()
        {
           return _instance;
        }
    }
}
