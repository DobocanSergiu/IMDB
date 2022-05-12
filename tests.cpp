#include"tests.h"
#include"UI.h"
#include <cassert>
void TESTS::testVisualMedia()
{
	Movie testmovie(1, 1, "Title", "Director", 100, 100, 1999, (Rating)1, (MovieGenre)0);
	Show testshow(2, 2, "Title", "Director", 10, 10, 1999, (Rating)0, (ShowType)0);
	assert(testmovie.getBudget() == 100);
	assert(testmovie.getDirector() == "Director");
	assert(testmovie.getGenreOrType() == 0);
	assert(testmovie.getId() == 1);
	assert(testmovie.getMediaType() == 1);
	assert(testmovie.getRating() == (Rating)1);
	assert(testmovie.getRelease_year() == 1999);
	assert(testmovie.getRuntime() == 100);
	assert(testmovie.getTitle() == "Title");
	testmovie.setDirector("NEWDIRECTOR");
	assert(testmovie.getDirector() == "NEWDIRECTOR");


	assert(testshow.getBudget() == 10);
	assert(testshow.getDirector() == "Director");
	assert(testshow.getGenreOrType() == 0);
	assert(testshow.getId() == 2);
	assert(testshow.getMediaType() == 2);
	assert(testshow.getRating() == (Rating)0);
	assert(testshow.getRelease_year() == 1999);
	assert(testshow.getRuntime() == 10);
	assert(testshow.getTitle() == "Title");
	testshow.setDirector("NEWDIRECTOR");
	assert(testshow.getDirector() == "NEWDIRECTOR");
}
void TESTS::testRepo() {
	VisualMediaRepo mystuff;
	Movie testmovie(1, 1, "Title", "Director", 100, 100, 1999, (Rating)1, (MovieGenre)0);
	Show testshow(2, 2, "Title", "Director", 10, 10, 1999, (Rating)0, (ShowType)0);
	Movie testmovie2(1,1, "NEWTITLE", "NEWDIRECTOR", 100, 100, 1999, (Rating)1, (MovieGenre)0);
	mystuff.addMovie(&testmovie);
	mystuff.AddShow(&testshow);
	assert(mystuff.Search(1) == &testmovie);
	assert(mystuff.Search(2) == &testshow);
	mystuff.Edit(1, "NEWTITLE", "NEWDIRECTOR", 100, 100, 1999, (Rating)0, 0);
	assert(mystuff.Search(1) != &testmovie2);
	assert(mystuff.Search(1) == &testmovie);

	

}
void TESTS::testController() {
	Controller testcontroller;
	testcontroller.CAddMovie(1, 1, "Title", "Director", 100, 100, 1999, (Rating)1, 0);
	testcontroller.CAddShow(2, 2, "Title", "Director", 10, 10, 1999, (Rating)0, 0);
	assert(testcontroller.CFindID(1) == true);
	assert(testcontroller.CFindID(2) == true);
	testcontroller.Undo();
	assert(testcontroller.CFindID(2) == false);
	testcontroller.Redo();
	assert(testcontroller.CFindID(2) == true);


}
void TESTS::runtests() {
	testVisualMedia();
	testRepo();
	testController();


}
