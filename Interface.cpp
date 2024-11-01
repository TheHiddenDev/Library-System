//Code declarations
#include <iostream>
#include <stdexcept>
#include <string>
#include "Library.h"
using namespace std;

//Function instanciations
int getInt (string msg);
void getMenu();
void readByCatagory();
void readByAll();
void removeBook();
void addBook();
void editBook();

//Declaring global variables
Library lib;

//Main method
int main () {
	//Welcome message to the user
	cout << "Welcome to the Algonquin Library" << endl << endl;

	//Prompt to the user
	cout << "Please select one of the following options: " << endl << "1 - Import Library from File" << endl << "2 - Create a new library" << endl;

	//Declares and instanciates choice
	int choice = -1;

	//Inf loop until the user enters one of the correct options
	while ((choice != 1) && (choice != 2)) {
		//Gets the users choice
		cout << endl << "Choice: ";

		//Validates user input
		choice = getInt("Invalid Value. \n\nChoice: ");
	}

	//Impliments the choice made by the user
	//Import the library data from a text file
	if (choice == 1) {
		//Output message to the user to get the file director
		cout << endl << "Please enter the file name of the file to import (Eg. Text.txt)" << endl;

		//Variable for the directory
		string dir = "";

		//Inf loop until a correct file is entered
		while (1) {
			//Gets the users choice
			cout << "Dir: ";

			//Variable for the directory
			getline(cin, dir);

			//Checks if the user wants to make a new file instead of loading one
			if (lib.validFile(dir)) {
				break;
			} else {
				cout << "Invalid Directory. \n";
			}

		}

		//Imports the books from the file
		lib.getBooks();

		//Creates a text file with the given name from the user
	} else {
		//Out message to the user
		cout << endl << "Please enter the file directory you wish to save the library to. Eg(library) DO NOT add the .txt to the end of the file name entered" << endl << "Dir: ";

		//Gets the file dir, then creates a text file with that name
		string dir = "";
		getline(cin, dir);
		lib.createFileDir(dir + ".txt");
	}

	//Outputs the library statistics
	cout << endl << lib.getLibrarySize() << endl << endl;
	choice = 5;

	//loop to control browsing the library
	while (choice != -1) {
		//Clears the terminal screen
		system("CLS");
		//Prints the librarys menu
		getMenu();
	
		//Gets the users choice
		cout << endl << "Choice: ";
		choice = getInt("Invalid Value. Choice: ");
		
		//Clears the terminal screen
		system("CLS");
		switch (choice) {
			case 1:
				//Lets the user browse the books by the catagory
				readByCatagory();
				break;
			case 2:
				//Lets the user view ALL of the books
				readByAll();
				break;
			case 3:
				//Lets the user remove books
				removeBook();
				break;
			case 4:
				//Adds a book to the library
				addBook();
				break;
			case 5:
				//Lets a user edit a book
				editBook();
				break;
			default:
				//If none of the other options are entered, the menu is re-printed
				if (choice != -1) {
					//Prints the librarys menu
					getMenu();
				}
				break;
		}

	}

	//Message at the end of the program
	cout << "Thanks for using the Library :)";
	lib.~Library();
	
	return 0;
}

//Allowed the user to edit a book
void editBook() {
	//Outputs the purpose
	cout << "Book Editor!:" << endl;
	
	//Initializes and declares variables
	string book = "", temp = "";
	
	//Gets and validates that the book exists
	cout << "If you do not wish to edit a section of the book, type skip\n\nBook Name: ";
	
	//Validates that a valid catagory has been choosen.
	while (getline(cin, book) && book!= "exit" && !lib.validBook(book)) {
		cout << "Not within system. \n\nBook Name: ";
	}

	
	cout << "Name:";
	getline(cin, temp);
	
	if (temp != "skip") {
		lib.setBookName(temp,  book);
	}

	cout << "Author:";
	getline(cin, temp);
	
	if (temp != "skip") {
		lib.setBookAuthor(temp, book);
	}

	cout << "Catagory:";
	getline(cin, temp);
	
	if (temp != "skip") {
		lib.setBookCatagory(temp, book);
	}

	cout << "Content:";
	getline(cin, temp);
	
	if (temp != "skip") {
		lib.setBookContent(temp, book);
	}
}


