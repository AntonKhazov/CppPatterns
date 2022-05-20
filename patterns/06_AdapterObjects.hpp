#ifndef _ADAPTER_OBJECTS_
#define _ADAPTER_OBJECTS_

#include <iostream>

using namespace std;

class Scales {
public:
	virtual float *getWeight() = 0;

	virtual ~Scales()
	{
	}
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
};

class AdapterForBritishScales : public Scales {
	BritishScales *britishScales;
	float *cw;

public:
	AdapterForBritishScales(BritishScales *bs) : britishScales(bs), cw(0)
	{
	}

	~AdapterForBritishScales()
	{
		delete britishScales;
		delete cw;
	}

	float *getWeight() override
	{
		cw = britishScales->getWeight();
		*cw = *cw * 0.453;

		return cw;
	}
};

#endif // _ADAPTER_OBJECTS_