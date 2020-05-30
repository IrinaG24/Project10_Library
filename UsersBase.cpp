#include "UsersBase.h"
#include<iostream>

///copies data 
void UsersBase::copyData(const UsersBase& other) {
	try {
		users = new User[other.capacity];
	}
	catch (...) {
		std::cerr << "Allocation failed!" << std::endl;
		return;
	}
	capacity = other.capacity;
	numberOfUsers = other.numberOfUsers;
	for (int i = 0; i < numberOfUsers; i++)
		users[i] = other.users[i];
}

void UsersBase::deleteData() {
	delete[] users;
}

///doubles the capacity for the array
void UsersBase::resize() {
	User* temp;
	try {
		temp = new User[capacity*2];
	}
	catch (...) {
		std::cerr << "Allocation failed!" << std::endl;
		return;
	}
	capacity *= 2;
	for (int i = 0; i < numberOfUsers; i++)
		temp[i] = users[i];

	delete[]users;
	users = temp;
}

///constructor
UsersBase::UsersBase(int capacity) {
	try {
		users = new User[capacity];
	}
	catch (...) {
		std::cerr << "Allocation failed!" << std::endl;
		return;
	}
	this->capacity = capacity;
	numberOfUsers = 0;
}

///copy constructor
UsersBase::UsersBase(const UsersBase& other) {
	copyData(other);
}

///predefinition operator =
UsersBase& UsersBase:: operator=(const UsersBase& other) {
	if (this != &other) {
		deleteData();
		copyData(other);
	}
	return* this;
}

///destructor
UsersBase::~UsersBase() {
	deleteData();
}

///adds user in the array
void UsersBase::userAdd(const User& toAdd) {
	if (capacity == numberOfUsers) resize();
	users[numberOfUsers].operator=(toAdd);
	numberOfUsers++;
}

///removes user from the array
void UsersBase::userRemove(const User& toRemove) {
	int indexToFind = 0;
	for (int i = 0; i < numberOfUsers; i++) {
		if (users[i] == toRemove) {
			indexToFind = i;
			break;
		}
	}

	User* temp;
	try {
		temp = new User[capacity];
	}
	catch (...) {
		std::cerr << "Allocation failed!" << std::endl;
		return;
	}
	
	for (int i = 0; i < indexToFind; i++)
		temp[i] = users[i];

	for (int i = indexToFind + 1; i < numberOfUsers; i++)
		temp[i - 1] = users[i];

	delete[] users;
	users = temp;
	numberOfUsers--;
}


///gets size of the array
int UsersBase::getNumberOfUsers()const {
	return numberOfUsers;
}

///checks if a users from the array is logged in
bool UsersBase::isThereLoggedUser()const {
	for (int i = 0; i < numberOfUsers; i++) {
		if (users[i].isLogged() == true) return true;
	}
	return false;
}


///predefinition operator[]
User& UsersBase::operator[](const int index) {
	return users[index];
}

const User& UsersBase::operator[](const int index)const {
	return users[index];
}

