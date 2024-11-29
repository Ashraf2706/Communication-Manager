
# Communication Manager

## Overview
The Communication Manager is a C++ application designed to simulate a communication system. It handles messages sent between communicators (representing phone numbers), organizes them in queues, and allows users to interact with the messages via a menu-driven interface.

## Features
- **Message Management**: Supports sending, storing, and displaying messages between different communicators.
- **Communicator Handling**: Dynamically allocates communicators as needed and maintains their message queues.
- **File Input**: Loads messages from an input file with pre-defined formatting.
- **Menu Interaction**: Offers options to display all messages, view messages for specific communicators, and quit the application.

## Files
### Source Files
- **`Communicator.cpp` & `Communicator.h`**:
  - Handles individual communicators, including managing messages sent "to" and "from" a phone number.
- **`Lqueue.cpp`**:
  - Implements a templated linked-list queue for managing messages.
- **`Manager.cpp` & `Manager.h`**:
  - Manages the entire communication system, including message loading, menu navigation, and communicator organization.
- **`Message.cpp` & `Message.h`**:
  - Represents individual messages with attributes for time, sender, recipient, and content.

## Installation
1. **Ensure all files are in the same directory**.
2. Compile the application using a C++ compiler:
   ```bash
   g++ -o communication_manager Communicator.cpp Lqueue.cpp Manager.cpp Message.cpp
   ```
3. Run the application:
   ```bash
   ./communication_manager
   ```

## How to Use
1. **Load Messages**:
   - Messages are loaded from an input file in the format:
     ```
     <time>|<to_phone_number>|<from_phone_number>|<message_content>
     ```
     Example: `1672531200|1234567890|9876543210|Hello there!`

2. **Menu Options**:
   - **Display Messages**: Displays all loaded messages.
   - **Choose Number**: Lists all unique phone numbers and allows viewing messages for a specific number.
   - **Quit**: Exits the application.

3. **Message Display**:
   - Messages include timestamps, sender, recipient, and content.
   - Example output:
     ```
     TIME: Thu Jan 1 00:00:00 1970
     TO: 1234567890 FROM: 9876543210 MESSAGE: Hello there!
     ```

## Classes and Functions
### `Communicator`
- Manages messages for a specific phone number.
- Key Methods:
  - `InsertMessage`: Adds a message to the communicator's queue.
  - `DisplayTo`: Displays messages sent to the communicator.
  - `DisplayFrom`: Displays messages sent from the communicator.

### `Lqueue`
- Implements a linked-list queue to store messages.
- Key Methods:
  - `Push`: Adds an item to the queue.
  - `Pop`: Removes and returns the front item of the queue.
  - `GetSize`: Returns the number of items in the queue.

### `Manager`
- Oversees the entire system.
- Key Methods:
  - `LoadMessages`: Loads messages from the input file.
  - `MainMenu`: Presents the user with options.
  - `FindCommunicator`: Locates a communicator by phone number.
  - `InitializeManager`: Initializes the program and manages the main menu loop.

### `Message`
- Represents a single message with details of the sender, recipient, and content.
- Overloads the `<<` operator for easy output formatting.

## Dependencies
- Standard C++ libraries:
  - `<iostream>`
  - `<string>`
  - `<fstream>`
  - `<vector>`
  - `<ctime>`

## Notes
- Input file should be formatted correctly with a `|` delimiter separating fields.
- Ensure dynamic memory is handled correctly to avoid leaks.

## Author
- **Ashraf Kawooya**
- **Date**: 11/11/2023
- **Email**: ashrafk1@umbc.edu

## License
This project is intended for educational purposes and does not provide warranties or guarantees.
