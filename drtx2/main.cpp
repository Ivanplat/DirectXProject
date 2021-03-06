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
    std::wstring b(a.begin(), a.end());
    LPCWSTR result = b.c_str();
    OutputDebugString(result);


    switch(msg){
    case WM_CLOSE: PostQuitMessage(69); break;
    case WM_KEYDOWN: {
        if (wParam == 'F') {
            SetWindowText(hWnd, L"NewText");
        }break;
    }
    case WM_CHAR:
    {
        static std::string title;
        title.push_back(char(wParam));
        std::wstring b(title.begin(), title.end());
        LPCWSTR a = b.c_str();
        SetWindowText(hWnd, a);;
    }
    case WM_LBUTTONDOWN:
    {
        POINTS pt = MAKEPOINTS(lParam);
        std::ostringstream oss;
        oss << "(" << pt.x << "," << pt.y << ")";
        std::string s = oss.str().c_str();
        std::wstring a(s.begin(), s.end());
        LPCWSTR b = a.c_str();
        SetWindowText(hWnd,b);
    }
    }

    return DefWindowProc(hWnd, msg, wParam, lParam);
}


int CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR, int nCmdShow){

    Window wnd(800, 300, "Ys");
    Window wnd2(800, 300, "Ys");

    MSG msg = {};
    BOOL gResult;
    while (gResult = msg.message != WM_QUIT)
    {
        if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }


    if (gResult == -1) {
        return -1;
    }
    else {
        return msg.wParam;
    }

}
