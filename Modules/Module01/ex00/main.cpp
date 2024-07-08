#include "car.hpp"

int main()
{
	Car a = Car();
	Car b = Car(a);

	b = a;
}
