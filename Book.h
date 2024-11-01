//Class definitions
#ifndef BOOK_H
#define BOOK_H

#include <string>

using namespace std;

//Book Class
class Book {
	//Private class members
	private:
		//Constants
		string content;
		string name;
		string author;
		string catagory;
		bool isCheckedOut;

	//Public class members
	public:
		//Main constructor
		Book (string content, string name, string author, string catagory) {
			//Initializes variables
			this->content = content;
			this->name = name;
			this->author = author;
			this->catagory = catagory;
			isCheckedOut = false;
		}

		//Secondard Constructor
		Book(string content, string name, string author, bool isCheckedOut, string catagory) {
			//Initializes variables
			this->content = content;
			this->name = name;
			this->author = author;
			this->catagory = catagory;
			this->isCheckedOut = isCheckedOut;
		}

		//Checks if the book is checke out
		bool isBookCheckedOut() {
			return isCheckedOut;
		}

		//Sets if the book is checked out or not
		void setChecking (bool isCheckedOut) {
			this->isCheckedOut = isCheckedOut;
		}

		//Returns the name of the book
		string getName () {
			return name;
		}

		//Sets the new name of the book
		void setName (string name) {
			this->name = name;
		}

		//Gets the content of the book
		string getContent () {
			return content;
		}

		//Sets thenew content of the book
		void setContent (string content) {
			this->content = content;
		}

		//Returns the authors name
		string getAuthor () {
			return author;
		}

		//Sets the new authors name
		void setAuthor (string author) {
			this->author = author;
		}

		//Returns the catagory name
		string getCatagory () {
			return catagory;
		}

		//Sets the new catagory name
		void setCatagory (string catagory) {
			this->catagory = catagory;
		}
		
		//Class Destructor
		~Book() {}
};

#endif