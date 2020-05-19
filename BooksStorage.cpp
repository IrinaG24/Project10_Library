#include "BooksStorage.h"
#include<iostream>

void BooksStorage::copyStorage(const BooksStorage& other) {
	try {
		books = new Book[other.capacity];
	}
	catch (...) {
		std::cerr << "Allocation failed!" << std::endl;
		return;
	}
	capacity = other.capacity;
	numberOfBooks = other.numberOfBooks;
	for (int i = 0; i < numberOfBooks; i++)
		books[i] = other.books[i];
}

void BooksStorage::deleteStorage() {
	delete[] books;
}

void BooksStorage::resize() {
	Book* doubleBooks;
	try {
		 doubleBooks = new Book[capacity * 2];
	}
	catch (...) {
		std::cerr << "Allocation failed!" << std::endl;
		return;
	}

	for (int i = 0; i < numberOfBooks; i++)
		doubleBooks[i] = books[i];
	capacity *= 2;
	delete[] books;
	books = doubleBooks;

}

BooksStorage::BooksStorage(int capacity) {
	try {
		books = new Book[capacity];
	}
	catch (...) {
		std::cerr << "Allocation failed!" << std::endl;
		return;
	}
	this->capacity = capacity;
	numberOfBooks = 0;
}

BooksStorage::BooksStorage(const BooksStorage& other) {
	copyStorage(other);
}

BooksStorage& BooksStorage::operator=(const BooksStorage& other) {
	if (this != &other) {
		deleteStorage();
		copyStorage(other);
	}
	return *this;
}

BooksStorage::~BooksStorage() {
	deleteStorage();
}

void BooksStorage::booksPrint() {
	for (int i = 0; i < numberOfBooks; i++) {
		books[i].bookPrint();
		std::cout << "-----------------------------------------\n";
	}
}

void BooksStorage::findBook(String option, String toSearch) {
	int flag = 0;
	if (option == "title") {
		for (int i = 0; i < numberOfBooks; i++) {
			if (toSearch == books[i].getTitle()) {
				books[i].bookDetailedInfo();
				flag = 1;
			}
		}
		if (flag == 0) std::cout << "This book is not found!" << std::endl;
	}
	else if (option == "author") {
		for (int i = 0; i < numberOfBooks; i++) {
			if (toSearch == books[i].getAuthor()) {
				books[i].bookDetailedInfo();
				flag = 1;
			}
		}
		if (flag == 0) std::cout << "This book is not found!" << std::endl;
	}
	else if (option == "tag") {
		for (int i = 0; i < numberOfBooks; i++) {
			String keyWordsI = books[i].getKeyWords();
			int k = 0;
			for (int j = 0; j < keyWordsI.Size(); j++) {
				if (keyWordsI[j] == toSearch[k]) k++;
				else {
					if (k == toSearch.Size()) {
						flag = 1;
						books[i].bookPrint();
						break;
					}
					k = 0;
				}
			}
		}
		if (flag==0) std::cout << "This book is not found!" << std::endl;
	}
}

void BooksStorage::sortBooks(String option, String howToSort) {
	Book temp;
	if (howToSort == "asc") {
		if (option == "title") {
			for (int i = 0; i < numberOfBooks; i++) {
				for (int j = 0; j < numberOfBooks; j++) {
					if (books[i].getTitle() < books[j].getTitle()) {
						temp = books[i];
						books[i] = books[j];
						books[j] = temp;

					}
				}
			}
		}else if (option == "author") {
			for (int i = 0; i < numberOfBooks; i++) {
				for (int j = 0; j < numberOfBooks; j++) {
					if (books[i].getAuthor() < books[j].getAuthor()) {
						temp = books[i];
						books[i] = books[j];
						books[j] = temp;

					}
				}
			}
		}else if (option == "year") {
			for (int i = 0; i < numberOfBooks; i++) {
				for (int j = 0; j < numberOfBooks; j++) {
					if (books[i].getYear() < books[j].getYear()) {
						temp = books[i];
						books[i] = books[j];
						books[j] = temp;

					}
				}
			}
		}else if (option == "rating") {
			for (int i = 0; i < numberOfBooks; i++) {
				for (int j = 0; j < numberOfBooks; j++) {
					if (books[i].getRating() < books[j].getRating()) {
						temp = books[i];
						books[i] = books[j];
						books[j] = temp;

					}
				}
			}
		}
	}
	else if (howToSort == "desc") {

		if (option == "title") {
			for (int i = 0; i < numberOfBooks; i++) {
				for (int j = 0; j < numberOfBooks; j++) {
					if (books[i].getTitle() > books[j].getTitle()) {
						temp = books[i];
						books[i] = books[j];
						books[j] = temp;

					}
				}
			}
		}
		else if (option == "author") {
			for (int i = 0; i < numberOfBooks; i++) {
				for (int j = 0; j < numberOfBooks; j++) {
					if (books[i].getAuthor() > books[j].getAuthor()) {
						temp = books[i];
						books[i] = books[j];
						books[j] = temp;

					}
				}
			}
		}
		else if (option == "year") {
			for (int i = 0; i < numberOfBooks; i++) {
				for (int j = 0; j < numberOfBooks; j++) {
					if (books[i].getYear() > books[j].getYear()) {
						temp = books[i];
						books[i] = books[j];
						books[j] = temp;

					}
				}
			}
		}
		else if (option == "rating") {
			for (int i = 0; i < numberOfBooks; i++) {
				for (int j = 0; j < numberOfBooks; j++) {
					if (books[i].getRating() > books[j].getRating()) {
						temp = books[i];
						books[i] = books[j];
						books[j] = temp;

					}
				}
			}
		}
	}
}

void BooksStorage::addBook(const Book& toAdd) {
	if (capacity == numberOfBooks) resize();
	books[numberOfBooks].operator=(toAdd);
	numberOfBooks++;

}

void BooksStorage::removeBook(const Book& toRemove) {
	int toFind = 0;
	for (int i = 0; i < numberOfBooks; i++)
	{
		if (books[i] == toRemove) {
			toFind = i;
			break;
		}
	}
	Book* temp;
	try {
		temp = new Book[capacity];
	}
	catch (...) {
		std::cerr << "Allocation failed!" << std::endl;
		return;
	}

	for (int i = 0; i < toFind; i++)
		temp[i] = books[i];
	for (int i = toFind + 1; i < numberOfBooks; i++)
		temp[i - 1] = books[i];

	delete[] books;
	books = temp;
	numberOfBooks--;
}
int BooksStorage:: getNumberOfBooks()const {
	return numberOfBooks;
}


Book& BooksStorage:: operator[](const int index) {
	return books[index];
}
const Book& BooksStorage::operator[](const int index)const {
	return books[index];
}
