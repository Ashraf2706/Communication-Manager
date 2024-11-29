#ifndef LQUEUE_CPP
#define LQUEUE_CPP
#include <string>
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

//Templated node class used in templated linked list
template <class T>
class Node {
public:
  Node( const T& data ); //Constructor
  T& GetData(); //Gets data from node
  void SetData( const T& data ); //Sets data in node
  Node<T>* GetNext(); //Gets next pointer
  void SetNext( Node<T>* next ); //Sets next pointer
private:
  T m_data;
  Node<T>* m_next;
};

//Overloaded constructor for Node
template <class T>
Node<T>::Node( const T& data ) {
   m_data = data;
   m_next = NULL;
}

//Returns the data from a Node
template <class T>
T& Node<T>::GetData() {
   return m_data;
}

//Sets the data in a Node
template <class T>
void Node<T>::SetData( const T& data ) {
   m_data = data;
}

//Gets the pointer to the next Node
template <class T>
Node<T>* Node<T>::GetNext() {
   return m_next;
}

//Sets the next Node
template <class T>
void Node<T>::SetNext( Node<T>* next ) {
   m_next = next;
}

template <class T>
class Lqueue {
 public:
  // Name: Lqueue() (Linked List Queue) - Default Constructor
  // Desc: Used to build a new linked queue (as a linked list)
  // Preconditions: None
  // Postconditions: Creates a new lqueue where m_head and m_tail point to nullptr
  // Required
  Lqueue();
  // Name: ~Lqueue() - Destructor
  // Desc: Used to destruct a Lqueue
  // Preconditions: There is an existing lqueue with at least one node
  // Postconditions: Lqueue is deallocated (including dynamically allocated nodes)
  //                 To have no memory leaks!
  // Required
 ~Lqueue();
  // Name: Lqueue (Copy Constructor)
  // Preconditions: Creates a copy of existing LQueue
  //                Requires a Lqueue
  // Postconditions: Copy of existing Lqueue
  // Required
  Lqueue(const Lqueue&);
  // Name: operator= (Overloaded Assignment Operator)
  // Preconditions: Copies an Lqueue into an existing Lqueue
  //                Requires a Lqueue
  // Postconditions: Copy of existing Lqueue
  // Required
  Lqueue<T>& operator= (Lqueue&);
  // Name: Push
  // Preconditions: Takes in data. Creates new node. 
  //                Requires a Lqueue
  // Postconditions: Adds a new node to the end of the lqueue.
  // Required
  void Push(const T&);
  // Name: Pop
  // Preconditions: Lqueue with at least one node. 
  // Postconditions: Removes first node in the lqueue, returns data in first node
  // Required
  T Pop();
  // Name: Display
  // Preconditions: Outputs the lqueue.
  // Postconditions: Displays the data in each node of lqueue
  // Required (used only for testing)
  void Display();
  // Name: Front
  // Preconditions: Requires a populated lqueue
  // Postconditions: Returns whatever data is in front
  // Required
  T Front();
  // Name: IsEmpty
  // Preconditions: Requires a lqueue
  // Postconditions: Returns if the lqueue is empty.
  // Required
  bool IsEmpty();
  // Name: GetSize
  // Preconditions: Requires a lqueue
  // Postconditions: Returns m_size
  // Required
  int GetSize();
  // Name: Find()
  // Preconditions: Requires a lqueue
  // Postconditions: Iterates and if it finds the thing, returns index, else -1
  // Required
  int Find(T&);
  // Name: Clear
  // Preconditions: Requires a lqueue
  // Postconditions: Removes all nodes in a lqueue
  // Required
  void Clear();
  // Name: At
  // Precondition: Existing Lqueue
  // Postcondition: Returns object from Lqueue at a specific location
  // Desc: Iterates to node x and returns data from Lqueue
  // Required
  T& At (int x);
  
  // OPTIONAL: EXTRA CREDIT
  // Name: Swap(int)
  // Preconditions: Requires a lqueue
  // Postconditions: Swaps the nodes at the index with the node prior to it.
  // Details: Must implement a separate file named swap_tests.cpp that is
  //          designed to test the swap function as well. See project document.
  //void Swap(int);

private:
  Node <T> *m_head; //Node pointer for the head
  Node <T> *m_tail; //Node pointer for the tail
  int m_size; //Number of nodes in queue
};

//**********Implement Lqueue Class Here***********
//**********All Functions Are Required Even If Not Used for Project**************
//**********Except Swap for extra credit******************


// Name: Lqueue() (Linked List Queue) - Default Constructor
// Desc: Used to build a new linked queue (as a linked list)
// Preconditions: None
// Postconditions: Creates a new lqueue where m_head and m_tail point to nullptr
// Required
template <class T>
Lqueue<T>::Lqueue(){
   m_head = nullptr;
   m_tail = nullptr;
   m_size = 0;
}

// Name: ~Lqueue() - Destructor
// Desc: Used to destruct a Lqueue
// Preconditions: There is an existing lqueue with at least one node
// Postconditions: Lqueue is deallocated (including dynamically allocated nodes)
//                 To have no memory leaks!
// Required
template <class T>
Lqueue<T>::~Lqueue(){
   Clear();
}

