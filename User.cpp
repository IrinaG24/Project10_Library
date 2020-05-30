#include "User.h"

///default constructor
User::User() {
	userName = "";
	password = "";
	level = 1; /// 1 - ordinary user, 2 - admin
	logged = false;
}

///constructor with parameters
User::User(String userName_, String password_, int level_) {
	userName = userName_;
	password = password_;
	level = level_;
}

///predefenition operator ==
bool User::operator==(const User& other) const {
	if (userName == other.userName && password==other.password) return true;
	else return false;
}

///checks if the user is logged in
bool User::isLogged()const {
	if (logged == true) return true;
	else return false;
}

///checks if the user is admin
bool User::isAdministrator()const {
	if (level == 2) return true;
	else return false;
}

///logs in/logs out user
void User::setLogged(bool status) {
	logged = status;
}

///getter for username
String User::getUserName()const {
	return userName;
}

///saves information for the user from a file
void saveFromFile(std::istream& is, User& toRead) {
	getline(is, toRead.userName);
	getline(is, toRead.password);
	
}

///saves information for the users in a file
void saveInFile(std::ostream& out, const User& toSave) {
	out << toSave.userName << std::endl;
	out << toSave.password << std::endl;
	
	
}