using System;
using System.Collections;
using System.Collections.Generic;
using System.Text;

namespace CSharpIteratorDotNetCore
{
    abstract class Iterator : IEnumerator
    {
        object IEnumerator.Current => CurrentItem();
        public abstract int Key();
        public abstract object CurrentItem();
        public abstract bool MoveNext();
        public abstract void Reset();
    }
    abstract class IteratorAggregate : IEnumerable
    {
        public abstract IEnumerator GetEnumerator();
    }
}
