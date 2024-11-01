//Class instanciations
#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <string>
#include <stack>
#include <stdexcept>
#include <fstream>
#include <iostream>
#include "Book.h"

using namespace std;

//This class manages reading and writing to a file
class FileManager {

		//Private Class members
	private:
		//Declaring stack used in program
		stack<Book*> bookPile;

		//Sets the file system data
		string fileDir;

		//Public Class members
	public:
		//Constructor used to read the file
		FileManager(string fileDir) {
			//Initilizes the variable
			this->fileDir = fileDir;
		}

		//Constructor used to save to the file
		FileManager(stack<Book*> &bookPile, string fileDir) {
			//Initializes the variables
			this->bookPile = bookPile;
			this->fileDir = fileDir;

			//Calls on the function to save it to the file
			saveBooks();
		}

		//Converts a binary value to its respective 1 and 0 values in string form
		string boolToString(bool val) {
			if (val) {
				return "1";
			} else {
				return "0";
			}
		}

		//Trys to load content from a file and store it in a stack
		stack<Book*> processFile() {
			try {
				//Opens the text file containing books
				ifstream bookFile(fileDir);

				//Checks that the file is open before reading it
				if (bookFile.is_open()) {
					readingBooks(bookFile, bookPile);

					//Closes the file
					bookFile.close();
				}

				//Catches any errors that may occur
			} catch (runtime_error &e) {
				cout << e.what() << endl;
			}

			//Returns the books received from the text file
			return bookPile;
		}

		//Gets the books from the text file
		void readingBooks(ifstream &file, stack<Book*> &bookList) {
			//Initalizes and declares variables
			string content = "", name = "", author = "", tempCheckedOut = "", catagory = "";
			bool isCheckedOut = false;

			while (file.peek() != EOF) {
				//Takes in 5 lines of the txt file at a time, and placing it in its respective locations
				getline(file, content);
				getline(file, name);
				getline(file, author);
				getline(file, tempCheckedOut);
				getline(file, catagory);
				isCheckedOut = (tempCheckedOut == "1") ? true : false;

				// Create a new Book object with the extracted information and push it onto the bookList stack
				bookList.push(new Book(content, name, author, isCheckedOut, catagory));
			}
		}

		//Attempts to save all the books to the file
		void saveBooks() {
			try {
				//Opens the file output system, clears all data on the file, and then opens the file.
				ofstream bookFile;
				bookFile.open(fileDir);

				if (bookFile.is_open()) {
					//Clears the contents of the time
					bookFile.clear();

					//Trys to save the data to the file
					saveToFile(bookFile, bookPile);

					//Closes the file
					bookFile.close();
				}

				//Catches any errors that may occur
			} catch (runtime_error &e) {
				cout << e.what() << endl;
			}
		}

		//Saves the books to file
		void saveToFile(ofstream &file, stack<Book*> &bookList) {
			//While the booklist has books, it adds books to the file
			while (!bookList.empty()) {
				//Gets the book at the top of the stack
				Book *b = bookList.top();

				//Writes the books contents to the file, each type of book info is on a new line
				file << b->getContent() << endl << b->getName() << endl << b->getAuthor() << endl << boolToString(b->isBookCheckedOut()) << endl << b->getCatagory() << endl;

				//Removes the book just written to the file from the stack
				bookList.pop();
				
				//Unalocated the memeory used by the book
				b->~Book();
			}
		}

		//Checks if the given file is valid
		static bool validFile (string dir) {
			//Creates the input stream for the file
			ifstream file(dir);
			bool status = file.good();
			file.close();
			//Returns if the file is valid or not
			return status;
		}

		//Creates a .txt file
		static void createFile (string dir) {
			//Creates the output stream to create the file
			ofstream file(dir);
		}

		//Class Destructor
		~FileManager() {}
};

#endif