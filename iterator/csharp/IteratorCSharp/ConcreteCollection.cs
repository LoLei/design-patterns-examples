using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace IteratorCSharp
{
    //Provides one or more methods for retrieving iterator instance, compatible with collection class
    class ConcreteCollection : IteratorAggregate
    {
        private ArrayList _collection = new ArrayList();

         public override IEnumerator GetEnumerator()
        {
            return new ConcreteIterator(this);
        }

        public ArrayList getItems()
        {
            return _collection;
        }
        public void AddItem(object item)
        {
            this._collection.Add(item);
        }
    }
}
