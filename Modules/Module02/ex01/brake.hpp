#ifndef BRAKE_HPP
#define BRAKE_HPP

#include "part.hpp"

class Brake : public Part
{
public:
	void print() override
	{
		std::cout << "Brake part\n";
	}
};

#endif