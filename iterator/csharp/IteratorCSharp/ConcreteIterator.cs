using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace IteratorCSharp
{
    abstract class Iterator
    {
        public abstract object First();
        public abstract bool Next();
        public abstract bool isDone();
        public abstract object CurrentItem();
    }
    class ConcreteIterator :Iterator
    {
        private ConcreteArrayCollection _aggregate;
        private int _current = -1;

        public ConcreteIterator(ConcreteArrayCollection aggregate)
        {
            this._aggregate = aggregate;
        }

        public override object First()
        {
            return _aggregate[0];
        }

        public override bool Next()
        {
            _current++;
            return _current <= _aggregate.Count;
        }

        public override bool isDone()
        {
            return _current <= _aggregate.Count;
        }

        public override object CurrentItem()
        {
            object ret = null;
            if (_current < _aggregate.Count)
            {
                ret = _aggregate[_current];
            }
            return ret;
        }
    }
}
