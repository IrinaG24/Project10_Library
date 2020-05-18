#include "UsersBase.h"
#include<iostream>

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

UsersBase::UsersBase(const UsersBase& other) {
	copyData(other);
}
UsersBase& UsersBase:: operator=(const UsersBase& other) {
	if (this != &other) {
		deleteData();
		copyData(other);
	}
	return* this;
}

UsersBase::~UsersBase() {
	deleteData();
}

void UsersBase::userAdd(const User& toAdd) {
	if (capacity == numberOfUsers) resize();
	users[numberOfUsers].operator=(toAdd);
	numberOfUsers++;
}
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