#ifndef LIBRARY_H_
#define LIBRARY_H_

#include "UsersBase.h"
#include "BooksStorage.h"

class Library {
private:
	UsersBase registeredUsers;
	BooksStorage library;


public:

	void logIn(const User&);
	void logOut();

	void booksAll()const;
	void booksInfo(int) const;
	void booksFind(String, String) const;
	void booksSort(String);
	void booksAdd(const Book&);
	void booksRemove(int);

	void usersAdd(const User&);
	void usersRemove(const String&);

	void open(const char*);
	void save(const char*);
	void saveas(const char*);
	void close();
	
};
#endif // !LIBRARY_H_
