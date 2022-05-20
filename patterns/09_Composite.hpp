#ifndef _COMPOSITE_
#define _COMPOSITE_

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

namespace PatternComposite {
	class Item {
	protected:
		string itemName;
		string ownerName;

	public:
		Item(string name) : itemName(name)
		{
		}

		void setOwner(string o)
		{
			ownerName = o;
		}

		virtual void add(Item *subItem) = 0;

		virtual void remove(Item *subItem) = 0;

		virtual void display() = 0;
	};

	class ClickableItem : public Item {
	public:
		ClickableItem(string name) : Item(name)
		{
		}

		void add(Item *subItem) override
		{
			throw exception();
		}

		void remove(Item *subItem) override
		{
			throw exception();
		}

		void display() override
		{
			cout << itemName << endl;
		}
	};

	class DropDownItem : public Item {
	private:
		vector<Item *> children;

	public:
		DropDownItem(string name) : Item(name)
		{
		}

		void add(Item *subItem) override
		{
			subItem->setOwner(this->itemName);
			children.push_back(subItem);
		}

		void remove(Item *subItem) override
		{
			std::remove(children.begin(), children.end(), subItem);
		}

		void display() override
		{
			for (const auto &child : children) {
				if (ownerName != "")
					cout << ownerName << itemName;
				child->display();
			}
		}
	};
}

#endif // _COMPOSITE_