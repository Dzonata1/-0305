#include <iostream>
#include <cstring>
#include <vector>
#include <fstream>

class Reservoir {
private:
    char* name;
    double width;
    double length;
    double maxDepth;
    char* type;

public:
    
    Reservoir() : name(nullptr), width(0), length(0), maxDepth(0), type(nullptr) {}

   
    explicit Reservoir(const char* name, double width, double length, double maxDepth, const char* type) {
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
        this->width = width;
        this->length = length;
        this->maxDepth = maxDepth;
        this->type = new char[strlen(type) + 1];
        strcpy(this->type, type);
    }

    
    Reservoir(const Reservoir& other) {
        name = new char[strlen(other.name) + 1];
        strcpy(name, other.name);
        width = other.width;
        length = other.length;
        maxDepth = other.maxDepth;
        type = new char[strlen(other.type) + 1];
        strcpy(type, other.type);
    }

    
    ~Reservoir() {
        delete[] name;
        delete[] type;
    }

    
    double getVolume() const {
        return width * length * maxDepth;
    }

    
    double getSurfaceArea() const {
        return width * length;
    }

  
    bool isSameType(const Reservoir& other) const {
        return strcmp(type, other.type) == 0;
    }

    
    bool isLargerSurfaceArea(const Reservoir& other) const {
        if (!isSameType(other)) {
            std::cerr << "Reservoirs are not of the same type." << std::endl;
            return false;
        }
        return getSurfaceArea() > other.getSurfaceArea();
    }

   
    Reservoir& operator=(const Reservoir& other) {
        if (this == &other) {
            return *this;
        }
        delete[] name;
        delete[] type;
        name = new char[strlen(other.name) + 1];
        strcpy(name, other.name);
        width = other.width;
        length = other.length;
        maxDepth = other.maxDepth;
        type = new char[strlen(other.type) + 1];
        strcpy(type, other.type);
        return *this;
    }

    
    void setName(const char* newName) {
        delete[] name;
        name = new char[strlen(newName) + 1];
        strcpy(name, newName);
    }

    const char* getName() const {
        return name;
    }

    void setWidth(double newWidth) {
        width = newWidth;
    }

    double getWidth() const {
        return width;
    }

    void setLength(double newLength) {
        length = newLength;
    }

    double getLength() const {
        return length;
    }

    void setMaxDepth(double newMaxDepth) {
        maxDepth = newMaxDepth;
    }

    double getMaxDepth() const {
        return maxDepth;
    }

    void setType(const char* newType) {
        delete[] type;
        type = new char[strlen(newType) + 1];
        strcpy(type, newType);
    }

    const char* getType() const {
        return type;
    }

    
    void display() const {
        std::cout << "Name: " << name << "\nType: " << type << "\nWidth: " << width << "\nLength: " << length << "\nMax Depth: " << maxDepth << "\nVolume: " << getVolume() << "\nSurface Area: " << getSurfaceArea() << std::endl;
    }
};


class ReservoirManager {
private:
    std::vector<Reservoir> reservoirs;

public:
    void addReservoir(const Reservoir& reservoir) {
        reservoirs.push_back(reservoir);
    }

    void removeReservoir(size_t index) {
        if (index < reservoirs.size()) {
            reservoirs.erase(reservoirs.begin() + index);
        } else {
            std::cerr << "Index out of bounds." << std::endl;
        }
    }

    void displayAll() const {
        for (const auto& reservoir : reservoirs) {
            reservoir.display();
            std::cout << std::endl;
        }
    }

    void saveToTextFile(const std::string& filename) const {
        std::ofstream outFile(filename);
        if (outFile.is_open()) {
            for (const auto& reservoir : reservoirs) {
                outFile << reservoir.getName() << "\n" << reservoir.getType() << "\n" << reservoir.getWidth() << "\n" << reservoir.getLength() << "\n" << reservoir.getMaxDepth() << "\n";
            }
            outFile.close();
        } else {
            std::cerr << "Unable to open file for writing." << std::endl;
        }
    }

    void saveToBinaryFile(const std::string& filename) const {
        std::ofstream outFile(filename, std::ios::binary);
        if (outFile.is_open()) {
            for (const auto& reservoir : reservoirs) {
                size_t nameLength = strlen(reservoir.getName()) + 1;
                outFile.write(reinterpret_cast<const char*>(&nameLength), sizeof(nameLength));
                outFile.write(reservoir.getName(), nameLength);

                size_t typeLength = strlen(reservoir.getType()) + 1;
                outFile.write(reinterpret_cast<const char*>(&typeLength), sizeof(typeLength));
                outFile.write(reservoir.getType(), typeLength);

                double width = reservoir.getWidth();
                outFile.write(reinterpret_cast<const char*>(&width), sizeof(width));

                double length = reservoir.getLength();
                outFile.write(reinterpret_cast<const char*>(&length), sizeof(length));

                double maxDepth = reservoir.getMaxDepth();
                outFile.write(reinterpret_cast<const char*>(&maxDepth), sizeof(maxDepth));
            }
            outFile.close();
        } else {
            std::cerr << "Unable to open file for writing." << std::endl;
        }
    }
};


int main() {
    ReservoirManager manager;

    Reservoir res1("Lake Baikal", 80.0, 640.0, 1642.0, "Lake");
    Reservoir res2("Caspian Sea", 435.0, 1200.0, 1025.0, "Sea");
    Reservoir res3("Black Sea", 580.0, 1130.0, 2210.0, "Sea");

    manager.addReservoir(res1);
    manager.addReservoir(res2);
    manager.addReservoir(res3);

    std::cout << "All reservoirs:" << std::endl;
    manager.displayAll();

    std::cout << "\nSaving to text file..." << std::endl;
    manager.saveToTextFile("reservoirs.txt");

    std::cout << "\nSaving to binary file..." << std::endl;
    manager.saveToBinaryFile("reservoirs.bin");

    return 0;
}



      


