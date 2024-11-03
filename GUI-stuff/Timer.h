#pragma once
class Timer
{
public:
	Timer(double _duration);
	virtual ~Timer();
	virtual void on_tick(); //for on tick functionality of derived classes
private:
	double m_duration; //iterates per tick
	static void tick(void* _userdata);
};

