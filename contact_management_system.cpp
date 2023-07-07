#include <iostream>
#include <string>

class Contact 
{
    public:
        Contact() = default;
        Contact(std::string firstName, std::string lastName, std::string email) : firstName(firstName), lastName(lastName), email(email) {}
        getFirstName(){ return firstName; }
        getLastName(){ return lastName; }
        getEmail(){ return email; }
        setFirstName(std::string firstName){ this->firstName = firstName; }
        setLastName(std::string lastName){ this->lastName = lastName; }

        void addContact(std::vector<Contact>&);
    private:
        std::string firstName;
        std::string lastName;
        std::string email;
}

int main()
{
    
}

void addContact(std::vector<Contact>& contacts)
{
    std::string firstName;
    std::cout << "Enter your first name: ";
    getline(std::cin, firstName);

    std::string lastName;
    std::cout << "Enter your last name: ";
    getline(std::cin, lastName);

    std::string email;
    std::cout << "Enter your email: ";
    getline(std::cin, email);

    contacts.push_back(Student(firstName, lastName, email));

    std::cout << firstName << ", " << lastname << ", " << email << ", " << "was successfully added." << std::endl;
}
