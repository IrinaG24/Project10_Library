#ifndef BOOK_H_
#define BOOK_H_
#include "String.h"

class Book
{
private:
    String author;
    String title;
    String genre;
    String description;
    int year;
    String keyWords;
    int rating;
    int ID;

public:
    Book();
    Book(String, String, String, String, int, String, int, int);
    void bookDetailedInfo() const;
    void bookPrint() const;

    String getTitle()const;
    String getAuthor()const;
    int getYear()const;
    int getRating()const;
    int getID()const;
    String getKeyWords()const;

    bool operator==(const Book&);

    friend std::istream& operator>>(std::istream&, Book&);
    friend std::ostream& operator<<(std::ostream&, Book&);
    friend void saveFromFile(std::istream&, Book&);
    void saveInFile (std::ostream&);
};

#endif BOOK_H_


