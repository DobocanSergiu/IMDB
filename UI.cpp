#include "UI.h"; 



void Menu::getMenu()
{
	cout << "1.AddMovie\n2.AddShow\n3.Remove\n4.Edit\n5.ShowAll\n6.Undo\n7.Redo\n0.End\n";

}


void Menu::AddMovie()
{
	int mediatype = 1;
	int id;
	string title;
	string director;
	int runtime;
	float budget;
	int release_year;
	int rating;
	int genre;
	cout << "ID: ";
	cin >> id;
	if (true == mycontroller.CFindID(id))
	{
		cout << "Invalid Id\n";
		return;

	}
	cout << "Title: ";
	cin >> title;
	cout << "Director: ";
	cin >> director;
	cout << "Runtime: ";
	cin >> runtime;
	cout << "Budget: ";
	cin >> budget;
	cout << "Release Year: ";
	cin >> release_year;
	cout << "Rating: 0.G 1.PG 2.PG_13 3.R 4.NC_17\n";
	cin >> rating;
	try 
	{
		if (!(rating >= 0 && rating <= 4))
		{
			throw(false);
		}
	}
	catch(bool val)
	{
		if (val == false)
		{
			cout << "Invalid Rating\n";
			return;
		}
	}
	cout << "Genre: 0.Action 1.Comedy 2.Horror 3.Adventure\n";
	cin >> genre;
	try
	{
		if (!(genre >= 0 && genre <= 3))
		{
			throw(false);
		}
	}
	catch (bool val)
	{
		if (val == false)
		{
			cout << "Invalid Rating\n";
			return;
		}
	}

	mycontroller.CAddMovie(mediatype, id, title, director, runtime, budget, release_year, (Rating)rating, genre);

	
	
}


void Menu::AddShow()
{
	int mediatype = 1;
	int id;
	string title;
	string director;
	int runtime;
	float budget;
	int release_year;
	int rating;
	int type;
	cout << "ID: ";
	cin >> id;
	if (true == mycontroller.CFindID(id))
	{
		cout << "Invalid Id\n";
		return;

	}
	cout << "Title: ";
	cin >> title;
	cout << "Director: ";
	cin >> director;
	cout << "Runtime: ";
	cin >> runtime;
	cout << "Budget: ";
	cin >> budget;
	cout << "Release Year: ";
	cin >> release_year;
	cout << "Rating: 0.G 1.PG 2.PG_13 3.R 4.NC_17\n";
	cin >> rating;
	try
	{
		if (!(rating >= 0 && rating <= 4))
		{
			throw(false);
		}
	}
	catch (bool val)
	{
		if (val == false)
		{
			cout << "Invalid Rating\n";
			return;
		}
	}
	cout << "Type: 0.Fiction 1.Non-Fiction\n";
	cin >> type;
	try
	{
		if (!(type >= 0 && type <= 1))
		{
			throw(false);
		}
	}
	catch (bool val)
	{
		if (val == false)
		{
			cout << "Invalid Rating\n";
			return;
		}
	}

	mycontroller.CAddShow(mediatype, id, title, director, runtime, budget, release_year, (Rating)rating, type);

}

void Menu::Remove()
{
	int id;
	cout << "ID:";
	cin >> id;
	if (mycontroller.CFindID(id) == true)
	{
		mycontroller.CRemove(id);
	}
	else
	{
		cout << "Id not found";
	}
}

void Menu::ShowAll()
{
	this->mycontroller.CShowAll();
}

void Menu::Import()
{
	this->mycontroller.CImport();
}

void Menu::Export()
{
	this->mycontroller.CExport();
}

void Menu::Edit()
{

	int mediatype = 1;
	int id;
	string title;
	string director;
	int runtime;
	float budget;
	int release_year;
	int rating;
	int other;
	cout << "ID: ";
	cin >> id;
	if (false == mycontroller.CFindID(id))
	{
		cout << "Invalid Id\n";
		return;

	}
	cout << "Title: ";
	cin >> title;
	cout << "Director: ";
	cin >> director;
	cout << "Runtime: ";
	cin >> runtime;
	cout << "Budget: ";
	cin >> budget;
	cout << "Release Year: ";
	cin >> release_year;
	cout << "Rating: 0.G 1.PG 2.PG_13 3.R 4.NC_17\n";
	cin >> rating;
	try
	{
		if (!(rating >= 0 && rating <= 4))
		{
			throw(false);
		}
	}
	catch (bool val)
	{
		if (val == false)
		{
			cout << "Invalid Rating\n";
			return;
		}
	}
	cout <<"Other";
	cin >> other;
	mycontroller.CEdit(id, title, director, runtime, budget, release_year, (Rating)rating, other);

}

void Menu::Undo()
{
	mycontroller.Undo();
}

void Menu::Redo()
{
	mycontroller.Redo();
}

