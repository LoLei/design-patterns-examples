using System;
using System.Collections.Generic;
using System.Text;

namespace CSharpIteratorDotNetCore
{
    //Concrete Iterator implements traversal algorithm. Store traversal position
    class ConcreteIterator : Iterator
    {
        private ConcreteCollection _collection;
        private int _current = -1;

        public ConcreteIterator(ConcreteCollection collection)
        {
            this._collection = collection;
        }

        public override object Current()
        {
                return this._collection.getItems()[_current];
        }

        public override int Key()
        {
            return this._current;
        }

        public override bool MoveNext()
        {
            if (++_current < _collection.getItems().Count)
            {
                return true;
            }
            else
            {
                return false;
            }
        }

        public override void Reset()
        {
            _current = -1;
        }
    }
}
