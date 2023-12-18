#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <map>

class Contact
{
    public:
        Contact(){};
        Contact(std::string firstName, std::string lastName, std::string email);
        std::string getFirstName(){ return firstName; }
        std::string getLastName(){ return lastName; }
        std::string getEmail(){ return email; }
        long getContactNumber(){ return contactNumber; }
    
        static void setLastContactNumber(long contactNumber);
        static long getLastContactNumber();
    
        friend std::ofstream & operator << (std::ofstream& ofs, Contact& contacts);
        friend std::ifstream & operator >> (std::ifstream& ifs, Contact& contacts);
        friend std::ostream  & operator << (std::ostream&  os,  Contact& contacts);
    
    private:
        std::string firstName;
        std::string lastName;
        std::string email;
        long contactNumber;
        static long nextContactNumber;
};

class ManagementSystem
{
    public:
        ManagementSystem();
        Contact addContact(std::string, std::string, std::string);
        void deleteContact(long);
        void displayContacts();
        ~ManagementSystem();
    
    private:
        std::map<long, Contact> contacts;
};

void displayMenu();

int main(void)
{
    ManagementSystem system;
    Contact contact;
    
    std::string firstName, lastName, email;
    long contactNumber = 0;
    int selection = 0;
    std::cout << "***Contact Management System***" << std::endl;
    
    do
    {
        displayMenu();
        std::cin >> selection;
        std::cin.ignore();
        switch (selection)
        {
            case 1:
                std::cout << "Enter your first name: ";
                getline(std::cin, firstName);
                std::cout << "Enter your last name: ";
                getline(std::cin, lastName);
                std::cout << "Enter your email address: ";
                getline(std::cin, email);
                
                contact = system.addContact(firstName, lastName, email);
                break;
            
            case 2:
                std::cout << "Enter a contact number: ";
                std::cin  >> contactNumber;
                std::cin.ignore();
                
                system.deleteContact(contactNumber);
                break;
                
            case 3:
                system.displayContacts();
                break;
                
            case 4:
                // Exit the program
                break;
                
            default:
                std::cout << "Invalid Selection" << std::endl;
        }
    } while (selection != 4);
    
    return 0;
} /* End of Program*/

long Contact::nextContactNumber = 0;

Contact::Contact(std::string firstName, std::string lastName, std::string email)
{
    ++nextContactNumber;
    contactNumber = nextContactNumber;
    this->firstName = firstName;
    this->lastName = lastName;
    this->email = email;
}

void Contact::setLastContactNumber(long contactNumber)
{
    nextContactNumber = contactNumber;
}

long Contact::getLastContactNumber()
{
    return nextContactNumber;
}

std::ofstream & operator << (std::ofstream& ofs, Contact& contacts)
{
    ofs << contacts.contactNumber << std::endl;
    ofs << contacts.firstName << std::endl;
    ofs << contacts.lastName << std::endl;
    ofs << contacts.email << std::endl;
    
    return ofs;
}

std::ifstream & operator >> (std::ifstream& ifs, Contact& contacts)
{
    ifs >> contacts.contactNumber;
    ifs >> contacts.firstName;
    ifs >> contacts.lastName;
    ifs >> contacts.email;
    
    return ifs;
}

std::ostream & operator << (std::ostream& os, Contact& contacts)
{
    os << "Contact number: " << contacts.getContactNumber() << std::endl;
    os << "First name: " << contacts.getFirstName() << std::endl;
    os << "Last name: " << contacts.getLastName() << std::endl;
    os << "Email address: " << contacts.getEmail() << std::endl;
    
    return os;
}

ManagementSystem::ManagementSystem()
{
    Contact contact;
    std::ifstream inFile;
    inFile.open("Contact.txt");
    
    if (!inFile)
    {
        std::cout << "ERROR in open file Contact.txt" << std::endl;
        exit(EXIT_FAILURE);
    }
    
    while (!inFile.eof())
    {
        inFile >> contact;
        contacts.insert(std::pair<long, Contact>(contact.getContactNumber(), contact));
    }
    
    Contact::setLastContactNumber(contact.getContactNumber());
    
    inFile.close();
}

Contact ManagementSystem::addContact(std::string firstName, std::string lastName, std::string email)
{
    std::ofstream outfile;
    Contact contact(firstName, lastName, email);
    contacts.insert(std::pair<long, Contact>(contact.getContactNumber(), contact));
    
    outfile.open("Contact.txt", std::ios::trunc);
    
    if (!outfile.is_open())
    {
        std::cout << "ERROR in opening file Contact.txt" << std::endl;
        exit(EXIT_FAILURE);
    }
    
    std::map<long, Contact>::iterator itr;
    
    for (itr = contacts.begin(); itr != contacts.end(); ++itr)
    {
        outfile << itr->second;
    }
    
    outfile.close();
    
    return contact;
}

void ManagementSystem::deleteContact(long contactNumber)
{
    std::map<long, Contact>::iterator itr;
    itr = contacts.find(contactNumber);
    
    if (itr != contacts.end())
    {
        std::cout << "Contact Number " << contactNumber << " deleted successfully" << std::endl;
        contacts.erase(itr);
    } else {
        std::cout << "Sorry, no contact found for contact number " << contactNumber << ".";
    }
    
    return;
}

void ManagementSystem::displayContacts()
{
    std::map<long, Contact>::iterator itr;
    
    if (itr == contacts.end())
    {
        std::cout << "List is empty." << std::endl;
        return;
    }
    
    for (itr = contacts.begin(); itr != contacts.end(); ++itr)
    {
        std::cout << "Contact " << itr->first << "\n" << itr->second << std::endl;
    }
}

void displayMenu()
{
    std::cout << "1. Add contact" << std::endl;
    std::cout << "2. Delete contact" << std::endl;
    std::cout << "3. Display all contacts" << std::endl;
    std::cout << "4. EXIT" << std::endl;
    std::cout << "Your Selection >> ";
}

ManagementSystem::~ManagementSystem()
{
    std::ofstream outFile;
    outFile.open("Contact.txt", std::ios::trunc);
    
    std::map<long, Contact>::iterator itr;
    
    for (itr = contacts.begin(); itr != contacts.end(); ++itr)
    {
        outFile << itr->second;
    }
    
    outFile.close();
}
