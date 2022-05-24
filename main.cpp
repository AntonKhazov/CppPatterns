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
	 * Фабричный метод (англ. Factory Method), или виртуальный конструктор
	 * (англ. Virtual Constructor) — порождающий шаблон проектирования,
	 * предоставляющий подклассам (дочерним классам) интерфейс для создания
	 * экземпляров некоторого класса. В момент создания наследники могут
	 * определить, какой класс создавать. Иными словами, данный шаблон делегирует
	 * создание объектов наследникам родительского класса. Это позволяет
	 * использовать в коде программы не конкретные классы, а манипулировать
	 * абстрактными объектами на более высоком уровне.
	 * https://en.wikipedia.org/wiki/Factory_method_pattern
	 **************************************************************************/

	cout << "1. Фабричный метод (Factory Method) [https://youtu.be/FjH1PtvrS9w]:" << endl;
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
	 * Абстрактная фабрика (англ. Abstract factory) — порождающий шаблон
	 * проектирования, предоставляет интерфейс для создания семейств
	 * взаимосвязанных или взаимозависимых объектов, не специфицируя их
	 * конкретных классов. Шаблон реализуется созданием абстрактного класса
	 * Factory, который представляет собой интерфейс для создания компонентов
	 * системы (например, для оконного интерфейса он может создавать окна и
	 * кнопки). Затем пишутся классы, реализующие этот интерфейс.
	 * https://en.wikipedia.org/wiki/Abstract_factory_pattern
	 **************************************************************************/

	cout << "2. Абстрактная фабрика (Abstract Factory) [https://youtu.be/vHjaqe3zx9Y]:" << endl;
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
	 * Строитель (англ. Builder) — порождающий шаблон проектирования
	 * предоставляет способ создания составного объекта.
	 * https://en.wikipedia.org/wiki/Builder_pattern
	 **************************************************************************/

	cout << "3. Строитель (Builder) [https://youtu.be/s95t2T_5dYI]:" << endl;
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
	 * Одиночка (англ. Singleton) — порождающий шаблон проектирования,
	 * гарантирующий, что в однопоточном приложении будет единственный экземпляр
	 * некоторого класса, и предоставляющий глобальную точку доступа к этому
	 * экземпляру.
	 * https://en.wikipedia.org/wiki/Singleton_pattern
	 **************************************************************************/

	cout << "4. Одиночка (Singleton) [https://youtu.be/0p_DPnkx_zw]:" << endl;
	{
		using namespace PatternSingleton;

		// DatabaseHelper *connection = new DatabaseHelper(); // Ошибка

		DatabaseHelper::getConnection()->insertData("123");

		cout << "Выборка данных из бд: " << DatabaseHelper::getConnection()->selectData() << endl;
	}
	cout << endl;

	/***************************************************************************
	 * Прототип, (англ. Prototype) — порождающий шаблон проектирования.
	 * Задаёт виды создаваемых объектов с помощью экземпляра-прототипа и создаёт
	 * новые объекты путём копирования этого прототипа. Он позволяет уйти от
	 * реализации и позволяет следовать принципу «программирование через
	 * интерфейсы».
	 * https://en.wikipedia.org/wiki/Prototype_pattern
	 **************************************************************************/

	cout << "5. Прототип (Prototype) [https://youtu.be/fKF-EZv5o88]:" << endl;
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
	 * Адаптер (англ. Adapter) — структурный шаблон проектирования,
	 * предназначенный для организации использования функций объекта,
	 * недоступного для модификации, через специально созданный интерфейс.
	 * Другими словами — это структурный паттерн проектирования, который
	 * позволяет объектам с несовместимыми интерфейсами работать вместе.
	 * https://en.wikipedia.org/wiki/Adapter_pattern
	 **************************************************************************/

	cout << "6. Адаптер (Adapter). Реализация на уровне объектов [https://youtu.be/IGy4WyoLgs0]:" << endl;
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

	cout << "7. Адаптер (Adapter). Реализация на уровне классов [https://youtu.be/w7pXSD4Gj2Q]:" << endl;
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
	 * Шаблон мост (англ. Bridge) — структурный шаблон проектирования,
	 * используемый в проектировании программного обеспечения чтобы «разделять
	 * абстракцию и реализацию так, чтобы они могли изменяться независимо».
	 * Шаблон мост использует инкапсуляцию, агрегирование и может использовать
	 * наследование для того, чтобы разделить ответственность между классами.
	 * https://en.wikipedia.org/wiki/Bridge_pattern
	 **************************************************************************/

	cout << "8. Мост (Bridge) [https://youtu.be/1OmwPFqlXBY]:" << endl;
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
	 * Компоновщик (англ. Composite pattern) — структурный шаблон
	 * проектирования, объединяющий объекты в древовидную структуру для
	 * представления иерархии от частного к целому. Компоновщик позволяет
	 * клиентам обращаться к отдельным объектам и к группам объектов одинаково.
	 * https://en.wikipedia.org/wiki/Composite_pattern
	 **************************************************************************/

	cout << "9. Компоновщик (Composite) [https://youtu.be/J0Ck4KTHpnI]:" << endl;
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
	 * Декоратор (англ. Decorator) — структурный шаблон проектирования,
	 * предназначенный для динамического подключения дополнительного поведения
	 * к объекту. Шаблон Декоратор предоставляет гибкую альтернативу практике
	 * создания подклассов с целью расширения функциональности.
	 * https://en.wikipedia.org/wiki/Decorator_pattern
	 **************************************************************************/

	cout << "10. Декоратор (Decorator) [https://youtu.be/z667MgTk_UA]:" << endl;
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
	 * Шаблон фасад (англ. Facade) — структурный шаблон проектирования,
	 * позволяющий скрыть сложность системы путём сведения всех возможных
	 * внешних вызовов к одному объекту, делегирующему их соответствующим
	 * объектам системы.
	 * https://en.wikipedia.org/wiki/Facade_pattern
	 **************************************************************************/

	cout << "11. Фасад (Facade) [https://youtu.be/9AOGu_kBlr0]:" << endl;
	{
		using namespace PatternFacade;

		MarketPlace marketPlace;
		marketPlace.productReceipt();

		cout << "--------------------------" << endl;

		marketPlace.productRelease();
	}
	cout << endl;

	/***************************************************************************
	 * Приспособленец (англ. flyweight, «легковесный (элемент)») — структурный
	 * шаблон проектирования, при котором объект, представляющий себя как
	 * уникальный экземпляр в разных местах программы, по факту не является
	 * таковым.
	 * Оптимизация работы с памятью путём предотвращения создания экземпляров
	 * элементов, имеющих общую сущность.
	 * https://en.wikipedia.org/wiki/Flyweight_pattern
	 **************************************************************************/

	cout << "12. Легковес (Flyweight) [https://youtu.be/maVvGxDdizE]:" << endl;
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
	 * Заместитель (англ. Proxy) — структурный шаблон проектирования,
	 * предоставляющий объект, который контролирует доступ к другому объекту,
	 * перехватывая все вызовы (выполняет функцию контейнера).
	 * https://en.wikipedia.org/wiki/Proxy_pattern
	 **************************************************************************/

	cout << "13. Заместитель (Proxy) [https://youtu.be/_erx1di25t0]:" << endl;
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
	 * Цепочка обязанностей (англ. Chain of responsibility) — поведенческий
	 * шаблон проектирования, предназначенный для организации в системе уровней
	 * ответственности.
	 * Шаблон рекомендован для использования в условиях:
	 * - в разрабатываемой системе имеется группа объектов, которые могут
	 *   обрабатывать сообщения определенного типа;
	 * - все сообщения должны быть обработаны хотя бы одним объектом системы;
	 * - сообщения в системе обрабатываются по схеме «обработай сам либо перешли
	 *   другому», то есть одни сообщения обрабатываются на том уровне, где они
	 *   получены, а другие пересылаются объектам иного уровня.
	 * https://en.wikipedia.org/wiki/Chain-of-responsibility_pattern
	 **************************************************************************/

	cout << "14. Цепочка обязанностей (Chain of responsibility) [https://youtu.be/wUF2TwSIoPA]:" << endl;
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
	 * Команда (англ. Command) — поведенческий шаблон проектирования,
	 * используемый при объектно-ориентированном программировании,
	 * представляющий действие. Объект команды заключает в себе само действие и
	 * его параметры.
	 * Создание структуры, в которой класс-отправитель и класс-получатель не
	 * зависят друг от друга напрямую. Организация обратного вызова к классу,
	 * который включает в себя класс-отправитель.
	 * https://en.wikipedia.org/wiki/Command_pattern
	 **************************************************************************/

	cout << "15. Команда (Command) [https://youtu.be/xmUzK9l4K7Y]:" << endl;
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
	 * Iterator — поведенческий шаблон проектирования. Представляет собой
	 * объект, позволяющий получить последовательный доступ к элементам
	 * объекта-агрегата без использования описаний каждого из агрегированных
	 * объектов.
	 * Например, такие элементы как дерево, связанный список, хеш-таблица и
	 * массив могут быть пролистаны (и модифицированы) с помощью объекта
	 * Итератор.
	 * https://en.wikipedia.org/wiki/Iterator_pattern
	 **************************************************************************/

	cout << "16. Итератор (Iterator) [https://youtu.be/bI7xXiMqpes]:" << endl;
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
	 * Посредник (англ. Mediator) — поведенческий шаблон проектирования,
	 * обеспечивающий взаимодействие множества объектов, формируя при этом
	 * слабое зацепление и избавляя объекты от необходимости явно ссылаться друг
	 * на друга.
	 * https://en.wikipedia.org/wiki/Mediator_pattern
	 **************************************************************************/

	cout << "17. Посредник (Mediator) [https://youtu.be/UCxqTKhKUWE]:" << endl;
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
	 * Хранитель (англ. Memento) — поведенческий шаблон проектирования,
	 * позволяющий, не нарушая инкапсуляцию, зафиксировать и сохранить
	 * внутреннее состояние объекта так, чтобы позднее восстановить его в это
	 * состояние.
	 * https://en.wikipedia.org/wiki/Memento_pattern
	 **************************************************************************/

	cout << "18. Снимок (Memento) [https://youtu.be/E7BOUtqbWuE]:" << endl;
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
	 * Наблюдатель (англ. Observer) — поведенческий шаблон проектирования.
	 * Также известен как «подчинённые» (англ. Dependents). Реализует у класса
	 * механизм, который позволяет объекту этого класса получать оповещения об
	 * изменении состояния других объектов и тем самым наблюдать за ними.
	 * Классы, на события которых другие классы подписываются, называются
	 * субъектами (Subjects), а подписывающиеся классы называются наблюдателями
	 * (англ. Observers).
	 * https://en.wikipedia.org/wiki/Observer_pattern
	 **************************************************************************/

	cout << "19. Наблюдатель (Observer) [https://youtu.be/zWznlNFmczk]:" << endl;
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
	 * Состояние (англ. State) — поведенческий шаблон проектирования.
	 * Используется в тех случаях, когда во время выполнения программы объект
	 * должен менять своё поведение в зависимости от своего состояния.
	 * https://en.wikipedia.org/wiki/State_pattern
	 **************************************************************************/

	cout << "20. Состояние (State) [https://youtu.be/IyC0qDzkqV0]:" << endl;
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
	 * Стратегия (англ. Strategy) — поведенческий шаблон проектирования,
	 * предназначенный для определения семейства алгоритмов, инкапсуляции
	 * каждого из них и обеспечения их взаимозаменяемости. Это позволяет
	 * выбирать алгоритм путём определения соответствующего класса. Шаблон
	 * Strategy позволяет менять выбранный алгоритм независимо от
	 * объектов-клиентов, которые его используют.
	 * https://en.wikipedia.org/wiki/Strategy_pattern
	 **************************************************************************/

	cout << "21. Стратегия (Strategy) [https://youtu.be/o99zwjc9ujE]:" << endl;
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
	 * Шаблонный метод (англ. Template method) — поведенческий шаблон
	 * проектирования, определяющий основу алгоритма и позволяющий наследникам
	 * переопределять некоторые шаги алгоритма, не изменяя его структуру
	 * в целом.
	 * https://en.wikipedia.org/wiki/Template_method_pattern
	 **************************************************************************/

	cout << "22. Шаблонный метод (Template method) [https://youtu.be/ADMeO9UOewU]:" << endl;
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
	 * Посетитель (англ. visitor) — поведенческий шаблон проектирования,
	 * описывающий операцию, которая выполняется над объектами других классов.
	 * При изменении visitor нет необходимости изменять обслуживаемые классы.
	 * Шаблон демонстрирует классический приём восстановления информации о
	 * потерянных типах, не прибегая к понижающему приведению типов при помощи
	 * двойной диспетчеризации.
	 * https://en.wikipedia.org/wiki/Visitor_pattern
	 **************************************************************************/

	cout << "23. Посетитель (Visitor) [https://youtu.be/ftlsO_rNZ54]:" << endl;
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