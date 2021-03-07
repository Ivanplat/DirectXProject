#include <Windows.h>
#include "WindowsMessageMap.h"
#include <sstream>
#include "Window.h"

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
        Window wnd(800, 300, "Ys");
        //Window wnd2(800, 300, "Ys");

        MSG msg = {};
        BOOL gResult;
        while (gResult = msg.message != WM_QUIT)
        {
            if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
            {
                TranslateMessage(&msg);
                DispatchMessage(&msg);
               
                static int i = 0;
                while (!wnd.mouse.isEmpty()) {
                    const auto e = wnd.mouse.Read();
                    switch (e.GetType()) {
                   
                    case Mouse::Event::Type::WheelUp:
                    {
                        i++;
                        std::ostringstream oss;
                        oss << "Up: " << i;
                        wnd.SetTitle(oss.str());
                    }break; case Mouse::Event::Type::WheelDown:
                    {
                        i--;
                        std::ostringstream oss;
                        oss << "Down: " << i;
                        wnd.SetTitle(oss.str());
                    }break;
                   }
                }






            }
        }


        if (gResult == -1) {
            return -1;
        }
        else {
            return msg.wParam;
        }
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
