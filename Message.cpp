#include "Message.h"

// Name: Overloaded Constructor
// Desc: Constructs a message object given all fields.
// Precondition: Message must be templated by the data type in as an argument.
// Postcondition: A new Message object is created for use.
Message::Message(long int time, long int mTo, long int mFrom, string message){
  m_time = time;
  m_to = mTo;
  m_from = mFrom;
  m_message = message;
}
// Name: Destructor
// Desc: Resets variables and deallocates dynamically allocated memory
// Precondition: A Message object exists.
// Postcondtion: All dynamically allocated memory is destroyed.
Message::~Message(){
  m_time = 0;
  m_to = 0;
  m_from = 0;
  m_message = "";
}
// Name: Overloaded insertion operator
// Desc: Returns ostream object for the message prompt. Presents
// message and answer data type.
// Precondition: Message object exists
// Postcondition: Returns ostream of message prompt.
// HINT: To display the time readably: std::ctime(&message.m_time)
ostream& operator<< (ostream& output, Message& message){
  output << "TIME: " << std::ctime(&message.m_time);
  output << "TO: " << message.m_to << 
  " FROM: " << message.m_from <<
  " MESSAGE: " << message.m_message;
  return output;
}