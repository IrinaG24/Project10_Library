#include "Library.h"
#include<iostream>
#include<fstream>

///logs in a user
void Library::logIn(const User& toLogin) {
	for (int i = 0; i < registeredUsers.getNumberOfUsers(); i++) {

		if (!(toLogin == registeredUsers[i]) && registeredUsers[i].isLogged() == true) {
			std::cout << "Another user is logged in!\n";
			break;
		}
		else if (toLogin == registeredUsers[i]) {
			if (registeredUsers[i].isLogged() == true) {
				std::cout << "You are already logged in!\n";
				break;
			}
			else {
				registeredUsers[i].setLogged(true);
				std::cout << "Welcome, " << toLogin.getUserName() << "!" << std::endl;
				break;
			}
		}
		else {
			std::cout << "Wrong username or password!\n";
		}
	}
}

//logs out a logged in users
void Library::logOut() {
	if (registeredUsers.isThereLoggedUser() == true) {
		for (int i = 0; i < registeredUsers.getNumberOfUsers(); i++) {
			if (registeredUsers[i].isLogged() == true) {
				registeredUsers[i].setLogged(false);
				std::cout << "User logged out!\n";
				break;
			}
		}
	}
	else std::cout << "There is no logged in user!\n";
}

///prints general information about the books in the library
void Library::booksAll() const {
	if (registeredUsers.isThereLoggedUser() == true) {
		library.booksPrint();
	}
	else std::cout << "User must be logged in!\n";
}

///find a book in the library and display information about the book
void Library::booksFind(String option, String toSearch) const{
	if (registeredUsers.isThereLoggedUser() == true) {
		library.findBook(option, toSearch);
	}
	else std::cout << "User must be logged in!\n";
}

///find a book according to ID and displpay information
void Library::booksInfo(int index)const {
	if (registeredUsers.isThereLoggedUser() == true) {
		for (int i = 0; i < library.getNumberOfBooks(); i++) {
			if (library[i].getID() == index) {
				library[i].bookDetailedInfo();
			}
		}
	}
	else std::cout << "User must be logged in!\n";
}

///sorts the books
void Library::booksSort(String option) {
	if (registeredUsers.isThereLoggedUser() == true) {
		library.sortBooks(option);
		std::cout << "The books are sorted!\n";
	}
	else std::cout << "User must be logged in!\n";
}

///adds book
void Library::booksAdd(const Book& toAdd) {
	int flag = 0;
	for (int i = 0; i < registeredUsers.getNumberOfUsers(); i++) {
		if (registeredUsers[i].isAdministrator() && registeredUsers[i].isLogged()) {
			flag = 1;
			library.addBook(toAdd);
			std::cout << "Book added!\n";
			break;
		}
	}
	if (flag == 0) std::cout << "Logged Administrator is needed!\n";
}

///removes book according to its ID
void Library::booksRemove(int index) {
	int flag = 0;
	for (int i = 0; i < registeredUsers.getNumberOfUsers(); i++) {
		if (registeredUsers[i].isAdministrator() && registeredUsers[i].isLogged()) {
			flag = 1;
			break;
		}
	}
	if (flag == 1) {
		for (int i = 0; i < library.getNumberOfBooks(); i++) {
			if (library[i].getID() == index) {
				library.removeBook(library[i]);
				std::cout << "Book is removed!\n";
				break;
			}
		}
	}else if (flag == 0) std::cout << "Logged Administrator is needed!\n";
	

}

///add user + saves in file
void Library::usersAdd(const User& toAdd) {
	int flag = 0;
	for (int i = 0; i < registeredUsers.getNumberOfUsers(); i++) {
		if (registeredUsers[i].isAdministrator() && registeredUsers[i].isLogged()) {
			flag = 1;
			registeredUsers.userAdd(toAdd);
			std::ofstream oFile;
			oFile.open("users.txt", std::ios::app);
			oFile << "\n";
			saveInFile(oFile, toAdd);
			oFile.close();
			std::cout << "This user is added!\n";
			break;
		}
	}
	if (flag == 0) std::cout << "Logged Administrator is needed!\n";
}

///remove user + delete from file
void Library::usersRemove(const String& toRemove) {
	int flag = 0;
	for (int i = 0; i < registeredUsers.getNumberOfUsers(); i++) {
		if (registeredUsers[i].isAdministrator() && registeredUsers[i].isLogged()) {
			flag = 1;
			break;
		}
	}
	if (flag == 1) {
		for (int i = 0; i < registeredUsers.getNumberOfUsers(); i++) {
			if (registeredUsers[i].getUserName() == toRemove) {
				flag = i;
			}
		}
		registeredUsers.userRemove(registeredUsers[flag]);
		std::ofstream oFile;
		oFile.open("users.txt", std::ios::trunc);
		for (int i = 0; i < registeredUsers.getNumberOfUsers(); i++) {
			saveInFile(oFile, registeredUsers[i]);
			oFile << "\n";
		}
		oFile.close();
		std::cout << "This user is removed!\n";
		flag = 1;
	}
	else std::cout << "Logged Administrator is needed!\n";
}


///command console files
void Library::open(const char* toOpen){
	
	std::ifstream iFile;
	iFile.open(toOpen);
	if (!iFile) {
		std::ofstream oFile(toOpen);
		oFile.close();
		iFile.open(toOpen);
	}
	iFile.seekg(0, std::ios::end);
	if (iFile.tellg()==0) {
		std::cerr << "The file is empty!\n";
	}
	
	else {iFile.seekg(0, std::ios::beg);
		if ( toOpen[0]=='u' && toOpen[1] == 's' && toOpen[2] == 'e' && toOpen[3] == 'r' && toOpen[4] == 's') {
			for (;;) {
				User toAdd;
				toAdd.setLevel(2);
				saveFromFile(iFile, toAdd);
				registeredUsers.userAdd(toAdd);
				iFile.ignore();
				if (iFile.eof()) {
					break;
				}
			}

		}
		else/// opens the information for books
		{
			for (;;) {
				Book toAdd;
				saveFromFile(iFile, toAdd);
				library.addBook(toAdd);
				iFile.ignore();
				if (iFile.eof()) {
					break;
				}
			}
		
		}
		std::cout << "Successfully opened " << toOpen << "!\n";
	}

	iFile.close();

}

void Library::save(const char* toSaveIn) {
	std::ofstream oFile;
	oFile.open(toSaveIn, std::ios::trunc);
	for (int i = 0; i < library.getNumberOfBooks(); i++) {
		library[i].saveInFile(oFile);
	}
	oFile.close();
	std::cout << "Successfully saved " << toSaveIn << "!\n";

}

void Library::saveas(const char* saveInNewFile) {
	std::ofstream oFile;
	oFile.open(saveInNewFile, std::ios::app);
	for (int i = 0; i < library.getNumberOfBooks(); i++)
		library[i].saveInFile(oFile);
	oFile.close();
	std::cout << "Successfully saved " << saveInNewFile << "!\n";
}

void Library::close() {
	library.deleteArray();
}