#ifndef USERS_H_
#define USERS_H_
#include "String.h"

class User {
private:
	String userName;
	String password;
	int level;  // 1 is for ordinary user, 2 - admin
	bool logged;
public:
	User();
	User(String, String, int);

	bool operator==(const User&) const;

	bool isLogged()const;
	bool isAdministrator()const;

	void setLogged(bool);
	void setLevel(int l) {
		level = l;
	}
	String getUserName()const;

	friend void saveFromFile(std::istream&, User&);
	
	friend void saveInFile(std::ostream&, const User&);


};
#endif
