#ifndef _FACADE_
#define _FACADE_

#include <iostream>

using namespace std;

namespace PatternFacade {
	class ProviderCommunication {
	public:
		void receive()
		{
			cout << "Получение продукции" << endl;
		}

		void payment()
		{
			cout << "Оплата поставщику с удержанием комиссии за продажу продукции" << endl;
		}
	};

	class Site {
	public:
		void placement()
		{
			cout << "Размещение на сайте" << endl;
		}

		void del()
		{
			cout << "Удаление с сайта" << endl;
		}
	};

	class Database {
	public:
		void insert()
		{
			cout << "Запись в базу данных" << endl;
		}

		void del()
		{
			cout << "Удаление из базы данных" << endl;
		}
	};

	class MarketPlace {
	private:
		ProviderCommunication providerCom;
		Site site;
		Database database;

	public:
		void productReceipt()
		{
			providerCom.receive();
			site.placement();
			database.insert();
		}

		void productRelease()
		{
			providerCom.payment();
			site.del();
			database.del();
		}
	};
}

#endif // _FACADE_