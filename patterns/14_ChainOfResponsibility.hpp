#ifndef _CHAIN_OF_RESPONSIBILITY_
#define _CHAIN_OF_RESPONSIBILITY_

#include <iostream>
#include <string>

using namespace std;

namespace PatternChainOfResponsibility {
	class IWorker {
	public:
		virtual IWorker *setNextWorker(IWorker *worker) = 0;

		virtual string execute(string command) = 0;
	};

	class AbstractWorker : public IWorker {
		IWorker *nextWorker_;

	public:
		AbstractWorker() : nextWorker_(nullptr)
		{
		}

		IWorker *setNextWorker(IWorker *worker) override
		{
			nextWorker_ = worker;

			return worker;
		}

		string execute(string command) override
		{
			if (nextWorker_)
				return nextWorker_->execute(command);

			return {};
		}
	};

	class Designer : public AbstractWorker {
	public:
		string execute(string command) override
		{
			if (command == "спроектировать дом")
				return "Проектировщик выполнил команду: " + command;
			else
				return AbstractWorker::execute(command);
		}
	};

	class Carpenters : public AbstractWorker {
	public:
		string execute(string command) override
		{
			if (command == "класть кирпич")
				return "Плотник выполнил команду: " + command;
			else
				return AbstractWorker::execute(command);
		}
	};

	class FinishingWorker : public AbstractWorker {
	public:
		string execute(string command) override
		{
			if (command == "клеить обои")
				return "Отделочник выполнил команду: " + command;
			else
				return AbstractWorker::execute(command);
		}
	};

	void giveCommand(IWorker *worker, string command)
	{
		string str = worker->execute(command);

		if (str.empty()) {
			cout << command << " - никто не умеет делать" << endl;
		}
		else {
			cout << str << endl;
		}
	}
}

#endif // _CHAIN_OF_RESPONSIBILITY_