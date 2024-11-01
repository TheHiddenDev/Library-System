//Class definitions
#ifndef LIBRARY_H
#define LIBRARY_H

#include<vector>
#include<map>
#include<stack>
#include <string>
#include "Book.h"
#include "FileManager.h"

using namespace std;

//Library class manages all the books
class Library {
		//All private instances of the class
	private:
		//Global class varibles
		map<string, vector<Book>> library;
		vector<Book> scifi, romance, history, unsorted;
		string fileDir;

	public:
		//Constructor for when no books exist within the library
		Library() {
			//Initializes variables
			library["Sci-Fi"] = scifi;
			library["Romance"] = romance;
			library["History"] = history;
			library["Unsorted"] = unsorted;
			fileDir = "";
		}

		void setBookName(string name, string bookName) {
			//Goes through all of the catagorys
			for (auto& genre : library) {
				//Goes through all of the books in a catagory, and saves a count for where it is in the list
				int count = 0;
				for (auto& book : genre.second) {
					//Checks if its the right book
					if (book.getName() == bookName) {
						//Sets a book name
						book.setName(name);
						
						//Ends the two for loops
						break;
						break;
					}
				}
			}
		}

		//Sets a book content
		void setBookContent(string content, string bookName) {
			//Goes through all of the catagorys
			for (auto& genre : library) {
				//Goes through all of the books in a catagory, and saves a count for where it is in the list
				for (auto& book : genre.second) {
					//Checks if its the right book
					if (book.getName() == bookName) {
						//Sets a book content
						book.setContent(content);
						
						//Ends the two for loops
						break;
						break;
					}
				}
			}
		}

		//Sets a book author
		void setBookAuthor(string author, string bookName) {
			//Goes through all of the catagorys
			for (auto& genre : library) {
				//Goes through all of the books in a catagory, and saves a count for where it is in the list
				for (auto& book : genre.second) {
					//Checks if its the right book
					if (book.getName() == bookName) {
						//Sets a book author
						book.setAuthor(author);
						
						//Ends the two for loops
						break;
						break;
					}
				}
			}
		}

		//Sets a book catagory
		void setBookCatagory(string catagory, string bookName) {
			//Goes through all of the catagorys
			for (auto& genre : library) {
				//Goes through all of the books in a catagory, and saves a count for where it is in the list
				for (auto& book : genre.second) {
					//Checks if its the right book
					if (book.getName() == bookName) {
						//Sets a book catagory
						book.setCatagory(catagory);
						
						//Ends the two for loops
						break;
						break;
					}
				}
			}
		}

		//Removes a book from the library
		void removeBook(string bookName) {
			//Goes through all of the catagorys
			for (auto& genre : library) {
				//Goes through all of the books in a catagory, and saves a count for where it is in the list
				int count = 0;
				for (auto& book : genre.second) {
					//Checks if its the right book
					if (book.getName() == bookName) {
						//Deletes the element from the vector
						genre.second.erase(genre.second.begin() + count);
						
						//Ends the two for loops
						break;
						break;
					}

					//Adds one to the count
					count++;
				}
			}
		}

		//Adds a book to the library
		void addBook (string content, string name, string author, string catagory) {
			//Checks if the book is within the system already
			if (validBook(name) && name != "back") {
				//If that book name already exits, adds an extra character to the end of it
				name += 1;
			}

			//Checks if the catagory specified for the book exists
			if (validCatagory(catagory)) {
				//Adds the book to the specified catagory
				library[catagory].push_back(Book(content, name, author, catagory));
			} else {
				//The specified catagory did not exist, so it was added to the unsorted file
				library["Unsorted"].push_back(Book(content, name, author, catagory));
			}
		}

		//Gets a book from a catagory
		string getBook(string bookName, string catagory) {
			//Initializing and declaring a variable
			string bookInfo = "";

			//Goes to the specifed catagory, then searches for the book
			for (auto& book : library[catagory]) {
				//Returns true if the book exists
				if (book.getName() == bookName) {
					//Gets the book details
					bookInfo = "Name: " + book.getName() + "\nAuthor: " + book.getAuthor() + "\nContent: '" + book.getContent() + "'";
					break;
				}
			}

			//Returns the books info
			return bookInfo;
		}

		//Gets a book from a catagory
		string getBook(string bookName) {
			//Initializing and declaring a variable
			string bookInfo = "";
			for (auto& genre : library) {
				//Goes to the specifed catagory, then searches for the book
				for (auto& book : genre.second) {
					//Returns true if the book exists
					if (book.getName() == bookName) {
						//Gets the book details
						bookInfo = "Name: " + book.getName() + "\nAuthor: " + book.getAuthor() + "\nContent: '" + book.getContent() + "'";
						
						//Ends the two for loops
						break;
						break;
					}
				}
			}

			//Returns the books info
			return bookInfo;
		}

