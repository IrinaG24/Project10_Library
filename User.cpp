#include "User.h"

User::User() {
	userName = "";
	password = "";
	level = 1;
	logged = false;
}

User::User(String userName_, String password_, int level_) {
	userName = userName_;
	password = password_;
	level = level_;
}

bool User::operator==(const User& other) const {
	if (userName == other.userName && password==other.password) return true;
	else return false;
}


bool User::isLogged()const {
	if (logged == true) return true;
	else return false;
}

bool User::isAdministrator()const {
	if (level == 2) return true;
	else return false;
}

void User::setLogged(bool status) {
	logged = status;
}

String User::getUserName()const {
	return userName;
}
