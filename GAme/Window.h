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
	bool isRun(); ////check the window is currently running
	// event methods
	virtual void onCreate()=0;
	virtual void onUpdate() = 0;
	virtual void onDestroy() = 0;

	~Window();
protected: //modifier specifies that the member can only be
	//accessed within its own & instance
	// they can be accessed in inherited classes
	// relaxed than private
	HWND m_hwnd;
	bool isrunning;
	//  private modifier specifies that  
	//the member can only be accessed in its own class. 
};

