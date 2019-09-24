#include "organizer.h" // organizes the main dialogue and locations of the game

int main()
{
	int loader; // if there is no file to load
	bool bugger = true; // for debugging
	hideCursor();
	system("cls");
	menur:
	printPattern(TESTER,80,10);
	printString("Instruction Manual included in Stone Crawler Manual.txt file",0,17);
	switch(options("Developed by Kobe Runnels","New Game - Start your Existence","Load Game - Return to the World","Exit","",3,0,10))
	{
		case 1:
		inJail = false;
		setUp();
		bookKeeper();
		break;
		case 2:
		loader = loadFile();	
		if(loader == 1)
		{
			goto menur;	
		}
		system("cls");
		getFortune();
		bookKeeper();
		break;
	}
}
