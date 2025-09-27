#include "GameApplication.h"
#include <cstdlib>  
#include <clocale> 
#include <ctime>
int main()
{
	srand(static_cast<unsigned int>(time(0)));
	setlocale(0,"Ru");
	GameApplication app;
	app.Run();
	return 0;
}