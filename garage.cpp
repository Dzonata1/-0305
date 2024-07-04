#include<iostream>
using namespace std;
#include<string>
// ����� �����
class Car {
public:
	std::string color;
	std::string model;
	Car(const std::string& color = " ", const std::string& model = " "):

		color (color),
		model(model){}
};
// ����� �����
class Garage {
public:
	int number;
	Car cars[5];
	int carCount;

	Garage(int number):
		number(number),
		carCount(0){}
// ��������� ������ � �����
	bool addCar(const Car& car) {
		if (carCount < 5) {
			cars[carCount] = car;
			carCount++;
			return true;
		} 
		else {
			std::cout << "garage is full" << endl;
			return false;
		}
	}
	// ������� ������
	bool removeCar(int index) {
		if (index >= 0 && index < carCount) {
			Car buf;// ������� �����
			for (int i = index; i < carCount - 1;i++) {
				buf = cars[i];
				cars[i] = cars[i + 1];
				cars[i + 1] = buf;

			}
			carCount--;
			return false;
		}
	}
};

// ��������� ������
int main() {
	Garage garage(1);
	Car car1("black", "kia");
	Car car2("green", "mazda");
	Car car3("red", "nissan");
	// ��������� ������ � �����
	garage.addCar(car1);
	garage.addCar(car2);
	garage.addCar(car3);
	
	cout << "cars in the garage" << endl;
	// ���������  ��� ������ � ������
	for (int i = 0; i < garage.carCount; i++) {
		cout << "color " << garage.cars[i].color << "model " << endl;

	}
	garage.removeCar(1);
	cout << "cars in the garage afrer removing car at index 1;" << endl;
	// ��������� ��� ���������� ������
	for (int i = 0; i < garage.carCount; i++) {
		cout << "color " << garage.cars[i].color << "model " << garage.cars[i].model << endl;
	}
	return 0;
}