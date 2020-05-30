#include "Book.h"
#include<iostream>

///default constructor
Book::Book()
{
    author = "";
    title = "";
    genre = "";
    description = "";
    year = 0;
    keyWords = "";
    rating = 0;
    ID = 0;
}

///constructor with parametres
Book::Book(String author_, String title_, String genre_, String description_, int year_, String keyWords_, int rating_, int ID_)
{
    author = author_;
    title = title_;
    genre = genre_;
    description = description_;
    year = year_;
    keyWords = keyWords_;
    rating = rating_;
    ID = ID_;
}

///prints detailed inforamation about the book
void Book::bookDetailedInfo ()const
{
    std::cout << "Title: " << title << std::endl;
    std::cout << "Author: " << author << std::endl;
    std::cout << "Genre: " << genre << std::endl;
    std::cout << "Descpription: " << description << std::endl;
    std::cout << "Year: " << year << std::endl;
    std::cout << "Rating: " << rating << std::endl;
}

///prints general inforamation about the booka
void Book::bookPrint()const
{
    std::cout << "Title: " << title << std::endl;
    std::cout << "Author: " << author << std::endl;
    std::cout << "Genre: " << genre << std::endl;
    std::cout << "ID: " << ID << std::endl;
}


///title getter
String Book::getTitle()const
{
    return title;
}

///author getter
String Book::getAuthor()const
{
    return author;
}

///year getter
int Book::getYear()const
{
    return year;
}

///rating getter
int Book::getRating()const
{
    return rating;

}

///key words getter
String Book::getKeyWords() const
{
    return keyWords;
}

///predefinition operator ==
bool Book:: operator==(const Book& find)
{
    if (author == find.author && title == find.title && genre == find.genre && year==find.year && ID == find.ID)
        return true;
    else
        return false;
}

///ID getter
int Book:: getID()const
{
    return ID;
}

///predefinition operator>>
std::istream& operator>>(std::istream& is, Book& toRead)
{
    Book temp;
    getline(is,temp.author, '|');
    getline(is, temp.title, '|');
    getline(is, temp.genre, '|');
    getline(is, temp.description, '|');
    is >> temp.year;
    is.ignore();
    getline(is, temp.keyWords, '|');
    is >> temp.rating;
    is.ignore();
    is >> temp.ID;
    is.ignore();
    toRead = temp;
    return is;

}

///predefinition operator<<
std::ostream& operator<<(std::ostream& out, Book& toCout)
{
    out << toCout.author << "|" << toCout.title << "|" << toCout.genre << "|" << toCout.description << "|" << toCout.year << "|" << toCout.keyWords << "|" << toCout.rating << "|" << toCout.ID << "\n";
    return out;
}

/// saves book from a file
void saveFromFile(std::istream& is, Book& toRead)
{
    is >> toRead;
}

///saves book in a file
void Book::saveInFile(std::ostream& out)
{
    out << *this << std::endl;
}
