/*****************************************************************************
 ** File: Communicator.h
 ** Project: CMSC 202 Project 5, Fall 2023
 ** Author:  Jeremy Dixon
 ** Date:    11/11/2023
 ** Email:   jdixon@umbc.edu
 **
 Description: Header file for Communicator class.
*****************************************************************************/

#ifndef COMMUNICATOR_H
#define COMMUNICATOR_H
#include "Lqueue.cpp"
#include "Message.h"
#include <string>
using namespace std;

class Communicator {
public:
  // Name: Overloaded Constructor
  // Desc: Dynamically allocates a new lqueue to hold messages
  //       Sets number to passed number
  // Precondition: None
  // Postcondition: number is passed set as m_number
  Communicator(long int number);
  // Name: Destructor
  // Desc: Deallocates memory allocated for each communicator.
  //       Iterates through m_messages and deletes using At.
  // Precondition: A Communicator exists.
  // Postcondition: All dynamically allocated memory in Communicator is deleted.
  ~Communicator();
  // Name: InsertMessage
  // Desc: Inserts a message to m_messages
  // Precondition: None
  // Postcondition: Inserts a message to m_messages
  void InsertMessage(Message*);
  // Name: DisplayTo
  // Desc: Displays all messages sent "to" this communicator
  // Precondition: m_messages has been populated
  // Postcondition: All messages are printed to the screen using overloaded <<
  void DisplayTo();
  // Name: DisplayFrom
  // Desc: Displays all messages sent "from" this communicator
  // Precondition: m_messages populated
  // Postcondition: All messages are printed to the screen using overloaded <<
  void DisplayFrom();
  // Name: GetNumber
  // Desc: Returns phone number of this communicator
  // Precondition: None.
  // Postcondition: Number is returned
  long int GetNumber();
  // Name: GetNumMessages
  // Desc: Returns total number of messages in this communicator
  // Precondition: None.
  // Postcondition: Number is returned
  int GetNumMessages();
private:
  Lqueue<Message*>* m_messages; //Holds messages sent to m_number or from m_number
  long int m_number; //phone number of this specific communicator
};
#endif
