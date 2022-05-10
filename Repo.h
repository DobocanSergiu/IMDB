#include"VisualMedia.h"
#include"vector"
using namespace std;
class VisualMediaRepo {
	/**
	 * Visual Media Repository that stores all movies and shows.
	 */
public:
	
	VisualMediaRepo();
	void addMovie(Movie *movie_a);
	void AddShow(Show *show_a);
	bool Remove(int id);
	bool Edit(int id, string title, string director, int runtime, float budget, int release_year, Rating rating, int other);
	VisualMedia* Search(int id);
	void ShowAll();
	friend ostream& operator << (ostream& out, const VisualMediaRepo& c);
	void importCSV();
	void exportCSV();
	 

protected:
	
	vector<VisualMedia*> medias;


};