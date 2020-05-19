#include<iostream>
#include<iomanip>
#include<fstream>
#include "String.h"
#include "Book.h"
#include "BooksStorage.h"
#include "User.h"
#include "UsersBase.h"

using namespace std;
int main() {

	String command;
	UsersBase registeredUsers;
	BooksStorage library;

	for (;;) {
		cout << ">";
		cin >> command;
		if (command == "exit") {
			cout << "Exiting the program...\n";
			return 0;
		}
		else if (command == "help") {
			cout << "The following commands are supported:\n";
			cout << "open <file> "<<setw(20)<<"opens<file>\n";
			cout << "close " << setw(47) << "closes the currently opened file\n";
			cout << "save " << setw(47) << "saves the currently opened file\n";
			cout << "saveas <file> " << setw(48) << "saves the currently opened file in <file>\n";
			cout << "help " << setw(39) << "prints this information\n";
			cout << "exit " << setw(33) << "exits the program\n";
		}
		else if (command == "open") {

		}
		else if (command == "close") {

		}
		else if (command == "save") {

		}
		else if (command == "saveas") {

		}
		else if (command == "login") {
			String username, password;
			cout << "username: ";
			cin >> username;
			cout << "password: ";
			cin >> password;
			User toLogin(username, password, 1);
			for (int i = 0; i < registeredUsers.getNumberOfUsers(); i++) {

				if (!(toLogin == registeredUsers[i]) && registeredUsers[i].isLogged() == true) {
					cout << "Another user is logged in!\n";
					break;
				}
				else if (toLogin == registeredUsers[i]) {
					if (registeredUsers[i].isLogged() == true) {
						cout << "You are already logged in!\n";
						break;
					}
					else {
						registeredUsers[i].setLogged(true);
						cout << "Welcome, " << username << "!" << endl;
						break;
					}
				}
				else {
					cout << "Wrong username or password!\n";
				}
			}
		}
		else if (command == "logout") {
			if (registeredUsers.isThereLoggedUser() == true) {
				for (int i = 0; i < registeredUsers.getNumberOfUsers(); i++) {
					if (registeredUsers[i].isLogged() == true) {
						registeredUsers[i].setLogged(false);
						cout << "User logged out!\n";
						break;
					}
				}
			}
			else cout << "There is no logged in user!\n";
		}
		else if (command == "books") {
			String nextCommand;
			cin >> nextCommand;
			if (nextCommand == "all") {
				if (registeredUsers.isThereLoggedUser() == true) {
					library.booksPrint();
				}
				else cout << "User must be logged in!\n";
			}
			else if (nextCommand == "find") {
				String option, toSearch;
				cin >> option;
				getline(cin, toSearch);
				if (registeredUsers.isThereLoggedUser() == true) {
					library.findBook(option, toSearch);
				}
				else cout << "User must be logged in!\n";
			}
			else if (nextCommand == "sort") {
				String option;
				cin >> option;
				String howToSort;
				cin >> howToSort;
				if (registeredUsers.isThereLoggedUser() == true) {
				}
				else cout << "User must be logged in!\n";

			}
			else if (nextCommand == "info") {
				int idToFind;
				cin >> idToFind;
				if (registeredUsers.isThereLoggedUser() == true) {
					for (int i = 0; i < library.getNumberOfBooks(); i++) {
						if (library[i].getID() == idToFind) {
							library[i].bookDetailedInfo();
						}
					}
				}
				else cout << "User must be logged in!\n";

			}
			else if (nextCommand == "add") {

			}
			else if (nextCommand == "remove") {

			}
			
		}
		else if (command == "users") {
			String nextCommand;
			cin >> nextCommand;
			if (nextCommand == "add") {
				String username, password;
				int flag = 0;
				cin >> username;
				cin >> password;
				for (int i = 0; i < registeredUsers.getNumberOfUsers(); i++) {
					if (registeredUsers[i].isAdministrator() && registeredUsers[i].isLogged()) {
						flag = 1;
						registeredUsers.userAdd(User(username, password, 1));
						//zapishi vuv faila
						break;
					}
				}
				if (flag == 0) cout << "Logged Administrator is needed!\n";
			}
			else if (nextCommand == "remove") {
				String userToRemove;
				cin >> userToRemove;
				int flag = 0;
				for (int i = 0; i < registeredUsers.getNumberOfUsers(); i++) {
					if (registeredUsers[i].isAdministrator() && registeredUsers[i].isLogged()) {
						flag = 1;
						break;
					}
				}
				if (flag == 1) {
					for (int i = 0; i < registeredUsers.getNumberOfUsers(); i++) {
						if (registeredUsers[i].getUserName() == userToRemove) {
							flag = i;
						}
					}
					registeredUsers.userRemove(registeredUsers[flag]);
					//mahni ot faila
					flag = 1;
				}else cout << "Logged Administrator is needed!\n";

			}
		}
	}
	return 0;


}