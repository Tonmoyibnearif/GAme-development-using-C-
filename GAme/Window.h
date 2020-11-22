#pragma once
#include <Windows.h>


class Window
{public:
	Window();
	bool init();
	bool release();
	bool broadcast(); // peak the event messages from os
					  //and dispatch them into window procedure
	// event methods
	virtual void onCreate();
	virtual void onUpdate();
	virtual void onDestroy();

	~Window();
private:
	HWND m_hwnd;
};

