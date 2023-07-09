# Contact Management System

This is a simple Contact Management System program written in C++. It allows you to manage a list of contacts by adding new contacts by adding new contacts, deleting existing contacts, and displaying all contacts. The program utilizes the file input/output to store the contact information persistently. 

## Getting Started 
To use this Contact Management System, follow this steps below:

1. Clone the repository or download the source code.
2. Compile the source code using a C++ compiler.
3. Run the compiled executable.

## Prerequisites
To compile and run this program, you need to have a C++ compiler installed by your system. 

## Usage
1. When you run the program, a menu will be displayed with the following options:
    * Add contact: Allows you to add a new contact by entering their first name, last name, and email address.
    * Delete contact: Lets you delete a contact by providing its contact number.
    * Display all contacts. Shows a list of all stored contacts.
    * Exits: Quits the program
2. Choose the desired option by entering the corresponing number.

## File Storage
The contact information is stored in a file named **Contact.txt**. When the program starts, it reads the contacts from the file, and when the program exit, it writes the updated contact list back to the file.
