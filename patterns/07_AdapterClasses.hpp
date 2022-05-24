#ifndef _ADAPTER_CLASSES_
#define _ADAPTER_CLASSES_

#include <iostream>

using namespace std;

namespace PatternAdapterClasses {
	class Scales {
	public:
		virtual ~Scales()
		{
		}

		virtual float *getWeight() = 0;

		virtual void adjust() = 0;
	};

	class RussianScales : public Scales {
		float *currentWeight_;

	public:
		RussianScales(float *cw) : currentWeight_(cw)
		{
		}

		float *getWeight() override
		{
			return currentWeight_;
		}

		void adjust() override
		{
			cout << "Регулировка российских весов" << endl;
		}
	};

	class BritishScales {
		float *currentWeight_;

	public:
		BritishScales(float *cw) : currentWeight_(cw)
		{
		}

		float *getWeight()
		{
			return currentWeight_;
		}

	protected:
		void adjust()
		{
			cout << "Регулировка британских весов";
		}
	};

	class AdapterForBritishScales : public Scales, private BritishScales {
	private:
		float *cw_;

	public:
		AdapterForBritishScales(float *cw) : BritishScales(cw)
		{
		}

		float *getWeight() override
		{
			cw_ = BritishScales::getWeight();
			*cw_ = *cw_ * 0.453;
			return cw_;
		}

		void adjust() override
		{
			BritishScales::adjust();
			cout << " в методе регулировки adjust() адаптера" << endl;
		}
	};
}
#endif // _ADAPTER_CLASSES_