//Prints the menu
void getMenu() {
	cout << "Library Options" << endl
	     << "1 - Browse Books by Catagory" << endl
	     << "2 - Browse All Books" << endl
	     << "3 - Remove a book from library" << endl
	     << "4 - Add a book to the library" << endl
	     << "5 - Edit a Book" << endl
	     << "-1 - To exit" << endl;
}


//Removes a book from the library
void removeBook() {
	//Outputs the purpose
	cout << "Book Deletion!:" << endl;

	//Initializes and declares variables
	string book = "";

	//Gets and validates that the book exists
	cout << "Book Name: ";
	//Validates that a valid catagory has been choosen.
	while (getline(cin, book) && book!= "exit" && !lib.validBook(book)) {
		cout << "Not within system. \n\nBook Name: ";
	}

	//Removes Book, and gives a message to the user
	lib.removeBook(book);
	cout << book + " has been removed from the library" << endl;
}


//Adds a book to the library
void addBook() {
	//Outputs the function purpose
	cout << "Book Creator!:" << endl << "Enter 'exit' at any point to return to the menu" << endl << endl;

	//Declares and initializes a temp variable
	string content = "", name = "", author = "", catagory = "";

	cout << "Name:";
	getline(cin, name);

	cout << "Author:";
	getline(cin, author);

	cout << "Catagory:";
	getline(cin, catagory);

	cout << "Content:";
	getline(cin, content);
	lib.addBook(content, name, author, catagory);

	cout << endl << "Added '" + name + "' to the system" << endl;
}


//Searches the entire library for a book
void readByAll() {
	//Outputs all of the books
	cout << "Displaying all library books:\n\nFormat: (BookName : Author)" << endl << lib.getBooklist() << endl;

	//Declares and initializes a temp variable
	string book;

	cout << endl << "Please enter the name of the book you wish to read. Type 'back' to return to the menu" << endl;

	while (true) {
		cout << "Book: ";
		//Validates that a valid catagory has been choosen.
		while (getline(cin, book) && book!= "back" && !lib.validBook(book)) {
			cout << "Not within system. \n\nBook: ";
		}

		//Exits the loop
		if (book == "back") {
			break;
		}

		//Displays all of the avalible books
		cout << endl << lib.getBook(book) << endl << endl;
	}

}


//Reads all of the books
void readByCatagory() {
	//Declares and initalizes catagory to hold the users choice
	string catagory = "";

	//Continious loop so long as the user wants to browse the catagorys
	while (1) {
		//Clears the terminal screen
		system("CLS");
		
		//Output message every time the user is back at the catagory list to choose from
		cout << endl << "Avalible Catagorys: (Eg: 'history')" << endl << lib.getCatagorys() << endl << "Type 'exit' to return to the menu" << endl << endl;
		cout << "Catagory To Search: ";

		//Validates that a valid category has been chosen.
		while (getline(cin, catagory) && catagory != "exit" && !lib.validCatagory(catagory)) {
			cout << "Invalid Category. \n\nCategory to search: ";
		}

		//Exits the main loop
		if (catagory == "exit") {
			break;
		}

		//Outputs the book list
		cout << "Format: (BookName : Author)" << endl << lib.getBooklist(catagory) << endl;

		//Declares and initializes a temp variable
		string book;

		cout << endl << "Please enter the name of the book you wish to read. Type 'back' to return to the book catagorys" << endl;

		while (true) {
			cout << "Book: ";
			//Validates that a valid catagory has been choosen.
			while (getline(cin, book) && book!= "back" && !lib.validBook(book, catagory)) {
				cout << "Not within system. \n\nBook: ";
			}

			//Exits the loop
			if (book == "back") {
				break;
			}

			//Displays all of the avalible books
			cout << endl << lib.getBook(book, catagory) << endl << endl;
		}
	}
}


//Gets and validates the entered INTEGER value
int getInt(string msg) {
	//Defining the grade variable, and gets its value
	string varStr;

	int var;
	bool validInput = false;

	//Loops until valid input is entered
	while (!validInput) {
		//Gets user grade as a string
		getline(cin, varStr);

		try {
			//Trys the string to integer function
			var = stoi(varStr);

			//Returns once its valid
			validInput = true;

		} catch (...) {
			//If the above function isnt possible, then error message is outputted
			cout << msg;
		}
	}

	//Returns the int variable
	return var;
}