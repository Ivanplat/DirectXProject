#pragma once
#include <chrono>


class BaseTimer
{
public:
	BaseTimer();
	float Mark();
	float Peek() const;
private:
	std::chrono::steady_clock::time_point last;
};

