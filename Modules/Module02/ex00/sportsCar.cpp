#include "sportsCar.hpp"
#include <iostream>

SportsCar::SportsCar() : topSpeed(0)
{
	std::cout << "Sports Car class Default Constructor called" << std::endl;
}

SportsCar::SportsCar(std::string make, std::string model, int year, int topSpeed) : Car(make, model, year), topSpeed(topSpeed)
{
	std::cout << "Sports Car class Constructor called" << std::endl;
}

SportsCar::SportsCar(const SportsCar &other) : Car(other), topSpeed(other.topSpeed)
{
	std::cout << "Sports Car class Copy constructor called" << std::endl;
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

void SportsCar::drive()
{
	std::cout << "make : " << make << std::endl;
	std::cout << "model : " << model << std::endl;
	std::cout << "year : " << year << std::endl;
	std::cout << "top speed : " << topSpeed << std::endl;
}
