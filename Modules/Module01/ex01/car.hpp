#ifndef CAR_HPP
#define CAR_HPP

#include <string>

class Car
{
private:
	std::string make;
	std::string model;
	int year;

public:
	Car();
	Car(std::string, std::string, int);
	Car(const Car &other);
	Car &operator=(const Car &other);
	~Car();

	void drive();
};

#endif