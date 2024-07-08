#ifndef CAR_HPP
#define CAR_HPP

#include <string>

class Car
{
private:

public:
	std::string name;
	int speed;

	Car();
	Car(const Car &other);
	Car &operator=(const Car &other);
	~Car();
};

#endif