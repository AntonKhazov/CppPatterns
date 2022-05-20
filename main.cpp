#include <iostream>

#include "patterns/01_FactoryMethod.hpp"
#include "patterns/02_AbstractFactory.hpp"
#include "patterns/03_Builder.hpp"
#include "patterns/04_Singleton.hpp"
#include "patterns/05_Prototype.hpp"
#include "patterns/06_AdapterObjects.hpp"
#include "patterns/07_AdapterClasses.hpp"
#include "patterns/08_Bridge.hpp"
#include "patterns/09_Composite.hpp"
#include "patterns/10_Decorator.hpp"
#include "patterns/11_Facade.hpp"
#include "patterns/12_Flyweight.hpp"
#include "patterns/13_Proxy.hpp"
#include "patterns/14_ChainOfResponsibility.hpp"
#include "patterns/15_Command.hpp"
#include "patterns/16_Iterator.hpp"
#include "patterns/17_Mediator.hpp"
#include "patterns/18_Memento.hpp"
#include "patterns/19_Observer.hpp"
#include "patterns/20_State.hpp"
#include "patterns/21_Strategy.hpp"
#include "patterns/22_TemplateMethod.hpp"
#include "patterns/23_Visitor.hpp"

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");

	/***************************************************************************
	 *
	 **************************************************************************/

	cout << "1. Фабричный метод (Factory Method):" << endl;
	{
		using namespace PatternFactoryMethod;

		IWorkShop *creator = new CarWorkShop();
		IProduction *car = creator->create();

		creator = new TruckWorkShop();
		IProduction *truck = creator->create();

		car->release();
		truck->release();
	}
	cout << endl;

	/***************************************************************************
	 *
	 **************************************************************************/

	cout << "2. Абстрактная фабрика (Abstract Factory):" << endl;
	{
		using namespace PatternAbstractFactory;

		IFactory *jFactory = new JapaneseFactory();
		IEngine *jEngine = jFactory->createEngine();
		ICar *jCar = jFactory->createCar();

		jCar->releaseCar(jEngine);

		IFactory *rFactory = new RussianFactory();
		IEngine *rEngine = rFactory->createEngine();
		ICar *rCar = rFactory->createCar();

		rCar->releaseCar(rEngine);

		rCar->releaseCar(jEngine);
	}
	cout << endl;

	/***************************************************************************
	 *
	 **************************************************************************/

	cout << "3. Строитель (Builder):" << endl;
	{
		using namespace PatternBuilder;

		IDeveloper *andrDeveloper = new AndroidDeveloper();
		Director director(andrDeveloper);

		Phone *samsung = director.mountFullPhone();
		cout << samsung->aboutPhone() << endl;

		IDeveloper *iphoneDeveloper = new IPhoneDeveloper();
		director.setDeveloper(iphoneDeveloper);

		Phone *iphone = director.mountOnlyPhone();
		cout << iphone->aboutPhone() << endl;
	}
	cout << endl;

	/***************************************************************************
	 *
	 **************************************************************************/

	cout << "4. Одиночка (Singleton):" << endl;
	{
		using namespace PatternSingleton;

		// DatabaseHelper *connection = new DatabaseHelper(); // Ошибка

		DatabaseHelper::getConnection()->insertData("123");

		cout << "Выборка данных из бд: " << DatabaseHelper::getConnection()->selectData() << endl;
	}
	cout << endl;

	/***************************************************************************
	 *
	 **************************************************************************/

	cout << "5. Прототип (Prototype):" << endl;
	{
		using namespace PatternPrototype;

		Sheep *sheepDonor = new Sheep();
		string name = "Долли";
		sheepDonor->setName(&name);

		Sheep *sheepClone = sheepDonor->clone();

		cout << sheepDonor->getName() << endl;
		cout << sheepClone->getName() << endl;
	}
	cout << endl;

	/***************************************************************************
	 *
	 **************************************************************************/

	cout << "6. Адаптер (Adapter). Реализация на уровне объектов:" << endl;
	{
		using namespace PatternAdapterObjects;

		float kg = 55.0; // кг
		float lb = 55.0; // фунты

		Scales *rScales = new RussianScales(&kg);
		Scales *bScales = new AdapterForBritishScales(new BritishScales(&lb));

		cout << *rScales->getWeight() << endl; // кг
		cout << *bScales->getWeight() << endl; // кг
	}
	cout << endl;

	/***************************************************************************
	 *
	 **************************************************************************/

	cout << "7. Адаптер (Adapter). Реализация на уровне классов:" << endl;
	{
		using namespace PatternAdapterClasses;

		float kg = 55.0; // кг
		float lb = 55.0; // фунты

		Scales *rScales = new RussianScales(&kg);
		Scales *bScales = new AdapterForBritishScales(&lb);

		cout << *rScales->getWeight() << endl; // кг
		cout << *bScales->getWeight() << endl; // кг

		rScales->adjust();
		bScales->adjust();
	}
	cout << endl;

	/***************************************************************************
	 *
	 **************************************************************************/

	cout << "8. Мост (Bridge):" << endl;
	{
		using namespace PatternBridge;

		Sender *sender = new EmailSender(new DataBaseReader());
		sender->send();

		sender->setDataReader(new FileReader());
		sender->send();

		sender = new TelegrgamBotSender(new DataBaseReader());
		sender->send();
	}
	cout << endl;

	/***************************************************************************
	 *
	 **************************************************************************/

	cout << "9. Компоновщик (Composite):" << endl;
	{
		using namespace PatternComposite;

		Item *file = new DropDownItem("Файл->");

		Item *create = new DropDownItem("Создать->");
		Item *open = new DropDownItem("Открыть->");
		Item *exit = new ClickableItem("Выход");

		file->add(create);
		file->add(open);
		file->add(exit);

		Item *project = new ClickableItem("Проект...");
		Item *repository = new ClickableItem("Репозиторий...");

		create->add(project);
		create->add(repository);

		Item *solution = new ClickableItem("Решение...");
		Item *folder = new ClickableItem("Папка...");

		open->add(solution);
		open->add(folder);

		file->display();
		cout << endl;

		file->remove(create);

		file->display();
	}
	cout << endl;

	/***************************************************************************
	 *
	 **************************************************************************/

	cout << "10. Декоратор (Decorator):" << endl;
	{
		using namespace PatternDecorator;

		Processor *transmitter = new Transmitter("12345");
		transmitter->process();

		Shell *hammingCoder = new HammingCoder(transmitter);
		hammingCoder->process();

		Shell *encriptor = new Encryptor(hammingCoder);
		encriptor->process();
	}
	cout << endl;

	/***************************************************************************
	 *
	 **************************************************************************/

	cout << "11. Фасад (Facade):" << endl;
	{
		using namespace PatternFacade;

		MarketPlace marketPlace;
		marketPlace.productReceipt();

		cout << "--------------------------" << endl;

		marketPlace.productRelease();
	}
	cout << endl;

	/***************************************************************************
	 *
	 **************************************************************************/

	cout << "12. Легковес (Flyweight):" << endl;
	{
		using namespace PatternFlyweight;
	}
	cout << endl;

	/***************************************************************************
	 *
	 **************************************************************************/

	cout << "13. Заместитель (Proxy):" << endl;
	{
		using namespace PatternProxy;
	}
	cout << endl;

	/***************************************************************************
	 *
	 **************************************************************************/

	cout << "14. Цепочка обязанностей (Chain of responsibility):" << endl;
	{
		using namespace PatternChainOfResponsibility;
	}
	cout << endl;

	/***************************************************************************
	 *
	 **************************************************************************/

	cout << "15. Команда (Command):" << endl;
	{
		using namespace PatternCommand;
	}
	cout << endl;

	/***************************************************************************
	 *
	 **************************************************************************/

	cout << "16. Итератор (Iterator):" << endl;
	{
		using namespace PatternIterator;
	}
	cout << endl;

	/***************************************************************************
	 *
	 **************************************************************************/

	cout << "17. Посредник (Mediator):" << endl;
	{
		using namespace PatternMediator;
	}
	cout << endl;

	/***************************************************************************
	 *
	 **************************************************************************/

	cout << "18. Снимок (Memento):" << endl;
	{
		using namespace PatternMemento;
	}
	cout << endl;

	/***************************************************************************
	 *
	 **************************************************************************/

	cout << "19. Наблюдатель (Observer):" << endl;
	{
		using namespace PatternObserver;
	}
	cout << endl;

	/***************************************************************************
	 *
	 **************************************************************************/

	cout << "20. Состояние (State):" << endl;
	{
		using namespace PatternState;
	}
	cout << endl;

	/***************************************************************************
	 *
	 **************************************************************************/

	cout << "21. Стратегия (Strategy):" << endl;
	{
		using namespace PatternStrategy;
	}
	cout << endl;

	/***************************************************************************
	 *
	 **************************************************************************/

	cout << "22. Шаблонный метод (Template method):" << endl;
	{
		using namespace PatternTemplateMethod;
	}
	cout << endl;

	/***************************************************************************
	 *
	 **************************************************************************/

	cout << "23. Посетитель (Visitor):" << endl;
	{
		using namespace PatternVisitor;
	}
	cout << endl;
}