#ifndef BOOKSSTORAGE_H_
#define BOOKSSTORAGE_H_
#include "Book.h"

class BooksStorage {
private:
	Book* books;
	int numberOfBooks;
	int capacity;

	void copyStorage(const BooksStorage&);
	void deleteStorage();
	void resize();

public:
	BooksStorage(int = 1);
	BooksStorage(const BooksStorage&);
	BooksStorage& operator=(const BooksStorage&);
	~BooksStorage();

	void booksPrint() const;
	void findBook(String, String) const;
	void sortBooks(String);
	void addBook(const Book&);
	void removeBook(const Book&);
	
	int getNumberOfBooks()const;
	Book& operator[](const int );
	const Book& operator[](const int )const;


	void deleteArray() {
		delete[] books;
		capacity = 1;
		numberOfBooks = 0;
	}

};


#endif
