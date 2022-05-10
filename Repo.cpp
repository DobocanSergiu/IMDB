#pragma warning(disable:4996)
#include"Repo.h"
#include <sstream>
#include<fstream>


VisualMediaRepo::VisualMediaRepo()
{

}
void VisualMediaRepo::importCSV()
{
	/**
	 * importCSV-takes a csv file and puts values in repo.
	 * 
	 */
	ifstream fi("sergiu.csv");
	char currentline[3000];
	char* pch;
	string mediatype, title, director, runtime, budget, release_year, rating, other, id;
	if (!fi.is_open())
	{
		std::cerr << "Unable to open file\n";
		return;
	}
	while (!fi.eof())
	{
		fi >> currentline;
		pch = strtok(currentline, ",.");
		while (pch != NULL)
		{
			string s = pch;
			mediatype.append(s);
			//cout << "mediatype " << mediatype << '\n';
			pch = strtok(NULL, ",");
			

			 s = pch;
			id.append(s);
			//cout << "id " << id << '\n';
			pch = strtok(NULL, ",");

			 s = pch;
			title.append(s);
			//cout << "title " << title << '\n';
			pch = strtok(NULL, ",.");

			 s = pch;
			director.append(s);
			//cout << "director " << director << '\n';

			pch = strtok(NULL, ",.");

			 s = pch;
			runtime.append(s);
			//cout << "runtime " << runtime << '\n';

			pch = strtok(NULL, ",.");

			 s = pch;
			budget.append(s);
			//cout << "budget " << budget << '\n';

			pch = strtok(NULL, ",.");

			s = pch;
			release_year.append(s);
			//cout << "release_year " << release_year << '\n';

			pch = strtok(NULL, ",.");

			s = pch;
			rating.append(s);
			//cout << "rating " << rating << '\n';

			pch = strtok(NULL, ",.");

			s = pch;
			other.append(s);
			//cout << "other " << other << '\n';


			pch = strtok(NULL, ",.");


			if (mediatype == "1")
			{
				Movie* p = new Movie(stoi(mediatype), stoi(id), title, director, (float)stoi(runtime), stoi(budget), stoi(release_year), (Rating)stoi(rating), (MovieGenre)stoi(other));
				this->addMovie(p);
			}
			else
			{
				Show* p = new Show(stoi(mediatype), stoi(id), title, director, (float)stoi(runtime), stoi(budget), stoi(release_year), (Rating)stoi(rating), (ShowType)stoi(other));
				this->AddShow(p);


			}
			mediatype.clear();
			id.clear();
			title.clear();
			director.clear();
			runtime.clear();
			budget.clear();
			release_year.clear();
			rating.clear();
			other.clear();

			
			 

		}
	}
	fi.close();

}

void VisualMediaRepo::exportCSV()
{
	/**
	 * exportCSV-puts repo values in CSV file.
	 * 
	 */
	ofstream myfile;
	myfile.open("sergiu.csv");
	for (int i = 0; i < this->medias.size(); i++)
	{
		myfile << this->medias[i]->getMediaType() << "," << this->medias[i]->getId() << "," << this->medias[i]->getTitle() << "," << this->medias[i]->getDirector() << "," << this->medias[i]->getRuntime() << "," << this->medias[i]->getBudget() << "," << this->medias[i]->getRelease_year() << "," << (int)this->medias[i]->getRating() << "," << this->medias[i]->getGenreOrType()<<'\n';
	}
	myfile.close();
}


void VisualMediaRepo::addMovie(Movie *movie_a) {
	/**
	 * addMovie-Adds movie to repository.
	 * 
	 * \param movie_a
	 */
	medias.push_back(movie_a);

}
void VisualMediaRepo::AddShow(Show *show_a) {
	/**
	 * AddShow-Adds show to repository.
	 * 
	 * \param show_a
	 */
	medias.push_back(show_a);
}

bool VisualMediaRepo::Remove(int id){
	/**
	 * Remove-removes element with specified id from repo.
	 * 
	 * \param id
	 */
	for (int i = 0; i < medias.size(); i++)
	{
		if (this->medias[i]->getId() == id)
		{
			this->medias.erase(medias.begin() + i);
			return true;

		}
	}
	return false;

}

bool VisualMediaRepo::Edit(int id, string title, string director, int runtime, float budget, int release_year, Rating rating, int other)
{
	/**
	 * Edit-changes all entries of specifed item.
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
	for (int i = 0; i < medias.size(); i++)
	{
		if (this->medias[i]->getId() == id)
		{
			medias[i]->setTitle(title);
			medias[i]->setDirector(director);
			medias[i]->setRuntime(runtime);
			medias[i]->setBudget(budget);
			medias[i]->setRelease_year(release_year);
			medias[i]->setRating(rating);
			medias[i]->setGenreOrType(other);
			return true;
		}
	}
	return false;

	
}
VisualMedia* VisualMediaRepo::Search(int id)
{
	for (int i = 0; i < this->medias.size(); i++)
	{
		if (this->medias[i]->getId() == id)
		{
			return this->medias[i];
		}
	}
	return nullptr;
}
void VisualMediaRepo::ShowAll()
{
	/**
	 * ShowAll-Outputs all elements from repo.
	 * 
	 */
	int i;
	for ( i = 0; i < this->medias.size(); i++)
	{
		cout << medias[i]->toStringg()<<'\n';
	}
}

ostream& operator << (ostream& out, const VisualMediaRepo& c)
{
	/**
	 * Stream operator<< overloading- equivalent to ShowAll.
	 * 
	 * \param out
	 * \param c
	 * \return 
	 */
	for (int i = 0; i < c.medias.size(); i++)
	{
		out << c.medias[i]->toStringg() << '\n';
	}
	return out;
}


