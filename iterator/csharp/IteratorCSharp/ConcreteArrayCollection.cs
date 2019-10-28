using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace IteratorCSharp
{
    abstract class Aggregate
    {
        public abstract Iterator CreateIterator();
    }

    class ConcreteArrayCollection : Aggregate
    {
        private ArrayList _items = new ArrayList();

         public override Iterator CreateIterator()
        {
            return new ConcreteIterator(this);
        }

        public object this[int index]
        {
            get { return _items[index]; }
            set { _items.Insert(index, value); }
        }

        public int Count
        { get { return _items.Count; } }
    }
}
