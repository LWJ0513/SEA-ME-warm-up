#include "car.hpp"
#include "sportsCar.hpp"
#include <iostream>

int main()
{
	std::cout << "Creating a Car object" << std::endl;
	Car car1("Toyota", "Camry", 2020);
	car1.drive();

	std::cout << "\nCreating a SportsCar object" << std::endl;
	SportsCar sportsCar1;
	sportsCar1.drive();

	std::cout << "\nCopying SportsCar object using copy constructor" << std::endl;
	SportsCar sportsCar2 = sportsCar1;
	sportsCar2.drive();

	std::cout << "\nAssigning SportsCar object using copy assignment operator" << std::endl;
	SportsCar sportsCar3;
	sportsCar3 = sportsCar1;
	sportsCar3.drive();

	std::cout << "\nCreating a new SportsCar with parameters and assigning it" << std::endl;
	SportsCar sportsCar4;
	sportsCar4 = SportsCar();
	sportsCar4.drive();

	return 0;
}
