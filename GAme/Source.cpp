#include "AppWindow.h"

int main()	
{
	AppWindow App;
	App.init();
	//added control check for intialization
	if (App.init())
	{
		while (App.isRun())
		{
			App.broadcast();
		}
	}
	return 0;
}