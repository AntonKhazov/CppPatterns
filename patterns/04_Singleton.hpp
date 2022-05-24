#ifndef _SINGLETON_
#define _SINGLETON_

#include <iostream>
#include <string>

using namespace std;

namespace PatternSingleton {
	class DatabaseHelper {
		DatabaseHelper()
		{
			cout << "Подключение к бд" << endl;
		}

		static DatabaseHelper *databaseConnection_;
		string data;

	public:
		DatabaseHelper(const DatabaseHelper &) = delete;

		~DatabaseHelper()
		{
			if (databaseConnection_)
				delete databaseConnection_;
		}

		void operator=(const DatabaseHelper &) = delete;

		static DatabaseHelper *getConnection()
		{
			if (databaseConnection_ == nullptr)
				databaseConnection_ = new DatabaseHelper();

			return databaseConnection_;
		}

		string selectData() const
		{
			return data;
		}

		void insertData(string d)
		{
			cout << "Новые данные: " << d << " внесены в бд" << endl;
			data = d;
		}
	};

	DatabaseHelper *DatabaseHelper::databaseConnection_ = nullptr;
}

#endif // _SINGLETON_