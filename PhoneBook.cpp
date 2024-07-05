#include <iostream>
#include <string>

class Contact {
private:
    std::string name;
    std::string phone;

public:
    
    Contact(const std::string& name, const std::string& phone)
        : name(name), phone(phone) {}

    
    const std::string& getName() const {
        return name;
    }

    
    const std::string& getPhone() const {
        return phone;
    }

    
    void print() const {
        std::cout << "Name: " << name << ", Phone: " << phone << std::endl;
    }
};

class PhoneBook {
private:
    Contact** contacts;
    int size;
    int capacity;

public:
    
    PhoneBook(int capacity) : size(0), capacity(capacity) {
        contacts = new Contact*[capacity];
    }

    
    ~PhoneBook() {
        for (int i = 0; i < size; ++i) {
            delete contacts[i];
        }
        delete[] contacts;
    }

    
    void addContact(const std::string& name, const std::string& phone) {
        if (size < capacity) {
            contacts[size++] = new Contact(name, phone);
        } else {
            std::cout << "Phone book is full!" << std::endl;
        }
    }

    Contact* findContact(const std::string& name) const {
        for (int i = 0; i < size; ++i) {
            if (contacts[i]->getName() == name) {
                return contacts[i];
            }
        }
        return nullptr;
    }

   
    void printContacts() const {
        for (int i = 0; i < size; ++i) {
            contacts[i]->print();
        }
    }
};

int main() {
    PhoneBook phoneBook(10);

    phoneBook.addContact("Alice", "123-456-7890");
    phoneBook.addContact("Bob", "987-654-3210");

    phoneBook.printContacts();

    Contact* contact = phoneBook.findContact("Alice");
    if (contact) {
        std::cout << "Found contact: ";
        contact->print();
    } else {
        std::cout << "Contact not found!" << std::endl;
    }

    return 0;
}






   