#include"Repo.h"
using namespace std;

class Controller {
public:
	/**
	 * Controller-connects Repo level to UI level.
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
	void CAddMovie(int MediaType,int id,string title,string director,int runtime,float budget,int release_year,Rating rating, int genre);
	void CAddShow(int MediaType, int id, string title, string director, int runtime, float budget, int release_year, Rating rating, int showtype);
	void CRemove(int id);
	bool CFindID(int id);
	void CEdit(int id, string title, string director, int runtime, float budget, int release_year, Rating rating, int other);
	inline void plusk() {k++;}
	inline void minusk() { k--; }
	void CShowAll();
	void CImport();
	void CExport();
	bool Undo();
	bool Redo();
	///undo redo next


protected:
	VisualMediaRepo myrepo;
	vector<string> moves;
	vector<VisualMedia*> entries;
	int k = -1;



};
