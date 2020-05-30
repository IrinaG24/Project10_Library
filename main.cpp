#include<iostream>
#include<iomanip>
#include<fstream>
#include "String.h"
#include "Book.h"
#include "BooksStorage.h"
#include "User.h"
#include "UsersBase.h"
#include "Library.h"

using namespace std;
int main() {
	
	Library base;
	String command, booksReadFrom;

	for (;;) {
		cout << ">";
		cin >> command;
		if (command == "exit") {
			cout << "Exiting the program...\n";
			return 0;
		}
		else if (command == "help") {
			cout << "The following commands are supported:\n";
			cout << "open <file> " << setw(20) << "opens<file>\n";
			cout << "close " << setw(47) << "closes the currently opened file\n";
			cout << "save " << setw(47) << "saves the currently opened file\n";
			cout << "saveas <file> " << setw(48) << "saves the currently opened file in <file>\n";
			cout << "help " << setw(39) << "prints this information\n";
			cout << "exit " << setw(33) << "exits the program\n";
		}
		else if (command == "open") {

			String fileToOpen;
			cin >> fileToOpen;

			///convert string into char*
			int n = fileToOpen.Size();
			char* toOpen = new char[n+ 1];
			for (int i = 0; i < n; i++) toOpen[i] = fileToOpen[i];
			toOpen[n ] = '\0';

			base.open(toOpen);
			booksReadFrom = fileToOpen; /// booksReadFrom holds from which file are the books saved
										///this will be used when save is written
			

		}
		else if (command == "close") {
			base.close();
			cout << "Successfully closed " << booksReadFrom << "!\n";
		}
		else if (command == "save") {
			int n = booksReadFrom.Size();
			char* toOpen = new char[n + 1];
			for (int i = 0; i < n; i++) toOpen[i] = booksReadFrom[i];
			toOpen[n] = '\0';
			base.save(toOpen);
		}
		else if (command == "saveas") {
			String newFile;
			cin >> newFile;
			int n = newFile.Size();
			char* toOpen = new char[n + 1];
			for (int i = 0; i < n; i++) toOpen[i] = newFile[i];
			toOpen[n] = '\0';
			base.saveas(toOpen);
		}
		else if (command == "login") {
			String username, password;
			cout << "username: ";
			cin >> username;
			cout << "password: ";
			cin >> password;
			User toLogin(username, password, 1);
			base.logIn(toLogin);
			
		}
		else if (command == "logout") {
			base.logOut();
		}
		else if (command == "books") {
			String nextCommand;
			cin >> nextCommand;
			if (nextCommand == "all") {
				base.booksAll();
			}
			else if (nextCommand == "find") {
				String option, toSearch;
				cin >> option;
				getline(cin, toSearch);
				base.booksFind(option, toSearch);
			}
			else if (nextCommand == "sort") {
				String option, howToSort;
				getline(cin, option);
				cout << option << endl;
				base.booksSort(option);

			}
			else if (nextCommand == "info") {
				int idToFind;
				cin >> idToFind;
				base.booksInfo(idToFind);

			}
			else if (nextCommand == "add") {
				Book newBook;
				cin >> newBook;
				base.booksAdd(newBook);

			}
			else if (nextCommand == "remove") {
				int index;
				cout << "ID to look for and remove: ";
				cin >> index;
				base.booksRemove(index);

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
				User add(username, password, 1);
				base.usersAdd(add);
			}
			else if (nextCommand == "remove") {
				String userToRemove;
				cin >> userToRemove;
				base.usersRemove(userToRemove);
			}
		}
		else
		{
				cout << "Wrong command!\n";
		}
	}
	return 0;


}