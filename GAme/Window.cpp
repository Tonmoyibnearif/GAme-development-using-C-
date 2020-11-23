#include "Window.h"
Window* window=nullptr; // global pointer

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM  wparam, LPARAM lparam)
{
	switch (msg)
	{
	case WM_PAINT:
	{
		break; }

	case WM_CREATE:
	{ // create the window
		window->onCreate();// event method of high level window
		//into low level window
		break; }
	case WM_DESTROY://destroy the window

	{ 
		window->onDestroy();// event method of high level window
		//into low level window --Asbtraction
		::PostQuitMessage(0);
		break;
	}

	default:
		return::DefWindowProc(hwnd, msg, wparam, lparam);
	}
	return NULL;
};
Window::Window()
{
}

bool Window::init()
{
	WNDCLASSEX wc; // all the properties are the visual appreance of the window.
	wc.cbClsExtra = NULL;
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.cbWndExtra = NULL;
	wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hIcon= LoadIcon(NULL, IDI_APPLICATION);
	wc.hIconSm= LoadIcon(NULL, IDI_APPLICATION);
	wc.hInstance = NULL;
	wc.lpszClassName = L"MyWindowClass"; //L requires 16-bits of 
	//storage rather than 8-bits
	wc.lpszMenuName =L"" ;
	wc.style=NULL;
	wc.lpfnWndProc = &WndProc; // handle the creation and destroy of the window

	// we also need to do some control flow,
	if(!::RegisterClassEx(&wc))
		return false; // for visual appreance  of window
	                  // take pointer of WNDCLASSEX
	
					  
	// setting the window pointer with our window
	// we have to do it before the create method.
	
	/*if (!window) // sucess if window is false
	{
		window = this;
	}*/
	// now we are creating the window
	m_hwnd=::CreateWindowEx(WS_EX_OVERLAPPEDWINDOW, L"Windowclass",L"DirectxAPP"
		, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 1024, 768, NULL, NULL,NULL,this);
	
	//control flow
	// if creation fials returns zero
	if (!m_hwnd)
		return false;
	//Show the window
	::ShowWindow(m_hwnd, SW_SHOW);
	//upadte the redraw the content of the window
	::UpdateWindow(m_hwnd);
	
	//seting the flag for runnng window
	isrunning = true;
	return true;
}

bool Window::release()

{
	if(!::DestroyWindow(m_hwnd))
		return false;
	return true;
}

bool Window::broadcast() // peak the event messages from os
					  //and dispatch them into window procedure
{
	MSG msg;// msgs from os
	while (::PeekMessage(&msg, NULL, 0, 0, PM_REMOVE) > 0)// get the msgs from os
		//get the those msgs from que of msgs
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	} // so the window process can process it.

	// as the App will be closed after each msg processing
	// so here we have to call the on update method
	window->onUpdate(); // this event method is called 
	Sleep(1); 	//				// to render all the graphics scene
	// it is called, to suspend its execution temporarily for a period 
	// of time in seconds specified by the function parameter
	return true;
}

bool Window::isRun() //only returning the Flag
{
	return isrunning;
}

void Window::onCreate()
{
}

void Window::onUpdate()
{
}

void Window::onDestroy()
{	
	isrunning = false;
}

Window::~Window()
{
}
