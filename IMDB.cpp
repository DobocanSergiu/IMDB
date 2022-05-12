#include <iostream>
#include"UI.h"
#include"tests.h"
using namespace std;

int main()
{
	TESTS::runtests();
	int choice;
	Menu mymenu;
	mymenu.Import();
	choice = -1;
	while (choice != 0)
	{
		mymenu.getMenu();
		cin >> choice;
		if (choice == 1)
		{
			mymenu.AddMovie();
		}
		else if (choice == 2)
		{
			mymenu.AddShow();
		}
		else if (choice == 3)
		{
			mymenu.Remove();
		}
		else if (choice == 4)
		{
			mymenu.Edit();
		}
		else if (choice == 5)
		{
			mymenu.ShowAll();
		}
		else if (choice == 6)
		{
			mymenu.Undo();

		}
		else if (choice == 7)
		{
			mymenu.Redo();
		}
		
	}
	mymenu.Export();
	return 0;

}
