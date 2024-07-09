#ifndef SPORTSCAR_HPP
#define SPORTSCAR_HPP

#include "car.hpp"
#include <string>

class SportsCar : public Car
{

private:
	int topSpeed;

public:
	void drive() override;

	SportsCar();
	SportsCar(std::string, std::string, int, int);
	SportsCar(const SportsCar &other);
	SportsCar &operator=(const SportsCar &other);
	~SportsCar();
};

#endif
