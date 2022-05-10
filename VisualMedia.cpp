#include "VisualMedia.h"
#include<iostream>
#include<sstream>
using namespace std;


VisualMedia::VisualMedia(int MediaType,int id, string title, string director, int runtime, float budget, int release_year, Rating rating)
{
	/**
	 * Constructor for Visual Media.
	 * 
	 * \param MediaType
	 * \param id
	 * \param title
	 * \param director
	 * \param runtime
	 * \param budget
	 * \param release_year
	 * \param rating
	 */

	this->MediaType = MediaType;
	this->id = id;
	this->title.append(title);
	this->director.append(director);
	//this->title = title;
	//this->director = director;
	this->runtime = runtime;
	this->budget = budget;
	this->release_year = release_year;
	this->rating = rating;
}


string VisualMedia::toStringg()
{
	/**
	 * Returns visual media elements in a string.
	 * 
	 * \return 
	 */
	stringstream ss;
	ss<< to_string(id) + " " +this->title + " " +this-> director + " " + to_string(runtime) + " " + to_string(budget) + " " + to_string(release_year) + " " + to_string((int)rating);
	return ss.str();
}

Movie::Movie(int MediaType, int id,string title, string director, int runtime, float budget, int release_year, Rating rating, MovieGenre genre):VisualMedia{MediaType,id,title,director,runtime,budget,release_year,rating}
{
	/**
	 * Movie Constructor.
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
	
	this->genre = genre;

}

string Movie::toStringg()
{
	/**
	 * Returns Movie elements in a string.
	 * 
	 * \return 
	 */
	stringstream ss;
	ss<<"Movie: ID:" << to_string(id) + " Title: " + this->title + " Director: " + this->director + " Runtime: " + to_string(runtime) + " Budget: " + to_string(budget) + " Release_Year: " + to_string(release_year) + " Rating: " + to_string((int)rating) + " Genre: " + to_string((int)genre);
	return ss.str();

}

Show::Show(int MediaType, int id, string title, string director, int runtime, float budget, int release_year, Rating rating, ShowType type) :VisualMedia{ MediaType,id,title,director,runtime,budget,release_year,rating}
{
	/**
	 * Show Constructor.
	 * 
	 * \param MediaType
	 * \param id
	 * \param title
	 * \param director
	 * \param runtime
	 * \param budget
	 * \param release_year
	 * \param rating
	 * \param type
	 */
	this->type = type;
}

string Show::toStringg()
{
	/**
	 * Returns show elements in a string.
	 * 
	 * \return 
	 */
	stringstream ss;
	ss<<"Show: ID:" << to_string(id) + " Title: " + this->title + " Director: " + this->director + " Runtime: " + to_string(runtime) + " Budget: " + to_string(budget) + " Release_Year: " + to_string(release_year) + " Rating: " + to_string((int)rating) + " ShowType: " + to_string((int)type);
	return ss.str();
}


