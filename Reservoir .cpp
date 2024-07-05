#include <iostream>
#include <cstring>

class Reservoir {
private:
    char* name;
    double width;
    double length;
    double maxDepth;
    char* type;

public:
    
    Reservoir() : name(nullptr), width(0), length(0), maxDepth(0), type(nullptr) {}

    Reservoir(const char* name, double width, double length, double maxDepth, const char* type)
        : width(width), length(length), maxDepth(maxDepth) {
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
        this->type = new char[strlen(type) + 1];
        strcpy(this->type, type);
    }

    
    ~Reservoir() {
        delete[] name;
        delete[] type;
    }

    
    Reservoir(const Reservoir& other)
        : width(other.width), length(other.length), maxDepth(other.maxDepth) {
        name = new char[strlen(other.name) + 1];
        strcpy(name, other.name);
        type = new char[strlen(other.type) + 1];
        strcpy(type, other.type);
    }

   
    double calculateVolume() const {
        return width * length * maxDepth;
    }

    double calculateSurfaceArea() const {
        return width * length;
    }

    bool isSameType(const Reservoir& other) const {
        return strcmp(type, other.type) == 0;
    }

    bool compareSurfaceArea(const Reservoir& other) const {
        return isSameType(other) && calculateSurfaceArea() > other.calculateSurfaceArea();
    }

    const char* getName() const { return name; }
    const char* getType() const { return type; }
    void setName(const char* name) {
        delete[] this->name;
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
    }
    void setType(const char* type) {
        delete[] this->type;
        this->type = new char[strlen(type) + 1];
        strcpy(this->type, type);
    }

    Reservoir& operator=(const Reservoir& other) {
        if (this != &other) {
            width = other.width;
            length = other.length;
            maxDepth = other.maxDepth;

            delete[] name;
            name = new char[strlen(other.name) + 1];
            strcpy(name, other.name);

            delete[] type;
            type = new char[strlen(other.type) + 1];
            strcpy(type, other.type);
        }
        return *this;
    }

    void print() const {
        std::cout << "Name: " << name << ", Type: " << type << ", Surface Area: " << calculateSurfaceArea() << ", Volume: " << calculateVolume() << std::endl;
    }
};

int main() {
    Reservoir lake("Big Lake", 100.0, 200.0, 15.0, "Lake");
    Reservoir pond("Small Pond", 50.0, 50.0, 5.0, "Pond");

    lake.print();
    pond.print();

    pond.setType("Lake");

    if (lake.isSameType(pond)) {
        std::cout << "Both reservoirs are of the same type." << std::endl;
    } else {
        std::cout << "Reservoirs are of different types." << std::endl;
    }

    if (lake.compareSurfaceArea(pond)) {
        std::cout << "Big Lake has a larger surface area than Small Pond." << std::endl;
    } else {
        std::cout << "Big Lake does not have a larger surface area than Small Pond." << std::endl;
    }

    Reservoir lakeCopy = lake;
    lakeCopy.setName("Copied Lake");

    lakeCopy.print();

    return 0;
}

