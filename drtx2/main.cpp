#include <Windows.h>
#include "WindowsMessageMap.h"
#include <sstream>
#include "App.h"

/*                                                 DiretX12 project                                                    */
/*  Author: Ivan Platonov                                                                                              */
/*  Author's VK: https://vk.com/id445781020                                                                            */


LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {


    static WindowsMessageMap mm;
    std::string a = mm(msg, lParam, wParam).c_str();
    OutputDebugString(a.c_str());


    switch(msg){
    case WM_CLOSE: PostQuitMessage(69); break;
    case WM_KEYDOWN: {
        if (wParam == 'F') {
            SetWindowText(hWnd, "NewText");
        }break;
    }
    case WM_CHAR:
    {
        static std::string title;
        title.push_back(char(wParam));
        SetWindowText(hWnd, title.c_str());;
    }
    case WM_LBUTTONDOWN:
    {
        POINTS pt = MAKEPOINTS(lParam);
        std::ostringstream oss;
        oss << "(" << pt.x << "," << pt.y << ")";
        std::string s = oss.str().c_str();
        SetWindowText(hWnd,s.c_str());
    }
    }

    return DefWindowProc(hWnd, msg, wParam, lParam);
}


int CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR, int nCmdShow){

    try {
        return App{}.Go();
    }
    catch (const ExceptionHandler& e) {
        MessageBox(nullptr, e.lwhat(), e.GetType(), MB_OK | MB_ICONEXCLAMATION );
    }
    catch (const std::exception& e) {
        std::string a = e.what();
        MessageBox(nullptr, a.c_str(), "Standart Exception", MB_OK | MB_ICONEXCLAMATION);
    }
    catch (...) {

        MessageBox(nullptr, "No details avaliable", "Standart Exception", MB_OK | MB_ICONEXCLAMATION);
    }
}
