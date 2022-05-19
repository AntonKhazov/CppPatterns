#ifndef _FACTORY_METHOD_
#define _FACTORY_METHOD_

#include <iostream>

using namespace std;

// Интерфейс выпуска автомобилей
class IProduction {
public:
	virtual void release() = 0;
};

// Новый легковой автомобиль
class Car : public IProduction {
public:
	void release() override
	{
		cout << "Выпущен новый легковой автомобиль" << endl;
	}
};

// Новый грузовой автомобиль
class Truck : public IProduction {
public:
	void release() override
	{
		cout << "Выпущен новый грузовой автомобиль" << endl;
	}
};

// Абстрактный цех по производству автомобилей
class IWorkShop {
public:
	// Абстрактный автомобиль
	virtual IProduction *create() = 0;
};

// Цех по производству легковых автомобилей
class CarWorkShop : public IWorkShop {
public:
	IProduction *create() override
	{
		return new Car();
	}
};

// Цех по производству легковых автомобилей
class TruckWorkShop : public IWorkShop {
public:
	IProduction *create() override
	{
		return new Truck();
	}
};

#endif // _FACTORY_METHOD_