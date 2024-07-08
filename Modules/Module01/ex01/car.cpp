#include "car.hpp"
#include <iostream>

Car::Car()
{
	std::cout << "Default Constructor called" << std::endl;
}

Car::Car(std::string make, std::string model, int year) : make(make), model(model), year(year)
{
	std::cout << "Constructor called" << std::endl;
}

Car::Car(const Car &other)
{
	std::cout << "Copy constructor called" << std::endl;
}

Car &Car::operator=(const Car &other)
{
	std::cout << "copy operator called" << std::endl;

	if (this != &other)
	{
		make = other.make;
		model = other.model;
		year = other.year;
	}
	return *this;
}

Car::~Car()
{
	std::cout << "destructor called" << std::endl;
}

void Car::drive()
{
	std::cout << make << ", " << model << ", " << year << std::endl;
}