#pragma once
#include <Windows.h>


class Window
// this the low level window
{	
public:
	Window();
	bool init();
	bool release();
	bool broadcast(); // peak the event messages from os
					  //and dispatch them into window procedure
	// event methods
	virtual void onCreate()=0;
	virtual void onUpdate() = 0;
	virtual void onDestroy() = 0;

	~Window();
private:
	HWND m_hwnd;
};

