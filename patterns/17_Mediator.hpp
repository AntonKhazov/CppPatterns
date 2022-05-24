#ifndef _MEDIATOR_
#define _MEDIATOR_

#include <iostream>
#include <string>

using namespace std;

namespace PatternMediator {
	class Employee;

	class Mediator {
	public:
		virtual void Notify(Employee *emp, string msg) = 0;
	};

	class Employee {
	protected:
		Mediator *mediator_;

	public:
		Employee(Mediator *med = nullptr) : mediator_(med)
		{
		}

		virtual ~Employee()
		{
		}

		void setMediator(Mediator *med)
		{
			mediator_ = med;
		}
	};

	class Designer : public Employee {
		bool isWorking_;

	public:
		Designer(Mediator *med = nullptr) : Employee(med)
		{
		}

		void executeWork()
		{
			cout << "<-Дизайнер в работе" << endl;
			mediator_->Notify(this, "дизайнер проектирует...");
		}

		void setWork(bool state)
		{
			isWorking_ = state;

			if (state)
				cout << "<-Дизайнер освобождён от работы" << endl;
			else
				cout << "<-Дизайнер занят" << endl;
		}
	};

	class Director : public Employee {
	private:
		string text_;

	public:
		Director(Mediator *med = nullptr) : Employee(med)
		{
		}

		void giveCommand(string txt)
		{
			text_ = txt;

			if (text_.empty())
				cout << "->Директор знает, что дизайнер уже работает" << endl;
			else
				cout << "->Директор дал команду: " << text_ << endl;

			mediator_->Notify(this, text_);
		}
	};

	class Controller : public Mediator {
		Designer *designer_;
		Director *director_;

	public:
		Controller(Designer *des, Director *dir)
		{
			designer_ = des;
			director_ = dir;

			designer_->setMediator(this);
			director_->setMediator(this);
		}

		virtual ~Controller()
		{
		}

		void Notify(Employee *emp, string msg) override
		{
			auto dir = dynamic_cast<Director *>(emp);
			if (dir)
				designer_->setWork(!msg.empty());

			auto des = dynamic_cast<Designer *>(emp);
			if (des &&
				msg == "дизайнер проектирует...")
				director_->giveCommand("");
		}
	};
}

#endif // _MEDIATOR_