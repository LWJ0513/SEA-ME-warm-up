#include "car.hpp"
#include <iostream>

Car::Car()
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
		name = other.name;
		speed = other.speed;
	}
	return *this;
}

Car::~Car()
{
	std::cout << "destructor called" << std::endl;
}