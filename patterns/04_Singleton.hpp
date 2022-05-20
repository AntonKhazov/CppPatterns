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

		static DatabaseHelper *databaseConnection;
		string data;

	public:
		DatabaseHelper(const DatabaseHelper &) = delete;
		void operator=(const DatabaseHelper &) = delete;

		static DatabaseHelper *getConnection()
		{
			if (databaseConnection == nullptr)
				databaseConnection = new DatabaseHelper();

			return databaseConnection;
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

	DatabaseHelper *DatabaseHelper::databaseConnection = nullptr;
}

#endif // _SINGLETON_