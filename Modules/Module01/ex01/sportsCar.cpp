#include "sportsCar.hpp"
#include <iostream>

void SportsCar::drive()
{
	Car::drive();
	std::cout << "top speed : " << topSpeed << std::endl;
}

SportsCar::SportsCar() : topSpeed(0)
{
	std::cout << "Sports Car class Default Constructor called" << std::endl;
}

SportsCar::SportsCar(const SportsCar &other) : Car(other)
{
	std::cout << "Sports Car class Copy constructor called" << std::endl;
	topSpeed = other.topSpeed;
}

SportsCar &SportsCar::operator=(const SportsCar &other)
{
	std::cout << "Sports Car class copy operator called" << std::endl;

	if (this != &other)
	{
		Car::operator=(other);
		topSpeed = other.topSpeed;
	}
	return *this;
}

SportsCar::~SportsCar()
{
	std::cout << "Sports Car class destructor called" << std::endl;
}