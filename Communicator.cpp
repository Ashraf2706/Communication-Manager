#include "Communicator.h"

// Name: Overloaded Constructor
// Desc: Dynamically allocates a new lqueue to hold messages
//       Sets number to passed number
// Precondition: None
// Postcondition: number is passed set as m_number
Communicator::Communicator(long int number){
  m_number = number;
  m_messages = new Lqueue<Message*>();
}
// Name: Destructor
// Desc: Deallocates memory allocated for each communicator.
//       Iterates through m_messages and deletes using At.
// Precondition: A Communicator exists.
// Postcondition: All dynamically allocated memory in Communicator is deleted.
Communicator::~Communicator(){
  for(int i = 0; i < m_messages->GetSize(); i++){
    delete m_messages->At(i);
  }
  delete m_messages;
  m_messages = nullptr;
}
// Name: InsertMessage
// Desc: Inserts a message to m_messages
// Precondition: None
// Postcondition: Inserts a message to m_messages
void Communicator::InsertMessage(Message* message){
  m_messages->Push(message);
}
// Name: DisplayTo
// Desc: Displays all messages sent "to" this communicator
// Precondition: m_messages has been populated
// Postcondition: All messages are printed to the screen using overloaded <<
void Communicator::DisplayTo(){
  if(m_messages == nullptr){
    cout << "No Messages To Print!" << endl;
    return;
  }
  cout << "The size is " << GetNumMessages() << endl;
  cout << "*****MESSAGES TO " << GetNumber() << "*****" << endl;
  bool found = false;
  for(int i = 0; i < GetNumMessages(); i++){
    Message *temp = m_messages->At(i);
    if(temp != nullptr && temp->m_to == m_number){
      cout << *temp << endl;
      found = true;
    }
  }
  if(!found){
    cout << "None" << endl;
  }
}

// Name: DisplayFrom
// Desc: Displays all messages sent "from" this communicator
// Precondition: m_messages populated
// Postcondition: All messages are printed to the screen using overloaded <<
void Communicator::DisplayFrom(){
  if(m_messages == nullptr){
  cout << "No Messages To Print!" << endl;
  return;
  }
  cout << "*****MESSAGES FROM " << GetNumber() << "*****" << endl;
  bool found = false;
  for(int i = 0; i < GetNumMessages(); i++){
    Message *temp = m_messages->At(i);
    if(temp != nullptr && temp->m_from == m_number){
      cout << *temp << endl;
      found = true;
    }
  }
  if(!found){
    cout << "None" << endl;
  }
}
// Name: GetNumber
// Desc: Returns phone number of this communicator
// Precondition: None.
// Postcondition: Number is returned
long int Communicator::GetNumber(){
  return m_number;
}
// Name: GetNumMessages
// Desc: Returns total number of messages in this communicator
// Precondition: None.
// Postcondition: Number is returned
int Communicator::GetNumMessages(){
  return m_messages->GetSize();
}