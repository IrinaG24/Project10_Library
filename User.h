#ifndef USERS_H_
#define USERS_H_
#include "String.h"

class User {
private:
	String userName;
	String password;
	int level; 
	bool logged;
public:
	User();
	User(String, String, int);

	bool operator==(const User&) const;
	bool isLogged()const;

	void setLogged(bool);
	String getUserName()const;



};
#endif
