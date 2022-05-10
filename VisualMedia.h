#pragma once
#include<iostream>
#include<vector>
#include<string>
using namespace std;
enum class Rating {
	G,
	PG,
	PG_13,
	R,
	NC_17

};
enum class MovieGenre {
	ACTION,
	COMEDY,
	HORROR,
	ADVENTURE

};

enum class ShowType {
	FICTION,
	NON_FICTION

};

class VisualMedia {
	
public:
	/**
	 * Default Data Type.
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
	VisualMedia(int MediaType,int id, string title, string director, int runtime, float budget, int release_year, Rating rating);
	inline int getId() const { return this->id; }
	inline void setId(int Id) { this->id = Id; }

	inline int getMediaType() const { return this->MediaType; }
	inline void setMediaType() { this->MediaType = MediaType; }

	inline string getTitle() const { return this->title;}
	inline void setTitle(string other) { this->title = other; }

	inline string getDirector() const { return this->director; }
	inline void setDirector(string other) { this->director = other; }

	inline int getRuntime() const { return this->runtime; }
	inline void setRuntime(int other) { this->runtime = other; }

	inline float getBudget() const { return this->budget; }
	inline void setBudget(float other) { this->budget = other; }

	inline int getRelease_year() const { return this->release_year; }
	inline void setRelease_year(int other) { this->release_year = other; }


	inline Rating getRating() const { return this->rating; }
	inline void setRating(Rating other) { this->rating = other; }

	virtual void setGenreOrType(int other)=0;
	virtual int getGenreOrType() = 0;
	virtual string toStringg();

protected:
	
	int MediaType;
	int id;
	string title;
	string director;
	int runtime;
	float budget;
	int release_year;
	Rating rating;

};


class Movie :public VisualMedia {
public:
	/**
	 * Movie Data Type.
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
	Movie(int MediaType,int id, string title, string director, int runtime, float budget, int release_year, Rating rating, MovieGenre genre);
	int getGenreOrType()  { return (int)this->genre; }
	void setGenreOrType(int other)override{ this->genre =(MovieGenre)other; }
	virtual string toStringg()override;
protected:
	MovieGenre genre;
};


class Show :public VisualMedia {
public:
	/**
	 * Show Data Type.
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
	Show(int MediaType,int id, string title, string director, int runtime, float budget, int release_year, Rating rating, ShowType type);
	int getGenreOrType()  { return (int)this->type; }
	void setGenreOrType(int other)override { this->type =(ShowType) other; }
	virtual string toStringg()override;
protected:
	ShowType type;
};