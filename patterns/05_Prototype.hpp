#ifndef _PROTOTYPE_
#define _PROTOTYPE_

#include <iostream>
#include <string>

using namespace std;

namespace PatternPrototype {
	class Animal {
	public:
		virtual ~Animal()
		{
		}

		virtual void setName(string *name)
		{
		}

		virtual string getName() = 0;

		virtual Animal *clone() const = 0;
	};

	class Sheep : public Animal {
		string *name_;

		Sheep(const Sheep &donor)
		{
			name_ = donor.name_;
		}

	public:
		Sheep()
		{
		}

		void setName(string *name) override
		{
			name_ = name;
		}

		string getName() override
		{
			return *name_;
		}

		Sheep *clone() const
		{
			return new Sheep(*this);
		}
	};
}

#endif // _PROTOTYPE_