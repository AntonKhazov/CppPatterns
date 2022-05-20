#ifndef _BRIDGE_
#define _BRIDGE_

#include <iostream>

using namespace std;

class DataReader {
public:
	virtual void read() = 0;
};

class DataBaseReader : public DataReader {
public:
	void read() override
	{
		cout << "Данные из Базы данных ";
	}
};

class FileReader : public DataReader {
public:
	void read() override
	{
		cout << "Данные из файла ";
	}
};

class Sender {
protected:
	DataReader *reader;

public:
	Sender(DataReader *dr) : reader(dr)
	{
	}

	void setDataReader(DataReader *dr)
	{
		reader = dr;
	}

	virtual void send() = 0;
};

class EmailSender : public Sender {
public:
	EmailSender(DataReader *dr) : Sender(dr)
	{
	}

	void send() override
	{
		reader->read();
		cout << "отправлены при помощи Email" << endl;
	}
};

class TelegrgamBotSender : public Sender {
public:
	TelegrgamBotSender(DataReader *dr) : Sender(dr)
	{
	}

	void send() override
	{
		reader->read();
		cout << "отправлены при помощи Telegram бота" << endl;
	}
};

#endif // _BRIDGE_