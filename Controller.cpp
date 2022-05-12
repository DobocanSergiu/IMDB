#include"Controller.h"

void Controller::CAddMovie(int MediaType, int id, string title, string director, int runtime, float budget, int release_year, Rating rating, int genre)
{
	/**
	 * CAddMovie-Adds movie to repo.
	 * 
	 * \param MediaType
	 * \param id
	 * \param title
	 * \param director
	 * \param runtime
	 * \param budget
	 * \param release_year
	 * \param rating
	 * \param genre
	 */
	//Movie cmovie(MediaType, id, title, director, runtime, budget, release_year, rating, genre);
	//myrepo.addMovie(&cmovie);
	if (this->k != this->moves.size()-1)
	{
		int K = this->k+1;
		this->entries.erase(this->entries.begin() + K, this->entries.end());
		this->moves.erase(this->moves.begin() + K, this->moves.end());
	}


	Movie* p = new Movie(MediaType, id, title, director, runtime, budget, release_year, rating, (MovieGenre)genre);
	myrepo.addMovie(p);
	k++;
	this->moves.push_back("ADD_MOVIE");
	Movie* pp = new Movie(MediaType, id, title, director, runtime, budget, release_year, rating, (MovieGenre)genre);
	this->entries.push_back(pp);
	/*
	for (int i = 0; i < this->entries.size() ; i++)
	{
		cout << this->entries[i]->toStringg() << " " << this->moves[i] << '\n';
	}
	cout << "================" << '\n';
	*/


	

}

void Controller::CAddShow(int MediaType, int id, string title, string director, int runtime, float budget, int release_year, Rating rating, int showtype)
{
	/**
	 * CAddShow-Adds show to repo.
	 * 
	 * \param MediaType
	 * \param id
	 * \param title
	 * \param director
	 * \param runtime
	 * \param budget
	 * \param release_year
	 * \param rating
	 * \param showtype
	 */
	//Show cshow(MediaType, id, title, director, runtime, budget, release_year, rating, showtype);
	//myrepo.AddShow(&cshow);
	if (this->k !=this->moves.size()-1)
	{
		int K = this->k+1;
		this->entries.erase(this->entries.begin() +K, this->entries.end());
		this->moves.erase(this->moves.begin() + K, this->moves.end());

	}
	Show* p = new Show(MediaType, id, title, director, runtime, budget, release_year, rating, (ShowType)showtype);
	myrepo.AddShow(p);

	k++;
	this->moves.push_back("ADD_SHOW");
	Show* pp = new Show(MediaType, id, title, director, runtime, budget, release_year, rating, (ShowType)showtype);
	this->entries.push_back(pp);
}

void Controller::CRemove(int id)
{
	/**
	 * CRemove-removes item from repo.
	 * 
	 * \param id
	 */
	if (this->k != this->moves.size()-1)
	{
		int K = this->k+1;
		this->entries.erase(this->entries.begin() + K, this->entries.end());
		this->moves.erase(this->moves.begin() + K, this->moves.end());

	}

	VisualMedia* item = this->myrepo.Search(id);
	if (item->getMediaType() == 1)
	{
		Movie* p = new Movie(item->getMediaType(), item->getId(), item->getTitle(), item->getDirector(), item->getRuntime(), item->getBudget(), item->getRelease_year(), item->getRating(),(MovieGenre) item->getGenreOrType());
		this->entries.push_back(p);
		k++;
		this->moves.push_back("REMOVE_MOVIE");
		this->myrepo.Remove(id);
	}
	else if(item->getMediaType() == 2)
	{
		Show* p = new Show(item->getMediaType(), item->getId(), item->getTitle(), item->getDirector(), item->getRuntime(), item->getBudget(), item->getRelease_year(), item->getRating(), (ShowType)item->getGenreOrType());
		this->entries.push_back(p);
		k++;
		this->moves.push_back("REMOVE_SHOW");
		this->myrepo.Remove(id);


	}
	
	
}

bool Controller::CFindID(int id)
{
	/**
	 * CFindID-Returns true if id is found	.
	 * 
	 * \param id
	 * \return 
	 */
	return myrepo.Search(id);
}

