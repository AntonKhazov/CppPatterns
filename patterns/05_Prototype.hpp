#ifndef _PROTOTYPE_
#define _PROTOTYPE_

#include <iostream>
#include <string>

using namespace std;

namespace PatternPrototype {
	class Animal {
	public:
		virtual void setName(string *name)
		{
		}

		virtual string getName() = 0;

		virtual Animal *clone() const = 0;
	};

	class Sheep : public Animal {
		string *name;

		Sheep(const Sheep &donor)
		{
			name = donor.name;
		}

	public:
		Sheep()
		{
		}

		~Sheep()
		{
			delete name;
		}

		void setName(string *name) override
		{
			this->name = name;
		}

		string getName() override
		{
			return *name;
		}

		Sheep *clone() const
		{
			return new Sheep(*this);
		}
	};
}

#endif // _PROTOTYPE_