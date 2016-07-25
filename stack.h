#ifndef stack_h
#define stack_h

#include <vector>
#include <string>

using namespace std;



class EmptyQueueException {
  public:
    EmptyQueueException(string);
    string getMessage();

  private:
    string msg;
};

class DivideByZero {
  public:
    DivideByZero(string);
    string getMessage();

  private:
    string msg;
};

class NotAnInteger {
  public:
    NotAnInteger(string);
    string getMessage();

  private:
    string msg;
};



template<class T>
class Node {
  public:
    Node(T, Node<T>*);
    ~Node();
  
    Node<T>* getNext();
    T getData();
    void setNext(Node<T>*);
    void setData(T);

  private:
    T val;
    Node<T>* next;
};

template<class T>
class Stack {
  public:
    Stack();
    ~Stack();

    // The push method pushs an item on the queue.
    void push(T item);
    T pop();
    bool isEmpty();

  private:
    Node<T>* head;
};

template<class T>
Stack<T>& operator<<(Stack<T>&, T);
template<class T>
Stack<T>& operator>>(Stack<T>&, T&);


//////////////////////////////////////
//////////////////////////////////////


template<class T>
Node<T>::Node(T x, Node<T>* next) {
  val = x;
  this->next = next;
}

template<class T>
Node<T>::~Node() {
  if (next == nullptr) 
    return;

  try {
    delete next;
  } catch(...) {}  
}

template<class T>
void Node<T>::setNext(Node<T>* next) {
  this->next = next;
}

template<class T>
Node<T>* Node<T>::getNext() {
  return next;
}

template<class T>
void Node<T>::setData(T val) {
  this->val = val;
}
template<class T>
T Node<T>::getData() {
  return val;
}

template<class T>
Stack<T>::Stack() {
  head = nullptr;

}
template<class T>
Stack<T>::~Stack() {
  try {
    delete head;
  } catch (...) {}
}

template<class T>
void Stack<T>::push(T item) {

  /* push
  1) create new node
      * make next field point to what head points to
  2) make head point to the new node
  */
   Node<T>* newFront = new Node<T>(item,head);
   head = newFront;

}

template<class T>
T Stack<T>::pop() {
    /* pop
    1) save someplace the data that head points to
    2) make head point to the next field of current top.
    
    */
   if (this->isEmpty())
    throw new EmptyQueueException("Expression is malformed.");
   T item = head->getData();
   Node<T>* newFront = head->getNext(); 
   Node<T>* toDelete = head;

   toDelete->setNext(nullptr);
   delete toDelete; // reclaims heap space
   head = newFront;  
   return item;
}

template<class T>
bool Stack<T>::isEmpty() {
   return head == nullptr;
}

template<class T>
Stack<T>& operator<<(Stack<T>& q, T x) {
  q.push(x);

  return q;
}

template<class T>
Stack<T>& operator>>(Stack<T>& q, T& x) {
  x = q.pop();

  return q;
}


#endif