void Controller::CEdit(int id, string title, string director, int runtime, float budget, int release_year, Rating rating, int other)
{
	/**
	 * CEdit-Edits repo item.
	 * 
	 * \param id
	 * \param title
	 * \param director
	 * \param runtime
	 * \param budget
	 * \param release_year
	 * \param rating
	 * \param other
	 */
	/*
	if (this->k != this->moves.size()-1)
	{
		int K = this->k;
		this->entries.erase(this->entries.begin() + K, this->entries.end());
		this->moves.erase(this->moves.begin() + K, this->moves.end());
	
	}
	*/

	//bool rez;
	VisualMedia* p=this->myrepo.Search(id);
	if (p->getMediaType() == 1)
	{
		Movie* pm1 = new Movie(1, p->getId(), p->getTitle(), p->getDirector(), p->getRuntime(), p->getBudget(), p->getRelease_year(), p->getRating(), (MovieGenre)p->getGenreOrType());
		//k++;
		//this->moves.push_back("BEFORE_EDIT");
		//this->entries.push_back(pm1);
		if (myrepo.Edit(id, title, director, runtime, budget, release_year, rating, other) == true)
		{
			Movie* pm2 = new Movie(1, id, title, director, runtime, budget, release_year, rating, (MovieGenre)other);
			//k++;
			//this->moves.push_back("AFTER_EDIT");
			//this->entries.push_back(pm2);
		}
		else
		{
			//this->moves.erase(this->moves.begin() + k);
			//this->entries.erase(this->entries.begin() + k);

			//k--;

		}

		
		
	}
	else if (p->getMediaType() == 2)
	{
		Show* pm1 = new Show(1, p->getId(), p->getTitle(), p->getDirector(), p->getRuntime(), p->getBudget(), p->getRelease_year(), p->getRating(), (ShowType)p->getGenreOrType());
		//k++;
		//this->moves.push_back("BEFORE_EDIT");
		//this->entries.push_back(pm1);
		/// SCHIMBARE SAR PUTEA SA NU SE SALVEZE PT CA II IN If
		if (myrepo.Edit(id, title, director, runtime, budget, release_year, rating, other) == true)
		{
			Show* pm2 = new Show(1, id, title, director, runtime, budget, release_year, rating, (ShowType)other);
		//	k++;
		//	this->moves.push_back("AFTER_EDIT");
		//	this->entries.push_back(pm2);
		}
		else
		{
			//this->moves.erase(this->moves.begin() + k);
			//this->entries.erase(this->entries.begin() + k);

			//k--;

		}
	



	}

	
	

}

void Controller::CShowAll()
{
	/**
	 * CShowAll-Outputs all elements from repo.
	 * 
	 */
	myrepo.ShowAll();
}

void Controller::CImport()
{
	/**
	 * CImport-Imports elements from csv file into repo.
	 * 
	 */
	myrepo.importCSV();
}

void Controller::CExport()
{
	/**
	 * CExport-Exports elements from repo to csv file.
	 *
	 */
	myrepo.exportCSV();
}




bool Controller::Undo()
{
	if (k >=0 && k < this->moves.size())
	{
		if (this->moves[k] == "ADD_MOVIE")
		{
			this->myrepo.Remove(this->entries[k]->getId());
			k--;

		}
		else if (this->moves[k] == "ADD_SHOW")
		{
			this->myrepo.Remove(this->entries[k]->getId());
			k--;
		}
		else if (this->moves[k] == "REMOVE_MOVIE")
		{
			Movie* pm = new Movie(this->entries[k]->getMediaType(),this->entries[k]->getId(), this->entries[k]->getTitle(), this->entries[k]->getDirector(), this->entries[k]->getRuntime(), this->entries[k]->getBudget(), this->entries[k]->getRelease_year(), this->entries[k]->getRating(), (MovieGenre)this->entries[k]->getGenreOrType());
			this->myrepo.addMovie(pm);
			k--;
		}
		else if (this->moves[k] == "REMOVE_SHOW")
		{
			Show* pm = new Show(this->entries[k]->getMediaType(), this->entries[k]->getId(), this->entries[k]->getTitle(), this->entries[k]->getDirector(), this->entries[k]->getRuntime(), this->entries[k]->getBudget(), this->entries[k]->getRelease_year(), this->entries[k]->getRating(), (ShowType)this->entries[k]->getGenreOrType());
			this->myrepo.AddShow(pm);
			k--;

		}
		
	

		return true;
		
	}
	return false;
}

bool Controller::Redo()
{
	if (k >= -1 && k < this->moves.size() - 1)
	{	
		if (this->moves[k] == "BEFORE_EDIT")
		{
		}
		else {
			k++;
		}
		if (this->moves[k] == "ADD_MOVIE")
		{
			Movie* p = new Movie(1, this->entries[k]->getId(), this->entries[k]->getTitle(), this->entries[k]->getDirector(), this->entries[k]->getRuntime(), this->entries[k]->getBudget(), this->entries[k]->getRelease_year(), this->entries[k]->getRating(), (MovieGenre)this->entries[k]->getGenreOrType());
			this->myrepo.addMovie(p);

		}
		else if (this->moves[k] == "ADD_SHOW")
		{
			Show* p = new Show(2, this->entries[k]->getId(), this->entries[k]->getTitle(), this->entries[k]->getDirector(), this->entries[k]->getRuntime(), this->entries[k]->getBudget(), this->entries[k]->getRelease_year(), this->entries[k]->getRating(), (ShowType)this->entries[k]->getGenreOrType());
			this->myrepo.AddShow(p);


		}
		else if (this->moves[k] == "REMOVE_MOVIE")
		{
			this->myrepo.Remove(this->entries[k]->getId());
		}
		else if (this->moves[k] == "REMOVE_SHOW")
		{
			this->myrepo.Remove(this->entries[k]->getId());

		}
		
		return true;
	}
	return false;

}

