#ifndef USERSBASE_H_
#define USERSBASE_H_

#include "User.h"

class UsersBase {
private: 
	User* users;
	int capacity;
	int numberOfUsers;

	void copyData(const UsersBase&);
	void deleteData();
	void resize();
public:
	UsersBase(int = 1);
	UsersBase(const UsersBase&);
	UsersBase& operator=(const UsersBase&);
	~UsersBase();

	void userAdd(const User&);
	void userRemove(const User&);

	int getNumberOfUsers()const;

	bool isThereLoggedUser()const;
	
	User& operator[](const int);

	const User& operator[](const int index)const;

};

#endif 