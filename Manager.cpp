#include "Manager.h"

// Name: Overloaded Constructor
// Desc: Sets m_fileName based on passed string
// Precondition: None
// Postcondition: m_fileName is populated
Manager::Manager(string filename){
  m_fileName = filename;
}
// Name: Destructor
// Desc: Deallocates each communicator in m_communicators
// Precondition: A Manager exists.
// Postcondition: All dynamically allocated memory in Manager is deleted.
Manager::~Manager(){
  //cout << "Called" << endl;
  int size = m_communicators.size();
  for(int i = 0; i < size; i++){
    delete m_communicators[i];
    m_communicators[i] = nullptr;
  }
  m_fileName = "";
}
// Name: FindCommunicator
// Desc: Searches all communicators in m_communicators for passed number
//       If not found, returns -1
// Precondition: None
// Postcondition: Returns index of number or -1
int Manager::FindCommunicator(long int number){
  int index = -1;
  for(unsigned int i = 0; i < m_communicators.size(); i++){
    if(m_communicators[i] -> GetNumber() == number){
      return i;
    }
  }
  return index;
}
// Name: LoadMessages
// Desc: Input file contains time, to, from, and message.
//       Dynamically allocates new communicator if new number
//       Creates two messages: one for "to" and one for "from"
//       Inserts one message into the communicator with matching "to" number.
//       Inserts one message into the communicator with the matching "from" num.
// Precondition: m_fileName populated
// Postcondition: Returns true if file was loaded, else false.
bool Manager::LoadMessages(){
  string message;
  string stringTime;
  string stringTo;
  string stringFrom;

  ifstream file(m_fileName);
  if(file.is_open()){
    while(getline(file, stringTime, DELIMITER)&&
      getline(file, stringTo, DELIMITER)&&
      getline(file, stringFrom, DELIMITER)&&
      getline(file, message, DELIMITER)){

      long int time = stol(stringTime);
      long int to = stol(stringTo);
      long int from = stol(stringFrom);

      Message* toMessage = new Message(time, to, from, message);
      Message* fromMessage = new Message(time, to, from, message);
           
      if(FindCommunicator(to) == -1){
        Communicator* toCommunicator = new Communicator(to);
        toCommunicator->InsertMessage(toMessage);
        m_communicators.push_back(toCommunicator);        
      }
      else{
        m_communicators[FindCommunicator(to)]->InsertMessage(toMessage);
      }

      if(FindCommunicator(from) == -1){
        Communicator* fromCommunicator = new Communicator(from);
        fromCommunicator->InsertMessage(fromMessage);
        m_communicators.push_back(fromCommunicator);   
      }
      else{
        m_communicators[FindCommunicator(from)]->InsertMessage(fromMessage);
      }
    }
    file.close();
    return true;
  }else{
    cout << "Unable to open file" << endl;
    return false;
  } 
  
}
// Name: MainMenu()
// Desc: Presents user with menu options.
//       Display Message (displays all messages loaded)
//       Chooses a Number (lists all unique numbers and user chooses one)
//       Exits
// Precondition: Messages have been loaded
// Postcondition: The main menu is presented
void Manager::MainMenu(){
  cout << "Choose an option" << endl;
  cout << "1. Display Messages" << endl;
  cout << "2. Choose Number" << endl;
  cout << "3. Quit" << endl;
}
// Name: DisplayMessages
// Desc: Displays all messages loaded
//       Used to display all messages loaded from file
// Precondition: m_messages has been populated
// Postcondition: All messages are printed to the screen.
void Manager::DisplayMessages(){
  for(unsigned int i = 0; i < m_communicators.size(); i++){
    m_communicators[i]->DisplayTo();
    m_communicators[i]->DisplayFrom();
  }
}
// Name: InitializeManager
// Desc: Displays the title then if the file is successfully loaded,
//       calls MainMenu. When finished, thanks user and closes
// Precondition: m_messages populated
// Postcondition: File is loaded and mainmenu called
void Manager::InitializeManager(){
  cout << "Welcome to UMBC Communication Manager" << endl;
  if(LoadMessages()){
    int choice = 0;
    do{
      MainMenu();
      cin >> choice;

      switch(choice){
        case 1:
          DisplayMessages();
          break;
        case 2:
          DisplayNumber(ChooseNumber());
          break;
        case 3:
          cout << "Thank you for trying UMBC Communication Manager!" << endl;
          break;
      }
    }while(choice != 3);
  }
}
// Name: ListNumbers
// Desc: Numbered list of all unique numbers in m_communicators
// Precondition: m_communicators
// Postcondition: Outputs a numbered list of numbers
void Manager::ListNumbers(){
  for(unsigned int i = 0; i < m_communicators.size(); i++){
    cout << i + 1 << ". " << m_communicators[i]->GetNumber() << endl;
  }
}
// Name: ChooseNumbers
// Desc: Calls ListNumbers and the user chooses one number.
//       Returns the number the user chooses (returns 10 digit number)
// Precondition: m_communicators
// Postcondition: Returns the number the user chooses
long int Manager::ChooseNumber(){
  int choice = 0;
  int size = m_communicators.size();
  do{
    cout << "What number's log you like to view?" << endl;
    ListNumbers();
    cin >> choice;
  }
  while(choice < 1 or choice > size );
  return m_communicators[choice -1]->GetNumber();
}
// Name: DisplayNumber
// Desc: Displays all "to" and "from" from a specific number
// Precondition: m_communicators
// Postcondition: Outputs "to" and from" from a specific number
void Manager::DisplayNumber(long int number){
  int index = FindCommunicator(number);
  if(index != -1){
    m_communicators[index]->DisplayTo();
    m_communicators[index]->DisplayFrom();
  }else{
      cout << "None" << endl;
  }
}