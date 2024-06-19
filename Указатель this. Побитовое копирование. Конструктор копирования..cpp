#include <iostream>
#include <cstring> 

class Person {
private:
    char* name;
public:
   
    Person(const char* name) {
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
    }

    
    Person(const Person& other) {
        name = new char[strlen(other.name) + 1];
        strcpy(name, other.name);
    }

    
    ~Person() {
        delete[] name;
    }

    
    const char* getName() const {
        return name;
    }

    
    void display() const {
        std::cout << "Person: " << name << std::endl;
    }
};

class Apartment {
private:
    Person** residents;
    int residentCount;
    int maxResidents;
public:
    
    Apartment(int maxResidents) : residentCount(0), maxResidents(maxResidents) {
        residents = new Person*[maxResidents];
    }

   
    Apartment(const Apartment& other) : residentCount(other.residentCount), maxResidents(other.maxResidents) {
        residents = new Person*[maxResidents];
        for (int i = 0; i < residentCount; ++i) {
            residents[i] = new Person(*other.residents[i]);
        }
    }

   
    ~Apartment() {
        for (int i = 0; i < residentCount; ++i) {
            delete residents[i];
        }
        delete[] residents;
    }

   
    void addResident(const Person& person) {
        if (residentCount < maxResidents) {
            residents[residentCount++] = new Person(person);
        } else {
            std::cout << "Apartment is full!" << std::endl;
        }
    }

   
    void display() const {
        std::cout << "Apartment with " << residentCount << " residents:" << std::endl;
        for (int i = 0; i < residentCount; ++i) {
            residents[i]->display();
        }
    }
};

class House {
private:
    Apartment** apartments;
    int apartmentCount;
    int maxApartments;
public:
    
    House(int maxApartments) : apartmentCount(0), maxApartments(maxApartments) {
        apartments = new Apartment*[maxApartments];
    }

    
    House(const House& other) : apartmentCount(other.apartmentCount), maxApartments(other.maxApartments) {
        apartments = new Apartment*[maxApartments];
        for (int i = 0; i < apartmentCount; ++i) {
            apartments[i] = new Apartment(*other.apartments[i]);
        }
    }

    
    ~House() {
        for (int i = 0; i < apartmentCount; ++i) {
            delete apartments[i];
        }
        delete[] apartments;
    }

   
    void addApartment(const Apartment& apartment) {
        if (apartmentCount < maxApartments) {
            apartments[apartmentCount++] = new Apartment(apartment);
        } else {
            std::cout << "House is full!" << std::endl;
        }
    }

    
    void display() const {
        std::cout << "House with " << apartmentCount << " apartments:" << std::endl;
        for (int i = 0; i < apartmentCount; ++i) {
            apartments[i]->display();
        }
    }
};

int main() {
    
    Person person1("Alice");
    Person person2("Bob");
    Person person3("Charlie");

    
    Apartment apartment1(2);
    apartment1.addResident(person1);
    apartment1.addResident(person2);

    
    Apartment apartment2(1);
    apartment2.addResident(person3);

    
    House house(2);
    house.addApartment(apartment1);
    house.addApartment(apartment2);

    
    house.display();

    return 0;
}


      


