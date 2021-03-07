#include "App.h"
#include <sstream>
#include<iomanip>


App::App() : wnd(800, 600, "Adsda"){}


int App::Go()
{
	while (true) {
		if (const auto ecode = Window::ProcessMessages()) {
			return *ecode;
		}
		DoFrame();
	}
}

void App::DoFrame()
{
	const float t = timer.Peek();
	std::ostringstream oss;
	oss << "Time elapsed: " << std::setprecision(1) << std::fixed << t;
	wnd.SetTitle(oss.str());

}
