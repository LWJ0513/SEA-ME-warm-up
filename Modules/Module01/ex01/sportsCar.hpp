#ifndef SPORTSCAR_HPP
#define SPORTSCAR_HPP

#include "car.hpp"

class SportsCar : public Car
{

private:
	int topSpeed;

public:
	void drive();

	SportsCar();
	SportsCar(const SportsCar &other);
	SportsCar &operator=(const SportsCar &other);
	~SportsCar();
};

#endif
