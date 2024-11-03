#include "Timer.h"
#include <FL/Fl.H>

Timer::Timer(double _duration) : m_duration(_duration)
{
	Fl::add_timeout(m_duration, tick, this); // adds timer
}

Timer::~Timer()
{
	Fl::remove_timeout(tick, this); // Clean up
}

// Default empty for implementation upon inheritence.
void Timer::on_tick(){}

void Timer::tick(void* _userdata)
{
	Timer* timer = static_cast<Timer*>(_userdata);
	timer->on_tick();
	Fl::repeat_timeout(timer->m_duration, tick, _userdata);
}