/*****************************************************************************
 ** File: Message.cpp
 ** Project: CMSC 202 Project 5, Fall 2023
 ** Author:  CMSC202
 ** Date:    11/14/2023
 **
 Description: CPP file for Message class. Includes both class definition and
 class function definitions.
*****************************************************************************/

#ifndef MESSAGE_CPP
#define MESSAGE_CPP
#include <iostream>
#include <string>
#include <ctime>
using namespace std;
struct Message {
public:
  // Name: Overloaded Constructor
  // Desc: Constructs a message object given all fields.
  // Precondition: Message must be templated by the data type in as an argument.
  // Postcondition: A new Message object is created for use.
  Message(long int time, long int mTo, long int mFrom, string message);
  // Name: Destructor
  // Desc: Resets variables and deallocates dynamically allocated memory
  // Precondition: A Message object exists.
  // Postcondtion: All dynamically allocated memory is destroyed.
  ~Message();
  // Name: Overloaded insertion operator
  // Desc: Returns ostream object for the message prompt. Presents
  // message and answer data type.
  // Precondition: Message object exists
  // Postcondition: Returns ostream of message prompt.
  // HINT: To display the time readably: std::ctime(&message.m_time)
  friend ostream& operator<< (ostream& output, Message&);
  //Member variables (all public)
  long int m_time; //Time message sent
  long int m_from; // Phone number of source of message
  long int m_to; // Phone number of destination of message
  string m_message; // Answer to message
};

#endif