		//Checks if a book exists with the system
		bool validBook(string bookToFind, string catagory) {
			//Linear search for the book
			for (auto& book : library[catagory]) {
				//Returns true if the book exists
				if (book.getName() == bookToFind) {
					return true;
				}
			}

			//Returns false that it does not exist
			return false;
		}

		//Checks if a book exists with the system
		bool validBook(string bookToFind) {
			//Linear search for the book
			for (auto& genre : library) {
				for (auto& book : genre.second) {
					//Returns true if the book exists
					if (book.getName() == bookToFind) {
						return true;
					}
				}
			}

			//Returns false that it does not exist
			return false;
		}

		//Gets a list of all the books
		string getBooklist() {
			//Declares and initializes a variable
			string bookData = "";

			//Goes through all of the catagorys
			for (auto& genre : library) {
				//Goes through all of the books in a catagory
				for (auto& book : genre.second) {
					//Gets the books info from that catagory
					bookData += book.getName() + " : " + book.getAuthor() + "\n";
				}
			}

			//Returns the gathered data about the specified book
			return bookData;
		}

		string getBooklist(string catagory) {
			//Declares and initializes the variable
			string bookData = "";

			//Goes through all of the books within the catagory
			for (auto& book : library[catagory]) {
				bookData += book.getName() + " : " + book.getAuthor() + "\n";
			}

			//Returns the gathered data about a specified book
			return bookData;
		}

		//Checks if a catagory exists with the map
		bool validCatagory(string location) {
			//Checks how many instances of that location exist with the map
			if (library.count(location) > 0) {
				//returns true if its a valid location
				if (library[location].size() > 0) {
					return true;
				}
			}

			//Otherwiese returns false
			return false;
		}

		//Prints all of the catagorys
		string getCatagorys() {
			//Initalizes and declares catagorys
			string catagorys = "";

			//For each catagory, gets the catagory name and the number of books it has
			for (auto& genre : library) {
				//Gets each catagory and the number of books it has
				catagorys += genre.first + "[" + to_string(genre.second.size()) + "]\n";
			}

			//Returns all of the catagorys and the number of books each one has
			return catagorys;
		}

		//Gets all the books from a .txt file, then sorts, and adds them to its respective catagory
		void getBooks() {
			//Gets the books from the file, and places it into a stack
			FileManager file(fileDir);
			stack<Book*> bookPile = file.processFile();
			
			//Populates the library book stack
			while(!bookPile.empty()) {
				//Gets the catagory of the top book of the stack
				Book *book = bookPile.top();
				string catagory = book->getCatagory();

				//Checks if the books catagory exists within the map
				if (library.find(catagory) != library.end()) {

					//If the book exists within the map, adds it to its respective catagory
					library[catagory].push_back(*book);

					//If the book does not exist in the map, adds it to the unsorted list
				} else {
					library["Unsorted"].push_back(*book);
				}

				//Removes the top Book of the stack as its been read
				bookPile.pop();
			}
		}

		//Validates if a file is valid or not
		bool validFile(string dir) {
			//Sets the file dir
			setFileDir(dir);

			//Uses the file checker within the file manager
			return FileManager::validFile(dir);
		}

		//Creates a .txt file using the FileManager
		void createFileDir(string dir) {
			//Sets the file dir
			setFileDir(dir);

			//Uses the file manager to create a new .txt doc
			FileManager::createFile(dir);
		}

		//Sets the librarys file dir
		void setFileDir (string dir) {
			fileDir = dir;
		}

		//Returns the librarys file dir
		string getFileDir () {
			return fileDir;
		}

		//Returns the number of books in the library statistically
		string getLibrarySize() {
			int numBooks = 0;
			string stats = "";

			for (auto& genre : library) {
				numBooks += genre.second.size();
				stats += genre.first + ": " + to_string(genre.second.size()) + "\n";
			}

			return "Library Details: \nTotal number of Books: " + to_string(numBooks) + "\n\n" + stats;
		}

		//When the file closes, the books will be saved to file
		~Library() {
			//Stack of the books with the library
			stack<Book*> bookPile;

			//Populates the library book stack
			for (auto& genre : library) {
				for (auto& book : genre.second) {
					bookPile.push(&book);
				}
			}

			//Calls on the file manager to save the books within the stack to a .txt file
			FileManager file(bookPile, fileDir);
		}
};

#endif