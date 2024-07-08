#include "car.hpp"
#include <iostream>

Car::Car()
{
	std::cout << "Car class Default Constructor called" << std::endl;
}

Car::Car(std::string make, std::string model, int year) : make(make), model(model), year(year)
{
	std::cout << "Car class Constructor called" << std::endl;
}

Car::Car(const Car &other)
{
	std::cout << "Car class Copy constructor called" << std::endl;

	make = other.make;
	model = other.model;
	year = other.year;
}

Car &Car::operator=(const Car &other)
{
	std::cout << "Car class copy operator called" << std::endl;

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
	std::cout << "Car class destructor called" << std::endl;
}

void Car::drive()
{
	std::cout << make << ", " << model << ", " << year << std::endl;
}