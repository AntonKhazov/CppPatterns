#ifndef _STATE_
#define _STATE_

#include <iostream>
#include <string>

using namespace std;

namespace PatternState {
	class TrafficLight;

	class State {
	protected:
		TrafficLight *trafficLight_;

	public:
		virtual ~State()
		{
		}

		void setTrafficLight(TrafficLight *tr)
		{
			trafficLight_ = tr;
		}

		virtual void nextState() = 0;

		virtual void previousState() = 0;
	};

	class TrafficLight {
	private:
		State *state_;

	public:
		TrafficLight(State *st) : state_(nullptr)
		{
			setState(st);
		}

		void setState(State *st)
		{
			if (state_)
				delete state_;

			state_ = st;
			state_->setTrafficLight(this);
		}

		void nextState()
		{
			state_->nextState();
		}

		void previousState()
		{
			state_->previousState();
		}
	};

	class GreenState : public State {
	public:
		void nextState() override;

		void previousState() override
		{
			cout << "Зелёный цвет" << endl;
		}
	};

	class YellowState : public State {
	public:
		void nextState() override;

		void previousState() override
		{
			cout << "Из жёлтого в зелёный цвет" << endl;
			trafficLight_->setState(new GreenState());
		}
	};

	void GreenState::nextState()
	{
		cout << "Из зелёного в жёлтый цвет" << endl;
		trafficLight_->setState(new YellowState());
	}

	class RedState : public State {
	public:
		void nextState() override
		{
			cout << "Красный цвет" << endl;
		}

		void previousState() override
		{
			cout << "Из красного в жёлтый цвет" << endl;
			trafficLight_->setState(new YellowState());
		}
	};

	void YellowState::nextState()
	{
		cout << "Из жёлтого в красный цвет" << endl;
		trafficLight_->setState(new RedState());
	}
}

#endif // _STATE_