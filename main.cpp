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
		delete creator;

		creator = new TruckWorkShop();
		IProduction *truck = creator->create();
		delete creator;

		car->release();
		truck->release();

		delete car;
		delete truck;
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

		delete jFactory;
		delete rFactory;
		delete jEngine;
		delete rEngine;
		delete jCar;
		delete rCar;
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

		delete iphoneDeveloper;
		delete andrDeveloper;
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

		delete sheepClone;
		delete sheepDonor;
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

		delete rScales;
		delete bScales;
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

		delete sender;

		sender = new TelegrgamBotSender(new DataBaseReader());
		sender->send();

		delete sender;
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

		delete folder;
		delete solution;
		delete repository;
		delete project;
		delete exit;
		delete open;
		delete create;
		delete file;
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

		delete encriptor;
		delete hammingCoder;
		delete transmitter;
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

		FlyweightFactory *factory = new FlyweightFactory(
			{{"Microsoft", "Управляющий"},
			 {"Google", "Android-разработчик"},
			 {"Google", "Web-разработчик"},
			 {"Apple", "IPhone-разработчик"}});

		factory->ListFlyweights();

		AddSpecialistDatabase(*factory,
							  "Google",
							  "Web-разработчик",
							  "Филипп",
							  "PK-6371173");

		AddSpecialistDatabase(*factory,
							  "Apple",
							  "Управляющий",
							  "Иван",
							  "XL-5553331");

		factory->ListFlyweights();

		delete factory;
	}
	cout << endl;

	/***************************************************************************
	 *
	 **************************************************************************/

	cout << "13. Заместитель (Proxy):" << endl;
	{
		using namespace PatternProxy;

		ISite *mySite = new SiteProxy(new Site());

		cout << mySite->getPage(1) << endl;
		cout << mySite->getPage(2) << endl;
		cout << mySite->getPage(3) << endl;

		cout << mySite->getPage(2) << endl;

		delete mySite;
	}
	cout << endl;

	/***************************************************************************
	 *
	 **************************************************************************/

	cout << "14. Цепочка обязанностей (Chain of responsibility):" << endl;
	{
		using namespace PatternChainOfResponsibility;

		Designer *designer = new Designer();
		Carpenters *carpenters = new Carpenters();
		FinishingWorker *finishingWorker = new FinishingWorker();

		designer->setNextWorker(carpenters)->setNextWorker(finishingWorker);

		giveCommand(designer, "спроектировать дом");
		giveCommand(designer, "класть кирпич");
		giveCommand(designer, "клеить обои");

		giveCommand(designer, "провести проводку");

		delete designer;
		delete carpenters;
		delete finishingWorker;
	}
	cout << endl;

	/***************************************************************************
	 *
	 **************************************************************************/

	cout << "15. Команда (Command):" << endl;
	{
		using namespace PatternCommand;

		Conveyor *conveyor = new Conveyor();

		Multipult *multipult = new Multipult();
		multipult->setCommand(0, new ConveyorWorkCommand(conveyor));
		multipult->setCommand(1, new ConveyorAdjustCommand(conveyor));

		multipult->pressOn(0);
		multipult->pressOn(1);
		multipult->pressCancel();
		multipult->pressCancel();

		delete multipult;
		delete conveyor;
	}
	cout << endl;

	/***************************************************************************
	 *
	 **************************************************************************/

	cout << "16. Итератор (Iterator):" << endl;
	{
		using namespace PatternIterator;

		DataStack stack1;

		for (int i = 1; i < 5; i++) {
			stack1.push(i);
		}

		DataStack stack2(stack1);

		cout << boolalpha << (stack1 == stack2) << endl;

		stack1.push(10);

		cout << boolalpha << (stack1 == stack2) << endl;
	}
	cout << endl;

	/***************************************************************************
	 *
	 **************************************************************************/

	cout << "17. Посредник (Mediator):" << endl;
	{
		using namespace PatternMediator;

		Designer *designer = new Designer();
		Director *director = new Director();

		Controller *mediator = new Controller(designer, director);

		director->giveCommand("Проектировать");

		cout << endl;

		designer->executeWork();

		delete designer;
		delete director;
		delete mediator;
	}
	cout << endl;

	/***************************************************************************
	 *
	 **************************************************************************/

	cout << "18. Снимок (Memento):" << endl;
	{
		using namespace PatternMemento;

		Exchange *exchange = new Exchange(10, 10);

		Memory *memory = new Memory(exchange);

		exchange->getDollars();
		exchange->getEuro();

		cout << "---- Продажа доллара, покупка евро ----" << endl;
		exchange->sell();
		exchange->buy();

		exchange->getDollars();
		exchange->getEuro();

		cout << "---- Сохранение состояния -------------" << endl;
		memory->backup();

		cout << "---- Продажа доллара, покупка евро ----" << endl;
		exchange->sell();
		exchange->buy();

		exchange->getDollars();
		exchange->getEuro();

		cout << "---- Восстановление состояния ---------" << endl;
		memory->undo();

		exchange->getDollars();
		exchange->getEuro();

		delete memory;
		delete exchange;
	}
	cout << endl;

	/***************************************************************************
	 *
	 **************************************************************************/

	cout << "19. Наблюдатель (Observer):" << endl;
	{
		using namespace PatternObserver;

		Product *product = new Product(400);

		Wholesaler *wholesaler = new Wholesaler(product);
		Buyer *buyer = new Buyer(product);

		product->changePrice(320);
		product->changePrice(280);

		delete wholesaler;
		delete buyer;
		delete product;
	}
	cout << endl;

	/***************************************************************************
	 *
	 **************************************************************************/

	cout << "20. Состояние (State):" << endl;
	{
		using namespace PatternState;

		TrafficLight *trafficLight = new TrafficLight(new YellowState());

		trafficLight->nextState();
		trafficLight->nextState();
		trafficLight->previousState();
		trafficLight->previousState();
		trafficLight->previousState();

		delete trafficLight;
	}
	cout << endl;

	/***************************************************************************
	 *
	 **************************************************************************/

	cout << "21. Стратегия (Strategy):" << endl;
	{
		using namespace PatternStrategy;

		ResourceReader *resourceReader = new ResourceReader(new NewsSiteReader());

		string url = "https://www.engadget.com/";
		resourceReader->read(url);

		url = "https://linkedin.com";
		resourceReader->setStrategy(new SocialNetworkReader());
		resourceReader->read(url);

		url = "@news_channel_telegram";
		resourceReader->setStrategy(new TelegramChannelReader());
		resourceReader->read(url);

		delete resourceReader;
	}
	cout << endl;

	/***************************************************************************
	 *
	 **************************************************************************/

	cout << "22. Шаблонный метод (Template method):" << endl;
	{
		using namespace PatternTemplateMethod;

		Transmitter *analogTransmitter = new AnalogTransmitter();

		analogTransmitter->processStart();

		cout << endl;

		Transmitter *digitalTransmitter = new DigitalTransmitter();

		digitalTransmitter->processStart();

		delete analogTransmitter;
		delete digitalTransmitter;
	}
	cout << endl;

	/***************************************************************************
	 *
	 **************************************************************************/

	cout << "23. Посетитель (Visitor):" << endl;
	{
		using namespace PatternVisitor;

		Zoo zoo;
		Cinema cinema;
		Circus circus;

		Place *places[] = {&zoo, &cinema, &circus};

		for (auto place : places) {
			HolidayMaker vizitor;
			place->accept(vizitor);
			cout << vizitor.value << endl;
		}
	}
	cout << endl;
}