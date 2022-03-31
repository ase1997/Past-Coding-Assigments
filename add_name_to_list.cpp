#include <string>
#include <iostream>


using namespace std;





class List;
class Iterator;
//template <typename T>
class Node
{
public:
   /** 
      Constructs a node with a given data value.
      @param element the data to store in this node
   */
   Node(string element); // Node(T element)
   // Node(T data, Node<T>* n, Node<T>* n);
private:
   string data; // T data;
   Node* previous;
   Node* next;
friend class List;
friend class Iterator;
};

class List
{
public:
   /**
      Constructs an empty list.
   */
   List();
   List(const List& rhs); // Homework 
   /*
      Appends an element to the list.
      @param element the value to append
   */
   void push_back(string element);
   /**
      Inserts an element into the list.
      @param iter the position before which to insert
      @param element the value to insert
   */
   void insert(Iterator iter, string element);
   /**
      Removes an element from the list.
      @param iter the position to remove      
      @return an iterator pointing to the element after the
      erased element
   */
   Iterator erase(Iterator iter);
   /**
      Gets the beginning position of the list.
      @return an iterator pointing to the beginning of the list
   */
   Iterator begin();
   /**
      Gets the past-the-end position of the list.
      @return an iterator pointing past the end of the list
   */
   Iterator end();
private:
   Node* first;
   Node* last;
friend class Iterator;
};

class Iterator
{
public:
   /**
      Constructs an iterator that does not point into any list.
   */
   Iterator();
   /**  
      Looks up the value at a position.
      @return the value of the node to which the iterator points
   */
   string get() const;
   /**
      Advances the iterator to the next node.
   */
   void next();
   /**
      Moves the iterator to the previous node.
   */
   void previous();
   /**
      Compares two iterators.
      @param other the iterator to compare with this iterator
      @return true if this iterator and other are equal
   */
   bool equals(Iterator other) const;
private:
   Node* position;
   List* container;
friend class List;
};





















Node::Node(string element)
{  
   data = element;
   previous = nullptr;
   next = nullptr;
}

List::List()
{  
   first = nullptr;
   last = nullptr;
}

List::List(const List& rhs) // Copy constructor - homework 
{
  // Your code here
  Node *p = rhs.first;
first = last = NULL;
while(p!=NULL){
this->push_back(p->data);
p=p->next;
}
}

void List::push_back(string element)
{  
   Node* new_node = new Node(element);
   if (last == nullptr) // List is empty
   {  
      first = new_node;
      last = new_node;
   }
   else
   {  
      new_node->previous = last;
      last->next = new_node;
      last = new_node;
   }
}

void List::insert(Iterator iter, string element)
{  
   if (iter.position == nullptr)
   {  
      push_back(element);
      return;
   }

   Node* after = iter.position;
   Node* before = after->previous;
   Node* new_node = new Node(element);
   new_node->previous = before;
   new_node->next = after;
   after->previous = new_node;
   if (before == nullptr) // Insert at beginning
   {
      first = new_node;
   }
   else
   {
      before->next = new_node;
   }
}

Iterator List::erase(Iterator iter)
{  
   Node* remove = iter.position;
   Node* before = remove->previous;
   Node* after = remove->next;
   if (remove == first)
   {
      first = after;
   }
   else
   {
      before->next = after;
   }
   if (remove == last)
   {
      last = before;
   }
   else
   {
      after->previous = before;
   }
   delete remove;
   Iterator r;
   r.position = after;
   r.container = this;
   return r;
}

Iterator List::begin()
{  
   Iterator iter;
   iter.position = first;
   iter.container = this;
   return iter;
}

Iterator List::end()
{  
   Iterator iter;
   iter.position = nullptr;
   iter.container = this;
   return iter;
}

Iterator::Iterator()
{  
   position = nullptr;
   container = nullptr;
}

string Iterator::get() const
{  
   return position->data;
}

void Iterator::next()
{  
   position = position->next;
}

void Iterator::previous()
{  
   if (position == nullptr)
   {
      position = container->last;
   }
   else 
   {
      position = position->previous;
   }
}

bool Iterator::equals(Iterator other) const
{  
   return position == other.position;
}















int main()
{  
   List names;

   names.push_back("Tom");
   names.push_back("Diana");
   names.push_back("Harry");
   names.push_back("Juliet");

   // Add a value in fourth place

   Iterator pos = names.begin();
   pos.next();
   pos.next();
   pos.next();

   names.insert(pos, "Romeo");

   // Remove the value in second place

   pos = names.begin();
   pos.next();

   names.erase(pos);

    List names_copy(names); //Copy constructor - homework
   names_copy.push_back("Shakespeare");
   // Verify that Shakespeare was inserted. 
   cout << "Printing new list" << endl;
   for (pos = names_copy.begin(); !pos.equals(names.end()); pos.next())
   {
      cout << pos.get() << endl; // 
   }
   cout << "Printing original list " << endl;
   for (pos = names.begin(); !pos.equals(names.end()); pos.next())
   {
      cout << pos.get() << endl;
   }

   return 0;
}
