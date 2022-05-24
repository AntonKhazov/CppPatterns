#ifndef _BUILDER_
#define _BUILDER_

#include <iostream>

using namespace std;

namespace PatternBuilder {
	// Результат производства
	class Phone {
		string data;

	public:
		Phone()
		{
			data = "";
		}

		string aboutPhone()
		{
			return data;
		}

		void appendData(string str)
		{
			data += str;
		}
	};

	// Интерфейс разработчика
	class IDeveloper {
	public:
		virtual ~IDeveloper()
		{
		}

		virtual void createDisplay() = 0;

		virtual void createBox() = 0;

		virtual void systemInstall() = 0;

		virtual Phone *getPhone() = 0;
	};

	// Разработчик телефонов на android платформе
	class AndroidDeveloper : public IDeveloper {
		Phone *phone;

	public:
		AndroidDeveloper()
		{
			phone = new Phone();
		}

		~AndroidDeveloper()
		{
			delete phone;
		}

		void createDisplay() override
		{
			phone->appendData("Произведен дисплей Samsung; ");
		}

		void createBox() override
		{
			phone->appendData("Произведен корпус Samsung; ");
		}

		void systemInstall() override
		{
			phone->appendData("Установлена система Android; ");
		}

		Phone *getPhone() override
		{
			return phone;
		}
	};

	// Разработчик айфонов
	class IPhoneDeveloper : public IDeveloper {
		Phone *phone;

	public:
		IPhoneDeveloper()
		{
			phone = new Phone();
		}

		~IPhoneDeveloper()
		{
			delete phone;
		}

		void createDisplay() override
		{
			phone->appendData("Произведен дисплей Apple; ");
		}

		void createBox() override
		{
			phone->appendData("Произведен корпус Apple; ");
		}

		void systemInstall() override
		{
			phone->appendData("Установлена система IOS; ");
		}

		Phone *getPhone() override
		{
			return phone;
		}
	};

	// Директор разработчиков
	class Director {
		IDeveloper *developer;

	public:
		Director(IDeveloper *dev) : developer(dev)
		{
		}

		void setDeveloper(IDeveloper *dev)
		{
			developer = dev;
		}

		Phone *mountOnlyPhone()
		{
			developer->createBox();
			developer->createDisplay();

			return developer->getPhone();
		}

		Phone *mountFullPhone()
		{
			developer->createBox();
			developer->createDisplay();
			developer->systemInstall();

			return developer->getPhone();
		}
	};
}

#endif // _BUILDER_