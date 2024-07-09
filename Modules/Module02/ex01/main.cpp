#include "car.hpp"

int main()
{
	Car myCar = Car("Chevrolet", "Camaro", 2017, "Bumblebee");
	myCar.printParts();
	myCar.introduce();

	return 0;
}