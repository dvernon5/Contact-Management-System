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

    private:
        std::string firstName;
        std::string lastName;
        std::string email;
}
