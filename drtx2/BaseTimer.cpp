#include "BaseTimer.h"

BaseTimer::BaseTimer()
{
	last = std::chrono::steady_clock::now();
}

float BaseTimer::Mark()
{
	const auto old = last;
	last = std::chrono::steady_clock::now();
	const std::chrono::duration<float> frameTime = last - old;
	return frameTime.count();
}

float BaseTimer::Peek() const
{
	return std::chrono::duration<float>(std::chrono::steady_clock::now() - last).count();
}
