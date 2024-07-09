#include "car.hpp"
#include "sportsCar.hpp"
#include <iostream>

int main()
{
	std::cout << "Creating a SportsCar object" << std::endl;
	std::unique_ptr<SportsCar> sportsCar1 = std::make_unique<SportsCar>("Ferrari", "488", 2020, 211);
	sportsCar1->drive();

	std::cout << "\nMoving SportsCar object" << std::endl;
	std::unique_ptr<SportsCar> sportsCar2 = std::move(sportsCar1);
	sportsCar2->drive();

	system("leaks a.out");
}
