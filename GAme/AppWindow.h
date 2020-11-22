#pragma once
#include "Window.h"
// this is the high level window
//as our base class is ready so
// now we can inherite from the base class window
class AppWindow : public Window 
{ public:
	AppWindow();
	~AppWindow();

	// Inherited via Window
	virtual void onCreate() override;
	virtual void onUpdate() override;
	virtual void onDestroy() override;
};

