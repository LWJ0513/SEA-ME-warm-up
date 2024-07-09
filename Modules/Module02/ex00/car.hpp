#ifndef CAR_HPP
#define CAR_HPP

#include <string>

class Car
{
protected:
	std::string make;
	std::string model;
	int year;

public:
	Car();
	Car(std::string, std::string, int);
	Car(const Car &other);
	Car &operator=(const Car &other);
	~Car();

	virtual void drive() = 0;
};

#endif