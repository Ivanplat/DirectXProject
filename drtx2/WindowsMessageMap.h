#pragma once
#include <Windows.h>
#include <unordered_map>


class WindowsMessageMap
{
public:
	WindowsMessageMap();

	std::string operator()(DWORD msg, LPARAM lParam, WPARAM wParam) const;
private:
	std::unordered_map<DWORD, std::string> map;

};

