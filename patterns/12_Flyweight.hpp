#ifndef _FLYWEIGHT_
#define _FLYWEIGHT_

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

namespace PatternFlyweight {
	struct Shared {
		string company;
		string position;

		Shared(const string &comp, const string &pos)
			: company(comp), position(pos)
		{
		}
	};

	struct Unique {
		string name;
		string passport;

		Unique(const string &nm, const string &passp)
			: name(nm), passport(passp)
		{
		}
	};

	class Flyweight {
		Shared *shared_;

	public:
		Flyweight(const Shared *shared) : shared_(new Shared(*shared))
		{
		}

		Flyweight(const Flyweight &other) : shared_(new Shared(*other.shared_))
		{
		}

		~Flyweight()
		{
			delete shared_;
		}

		void Process(const Unique &unique) const
		{
			cout << "Отображаем новые данные: общее - " << shared_->company << "_" << shared_->position;
			cout << " и уникальное - " << unique.name << "_" << unique.passport << ")." << endl;
		}
	};

	class FlyweightFactory {
		unordered_map<string, Flyweight> flyweights_;

		auto GetKey(const Shared &shared) const
		{
			return shared.company + "_" + shared.position;
		}

	public:
		FlyweightFactory(initializer_list<Shared> shareds)
		{
			for (const auto &shared : shareds) {
				flyweights_.insert(make_pair(GetKey(shared), Flyweight(&shared)));
			}
		}

		auto GetFlyweight(const Shared &shared)
		{
			auto key = GetKey(shared);

			if (flyweights_.find(key) == flyweights_.end()) {
				cout << "Фабрика легковесов: Общий объект по ключу " << key << " не найден. Создаём новый." << endl;

				flyweights_.insert(make_pair(key, Flyweight(&shared)));
			}
			else
				cout << "Фабрика легковесов: Извлекаем данные из имеющихся записей по ключу " << key << "." << endl;

			return flyweights_.at(key);
		}

		void ListFlyweights() const
		{
			cout << endl
				 << "Фабрика легковесов: Всего " << flyweights_.size() << " записей:" << endl;

			for (const auto &pair : flyweights_) {
				cout << pair.first << endl;
			}
		}
	};

	void AddSpecialistDatabase(FlyweightFactory &ff,
							   const string &company,
							   const string &position,
							   const string &name,
							   const string &passport)
	{
		cout << endl;
		const auto &flyweight = ff.GetFlyweight({company, position});
		flyweight.Process({name, passport});
	}
}

#endif // _FLYWEIGHT_