// Name: Lqueue (Copy Constructor)
// Preconditions: Creates a copy of existing LQueue
//                Requires a Lqueue
// Postconditions: Copy of existing Lqueue
// Required
template <class T>
Lqueue<T>::Lqueue(const Lqueue& toCopy){
   m_head = nullptr;
   m_tail = nullptr;
   m_size = 0;

   //if size is 0, constructor will make a copy of linked list
   if(toCopy.m_head != nullptr){
      Node<T> *temp = toCopy.m_head;
      T data;
      while(temp != nullptr){//iterate through original list
         data = temp -> GetData();
         Push(data); //if list is empty, set node as head
         temp = temp -> GetNext();
      }
   }else{
      m_head = nullptr;
      m_tail = nullptr;
      m_size = 0;
   }
}

// Name: operator= (Overloaded Assignment Operator)
// Preconditions: Copies an Lqueue into an existing Lqueue
//                Requires a Lqueue
// Postconditions: Copy of existing Lqueue
// Required
template <class T>
Lqueue<T>& Lqueue<T>::operator= (Lqueue& other){
   if(m_size != 0){
      Node<T>* curr = m_head;
      Node<T>* prev = m_head;
      while(curr != nullptr){//set curr to next and delete prev
         curr = curr -> GetNext();
         delete prev;
         prev = curr;
      }
      m_head = nullptr;
      m_tail = nullptr;
      curr = nullptr;
      prev = nullptr;
   }// copy original list and data gets info from list
   T data;
   Node<T>* temp = other.m_head;
   while(temp != nullptr){
      data = temp -> GetData();
      Push(data);
      temp = temp -> GetNext();
   }
   return *this;
}

// Name: Push
// Preconditions: Takes in data. Creates new node. 
//                Requires a Lqueue
// Postconditions: Adds a new node to the end of the lqueue.
// Required
template <class T>
void Lqueue<T>::Push(const T& data){
   Node<T>* newNode = new Node<T>(data);
   if(m_head == nullptr){
      m_head = newNode;
      m_tail = newNode;
      //m_size = 1;
   }else{
      m_tail -> SetNext(newNode);
      m_tail = newNode;
      // m_size++;
   }
   m_size++;
 //  newNode = nullptr;
}

// Name: Pop
// Preconditions: Lqueue with at least one node. 
// Postconditions: Removes first node in the lqueue, returns data in first node
// Required
template <class T>
T Lqueue<T>::Pop(){
   T data;
   data = m_head -> GetData();
   if(m_head != m_tail){
      Node<T>* temp = m_head;
      m_head = m_head -> GetNext();
      delete temp;
      m_size--;
      temp = nullptr;
   }else{
      data = m_head->GetData();
      delete m_head;
      delete m_tail;
      m_head = nullptr;
      m_tail = nullptr;
      m_size--;
   }
   return data;
}

// Name: Display
// Preconditions: Outputs the lqueue.
// Postconditions: Displays the data in each node of lqueue
// Required (used only for testing)
template <class T>
void Lqueue<T>::Display(){
   int index = 1;
   Node<T>* curr = m_head;
   while(curr != nullptr){
      cout << index << ". " << curr->GetData() << endl;
      index++;
      curr = curr->GetNext();
   }
}

// Name: Front
// Preconditions: Requires a populated lqueue
// Postconditions: Returns whatever data is in front
// Required
template <class T>
T Lqueue<T>::Front(){
   if(m_head != nullptr){
      return m_head->GetData();
   }
}

// Name: IsEmpty
// Preconditions: Requires a lqueue
// Postconditions: Returns if the lqueue is empty.
// Required
template <class T>
bool Lqueue<T>::IsEmpty(){
   if(m_size == 0){
      return true;
   }else{
      return false;
   }
}

// Name: GetSize
// Preconditions: Requires a lqueue
// Postconditions: Returns m_size
// Required
template <class T>
int Lqueue<T>::GetSize(){
   return m_size;
}
// Name: Find()
// Preconditions: Requires a lqueue
// Postconditions: Iterates and if it finds the thing, returns index, else -1
// Required
template <class T>
int Lqueue<T>::Find(T& data){
   int index = 0;
   Node<T>* curr = m_head;
   while(curr != nullptr){
      if(curr->GetData() == data){
         return index;
      }else{
         curr = curr -> GetNext();
         index++;
      }
   }
   return -1;
}
// Name: Clear
// Preconditions: Requires a lqueue
// Postconditions: Removes all nodes in a lqueue
// Required
template <class T>
void Lqueue<T>::Clear(){
   Node<T>* curr = m_head;
   Node<T>* toDelete = m_head;
   while(curr != nullptr){
      curr = curr -> GetNext();
      delete toDelete;
      toDelete = curr;
   }
   m_head = nullptr;
   m_tail = nullptr;
   curr = nullptr;
   toDelete = nullptr;
   m_size = 0;
}

// Name: At
// Precondition: Existing Lqueue
// Postcondition: Returns object from Lqueue at a specific location
// Desc: Iterates to node x and returns data from Lqueue
// Required
template <class T>
T& Lqueue<T>::At (int x){
   if(x >= 0 && x < m_size){
      Node<T>* curr = m_head;
      for(int i = 0; i < x; i++){
         curr = curr -> GetNext();
      }
      return curr -> GetData();
   }
   return m_head->GetData();
}




#endif
