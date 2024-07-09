#ifndef ENGINE_HPP
#define ENGINE_HPP

#include "part.hpp"

class Engine : public Part
{
public:
	void print() override
	{
		std::cout << "Engine part\n";
	}
};

#endif