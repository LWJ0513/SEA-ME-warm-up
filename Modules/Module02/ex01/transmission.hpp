#ifndef TRANSMISSION_HPP
#define TRANSMISSION_HPP

#include "part.hpp"

class Transmission : public Part
{
public:
	void print() override
	{
		std::cout << "Transmission part\n";
	}
};

#endif