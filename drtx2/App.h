#pragma once
#include "Window.h"
#include "BaseTimer.h"


class App
{
public:
	App();

	int Go();
private:
	void DoFrame();
private:
	Window wnd;
	BaseTimer timer;
};

