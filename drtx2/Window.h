#pragma once
#include "DIHeader.h"
#include "ExceptionHandler.h"


class Window
{
public:

	class Exception : public ExceptionHandler {
	public:
		Exception(int line, const char* file, HRESULT hr) noexcept;
		virtual const LPCSTR lwhat() const noexcept;
		const char* what() const noexcept override;
		virtual const LPCSTR GetType() const noexcept override;
		static std::string TranslateErrorCode(HRESULT hr);
		HRESULT GetErrorCode() const noexcept;
		std::string GetErrorString() const noexcept;
	private:
			HRESULT hr;
	};



private:

	class WindowClass
	{
	public:
		static LPCSTR GetName() noexcept;
		static HINSTANCE GetInstance() noexcept;
	private:
		WindowClass() noexcept;
		~WindowClass();
		WindowClass(const WindowClass&) = delete;
		WindowClass& operator=(const WindowClass&) = delete;

		static constexpr const LPCSTR wndClassName = "EventGraphDev DirectX3D Engine Window";
		static WindowClass wndClass;
		HINSTANCE hInst;
	};
public:
	Window(int width, int height, const char* name);
	~Window();
	Window(const Window&) = delete;
	Window& operator=(const Window&) = delete;
private:
	static LRESULT CALLBACK HandleMsgSetup(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
	static LRESULT CALLBACK HandleMsgThunk(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
	LRESULT HandleMsg(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) noexcept;
private:
	int Width;
	int Height;
	HWND hWnd;
};

#define CHWND_EXCEPT(hr) Window::Exception(__LINE__, __FILE__, hr)
#define CHWND_LAST_EXCEPT() Window::Exception(__LINE__, __FILE__,GetLastError())