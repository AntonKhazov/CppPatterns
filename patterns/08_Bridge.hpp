#ifndef _BRIDGE_
#define _BRIDGE_

#include <iostream>

using namespace std;

namespace PatternBridge {
	class DataReader {
	public:
		virtual ~DataReader()
		{
		}

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
		DataReader *reader_;

	public:
		Sender(DataReader *dr) : reader_(dr)
		{
		}

		virtual ~Sender()
		{
			delete reader_;
		}

		void setDataReader(DataReader *dr)
		{
			reader_ = dr;
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
			reader_->read();
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
			reader_->read();
			cout << "отправлены при помощи Telegram бота" << endl;
		}
	};
}

#endif // _BRIDGE_