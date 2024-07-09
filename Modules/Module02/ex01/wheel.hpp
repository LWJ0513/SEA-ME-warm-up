#ifndef WHEEL_HPP
#define WHEEL_HPP

#include "part.hpp"

class Wheel : public Part
{
public:
	void print() override
	{
		std::cout << "Wheel part\n";
	}
};

#endif