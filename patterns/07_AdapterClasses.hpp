#ifndef _ADAPTER_CLASSES_
#define _ADAPTER_CLASSES_

#include <iostream>

using namespace std;

class Scales {
public:
	virtual ~Scales() {}

	virtual float *getWeight() = 0;

	virtual void adjust() = 0;
};

class RussianScales : public Scales {
	float *currentWeight;

public:
	RussianScales(float *cw) : currentWeight(cw)
	{
	}

	~RussianScales() override
	{
		delete currentWeight;
	}

	float *getWeight() override
	{
		return currentWeight;
	}

	void adjust() override
	{
		cout << "Регулировка российских весов" << endl;
	}
};

class BritishScales {
	float *currentWeight;

public:
	BritishScales(float *cw) : currentWeight(cw)
	{
	}

	~BritishScales()
	{
		delete currentWeight;
	}

	float *getWeight()
	{
		return currentWeight;
	}

protected:
	void adjust()
	{
		cout << "Регулировка британских весов";
	}
};

class AdapterForBritishScales : public Scales, private BritishScales {
private:
	float *cw;

public:
	AdapterForBritishScales(float *cw) : BritishScales(cw)
	{
	}

	~AdapterForBritishScales()
	{
		delete cw;
	}

	float *getWeight() override
	{
		cw = BritishScales::getWeight();
		*cw = *cw * 0.453;
		return cw;
	}

	void adjust() override
	{
		BritishScales::adjust();
		cout << " в методе регулировки adjust() адаптера" << endl;
	}
};

#endif // _ADAPTER_CLASSES_