#ifndef _COMMAND_
#define _COMMAND_

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

namespace PatternCommand {
	class ICommand {
	public:
		virtual ~ICommand()
		{
		}

		virtual void positive() = 0;

		virtual void negative() = 0;
	};

	class Conveyor {
	public:
		void on()
		{
			cout << "Конвейер запущен" << endl;
		}

		void off()
		{
			cout << "Конвейер остановлен" << endl;
		}

		void speedIncrease()
		{
			cout << "Увеличена скорость конвейера" << endl;
		}

		void speedDecrease()
		{
			cout << "Снижена скорость конвейера" << endl;
		}
	};

	class ConveyorWorkCommand : public ICommand {
		Conveyor *conveyor_;

	public:
		ConveyorWorkCommand(Conveyor *conveyor) : conveyor_(conveyor)
		{
		}

		void positive() override
		{
			conveyor_->on();
		}

		void negative() override
		{
			conveyor_->off();
		}
	};

	class ConveyorAdjustCommand : public ICommand {
		Conveyor *conveyor_;

	public:
		ConveyorAdjustCommand(Conveyor *conveyor) : conveyor_(conveyor)
		{
		}

		void positive() override
		{
			conveyor_->speedIncrease();
		}

		void negative() override
		{
			conveyor_->speedDecrease();
		}
	};

	class Multipult {
		vector<ICommand *> commands_;
		stack<ICommand *> history_;

	public:
		Multipult()
		{
			commands_.resize(2);
		}

		~Multipult()
		{
			for (auto command : commands_) {
				if (command)
					delete command;
			}
		}

		void setCommand(int button, ICommand *command)
		{
			commands_[button] = command;
		}

		void pressOn(int button)
		{
			commands_[button]->positive();
			history_.push(commands_[button]);
		}

		void pressCancel()
		{
			if (!history_.empty()) {
				history_.top()->negative();
				history_.pop();
			}
		}
	};
}

#endif // _COMMAND_