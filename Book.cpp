#include "Book.h"
#include<iostream>


Book::Book() {
	author = "";
	title = "";
	genre = "";
	description = "";
	year = 0;
	keyWords = "";
	rating = 0;
	ID = 0;
}

Book::Book(String author_, String title_, String genre_, String description_, int year_, String keyWords_, int rating_, int ID_) {
	author = author_;
	title = title_;
	genre = genre_;
	description = description_;
	year = year_;
	keyWords = keyWords_;
	rating = rating_;
	ID = ID_;
}

void Book::bookDetailedInfo() {
	std::cout << "Title: " << title << std::endl;
	std::cout << "Author: " << author << std::endl;
	std::cout << "Genre: " << genre << std::endl;
	std::cout << "Descpription: " << description << std::endl;
	std::cout << "Year: " << year << std::endl;
	std::cout << "Rating: " << rating << std::endl;
}

void Book::bookPrint() {
	std::cout << "Title: " << title << std::endl;
	std::cout << "Author: " << author << std::endl;
	std::cout << "Genre: " << genre << std::endl;
	std::cout << "ID: " << ID << std::endl;
}

String Book::getTitle()const {
	return title;
}
String Book::getAuthor()const {
	return author;
}
int Book::getYear()const {
	return year;
}
int Book::getRating()const {
	return rating;

}
String Book::getKeyWords() const {
	return keyWords;
}

bool Book:: operator==(const Book& find) {
	if (author == find.author && title == find.title && genre == find.genre && year==find.year && ID == find.ID) return true;
	else return false;
}