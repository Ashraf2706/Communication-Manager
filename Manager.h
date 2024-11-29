/*****************************************************************************
 ** File: Manager.h
 ** Project: CMSC 202 Project 5, Fall 2023
 ** Author:  Jeremy Dixon
 ** Date:    11/11/2023
 ** Email:   jdixon@umbc.edu
 **
 Description: Header file for Manager class.
*****************************************************************************/

#ifndef MANAGER_H
#define MANAGER_H
#include "Lqueue.cpp"
#include "Communicator.h"
#include "Message.h"
#include <fstream>
#include <vector>
#include <string>
using namespace std;

//constants
const char DELIMITER = '|'; //delimiter between input lines

class Manager {
public:
  // Name: Overloaded Constructor
  // Desc: Sets m_fileName based on passed string
  // Precondition: None
  // Postcondition: m_fileName is populated
  Manager(string filename);
  // Name: Destructor
  // Desc: Deallocates each communicator in m_communicators
  // Precondition: A Manager exists.
  // Postcondition: All dynamically allocated memory in Manager is deleted.
  ~Manager();
  // Name: FindCommunicator
  // Desc: Searches all communicators in m_communicators for passed number
  //       If not found, returns -1
  // Precondition: None
  // Postcondition: Returns index of number or -1
  int FindCommunicator(long int);
  // Name: LoadMessages
  // Desc: Input file contains time, to, from, and message.
  //       Dynamically allocates new communicator if new number
  //       Creates two messages: one for "to" and one for "from"
  //       Inserts one message into the communicator with matching "to" number.
  //       Inserts one message into the communicator with the matching "from" num.
  // Precondition: m_fileName populated
  // Postcondition: Returns true if file was loaded, else false.
  bool LoadMessages();
  // Name: MainMenu()
  // Desc: Presents user with menu options.
  //       Display Message (displays all messages loaded)
  //       Chooses a Number (lists all unique numbers and user chooses one)
  //       Exits
  // Precondition: Messages have been loaded
  // Postcondition: The main menu is presented
  void MainMenu();
  // Name: DisplayMessages
  // Desc: Displays all messages loaded
  //       Used to display all messages loaded from file
  // Precondition: m_messages has been populated
  // Postcondition: All messages are printed to the screen.
  void DisplayMessages();
  // Name: InitializeManager
  // Desc: Displays the title then if the file is successfully loaded,
  //       calls MainMenu. When finished, thanks user and closes
  // Precondition: m_messages populated
  // Postcondition: File is loaded and mainmenu called
  void InitializeManager();
  // Name: ListNumbers
  // Desc: Numbered list of all unique numbers in m_communicators
  // Precondition: m_communicators
  // Postcondition: Outputs a numbered list of numbers
  void ListNumbers();
  // Name: ChooseNumbers
  // Desc: Calls ListNumbers and the user chooses one number.
  //       Returns the number the user chooses (returns 10 digit number)
  // Precondition: m_communicators
  // Postcondition: Returns the number the user chooses
  long int ChooseNumber();
  // Name: DisplayNumber
  // Desc: Displays all "to" and "from" from a specific number
  // Precondition: m_communicators
  // Postcondition: Outputs "to" and from" from a specific number
  void DisplayNumber(long int);
private:
  vector<Communicator* > m_communicators; //Holds all communicators (phone #)
  string m_fileName; //Filename to be loaded
};
#endif
