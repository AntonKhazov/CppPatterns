#ifndef _DECORATOR_
#define _DECORATOR_

#include <iostream>

using namespace std;

class Processor {
public:
	virtual void process() = 0;
};

class Transmitter : public Processor {
private:
	string data;

public:
	Transmitter(string d) : data(d)
	{
	}

	void process() override
	{
		cout << "Данные " << data << " переданы по каналу связи" << endl;
	}
};

class Shell : public Processor {
protected:
	Processor *processor;

public:
	Shell(Processor *pr) : processor(pr)
	{
	}

	void process() override
	{
		processor->process();
	}
};

class HammingCoder : public Shell {
public:
	HammingCoder(Processor *pr) : Shell(pr)
	{
	}

	void process() override
	{
		cout << "Наложен помехоустойчивый код Хамминга->";
		processor->process();
	}
};

class Encryptor : public Shell {
public:
	Encryptor(Processor *pr) : Shell(pr)
	{
	}

	void process() override
	{
		cout << "Шифрование данных->";
		processor->process();
	}
};

#endif // _DECORATOR_