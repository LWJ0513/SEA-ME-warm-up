#ifndef CAR_HPP
#define CAR_HPP

#include "engine.hpp"
#include "brake.hpp"
#include "transmission.hpp"
#include "wheel.hpp"

class Car
{
private:
	Engine *engine_;
	Wheel *wheels_;
	Brake *brakes_;
	Transmission *transmission_;

	std::string company;
	std::string model;
	int year;
	std::string name;

public:
	void introduce()
	{
		std::cout << "company : " << company << std::endl;
		std::cout << "model : " << model << std::endl;
		std::cout << "year : " << year << std::endl;
		std::cout << "name : " << name << std::endl;
	}

	Car()
	{
		engine_ = new Engine();
		wheels_ = new Wheel[4];
		brakes_ = new Brake[4];
		transmission_ = new Transmission();
	}

	Car(std::string company, std::string model, int year, std::string name) : company(company), model(model), year(year), name(name)
	{
		engine_ = new Engine();
		wheels_ = new Wheel[4];
		brakes_ = new Brake[4];
		transmission_ = new Transmission();
	}

	void printParts()
	{
		engine_->print();
		for (int i = 0; i < 4; ++i)
		{
			wheels_[i].print();
			brakes_[i].print();
		}
		transmission_->print();
	}

	~Car()
	{
		delete engine_;
		delete[] wheels_;
		delete[] brakes_;
		delete transmission_;
	}
};

#endif