#ifndef _ABSTRACT_FACTORY_
#define _ABSTRACT_FACTORY_

#include <iostream>

using namespace std;

namespace PatternAbstractFactory {
	// Абстрактный двигатель
	class IEngine {
	public:
		virtual void releaseEngine() = 0;
	};

	// Японский двигатель
	class JapaneseEngine : public IEngine {
	public:
		void releaseEngine() override
		{
			cout << "японский двигатель" << endl;
		}
	};

	// Российский двигатель
	class RussianEngine : public IEngine {
	public:
		void releaseEngine() override
		{
			cout << "российский двигатель" << endl;
		}
	};

	// Интерфейс производства автомобилей
	class ICar {
	public:
		virtual void releaseCar(IEngine *engine) = 0;
	};

	// Реализация интерфейса выпуска японского автомобиля
	class JapaneseCar : public ICar {
	public:
		void releaseCar(IEngine *engine) override
		{
			cout << "Собрали японский автомобиль: ";
			engine->releaseEngine();
		}
	};

	// Реализация интерфейса выпуска российского автомобиля
	class RussianCar : public ICar {
	public:
		void releaseCar(IEngine *engine) override
		{
			cout << "Собрали российский автомобиль: ";
			engine->releaseEngine();
		}
	};

	// Интерфейс фабрики по производству автомобилей и их двигателей
	class IFactory {
	public:
		virtual IEngine *createEngine() = 0;
		virtual ICar *createCar() = 0;
	};

	// Реализация интерфейса японской фабрики
	class JapaneseFactory : public IFactory {
	public:
		IEngine *createEngine() override
		{
			return new JapaneseEngine();
		}

		ICar *createCar() override
		{
			return new JapaneseCar();
		}
	};

	// Реализация интерфейса российской фабрики
	class RussianFactory : public IFactory {
	public:
		IEngine *createEngine() override
		{
			return new RussianEngine();
		}

		ICar *createCar() override
		{
			return new RussianCar();
		}
	};
}

#endif // _ABSTRACT_FACTORY_