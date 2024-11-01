# This library system serves as the final term project for the Algonquin College Advanced Programming and Data Structures course. As a requirement of the curriculum, it incorporates a variety of programming techniques, which may result in some elements of code that appear unnecessary. For example, multiple container types have been utilized throughout the implementation.


## Interface.cpp**
### Overview:
Interface.cpp provides a console-based user interface for managing a library system. This class initializes a Library object and facilitates user interactions by offering various functionalities to import, create, view, edit, and manage books within the library.

### Features:
  -Import Library from File: Load books from an existing file.
  -Create New Library: Start a fresh library and save it to a specified file.
  -Browse by Category: View books categorized for easier access.
  -View All Books: Display a list of all available books.
  -Add a Book: Introduce new books to the library.
  -Edit a Book: Modify the details of existing books.
  -Remove a Book: Delete books from the library.

### Usage:
  -Compile the Code: Ensure you have the necessary environment to compile C++ code.
  -Run the Application: Execute the compiled binary to launch the library interface.
  -Follow the Prompts: Choose options by entering the corresponding number and follow the on-screen instructions to interact with the library system.

### Code Structure:
  -Main Function: Handles user input and controls the flow of the application.
  -Menu Functions: Provide options for various library management tasks.
  -Validation Functions: Ensure user inputs are valid and prevent errors.

## Library.h
Overview:
The Library class is responsible for managing the collection of books within the library system. It organizes books into categories, handles book metadata (like name, author, content, and category), and provides various functionalities for adding, removing, and retrieving books.

### Features:
  -Book Management: Add, remove, edit, and retrieve books from various categories.
  -Category Organization: Manage books within predefined categories such as Sci-Fi, Romance, History, and an Unsorted category for uncategorized books.
  -File Operations: Load books from a text file and save the library's state to a file.
  -Validation: Check the existence of books and categories.

### Code Structure:
  **Private Members**:
    -A map to hold categories and their respective books.
    -Vectors to manage specific genres and a string for the file directory.
  **Public Methods**:
    -Constructors and destructors for initializing and saving the library state.
    -Methods for adding, removing, and editing book attributes.
    -Methods to validate books and categories.
    -Methods for loading books from a file and saving the library state.

## Book.h
### Overview:
The Book class represents an individual book within the library system. It encapsulates essential attributes such as content, name, author, category, and checkout status. This class provides methods for accessing and modifying these attributes, making it an integral part of the library management system.

### Features:
  -Attributes: Stores book details, including content, name, author, category, and whether the book is checked out.
  -Constructors: Supports multiple ways to instantiate a Book object.
  -Accessors and Mutators: Provides methods to get and set the book's attributes.

### Code Structure:
  **Private Members:**
    -string content: The content of the book.
    -string name: The title of the book.
    -string author: The author of the book.
    -string category: The category to which the book belongs.
    -bool isCheckedOut: Indicates if the book is currently checked out.
  **Public Methods:**
    -Constructors for initializing a book.
    -Methods to check and update the checkout status.
    -Getters and setters for book attributes.

## FileManager.h
### Overview:
The FileManager class is responsible for handling file operations related to books in the library system. It provides functionalities to read book data from a file and save book data back to a file. The class utilizes a stack to temporarily hold book objects while reading and writing.

### Features:
  -File Operations: Load and save book data to and from a specified file.
  -Error Handling: Robust error handling for file operations.
  -Static Utility Methods: Methods to validate files and create new files.

### Code Structure:
  **Private Members:**
    -stack<Book*> bookPile: A stack that stores pointers to Book objects.
    -string fileDir: The directory path of the file to be managed.
  **Public Methods:**
    -Constructors for reading and saving to files.
    -Methods for processing files, converting boolean values, and managing file validity.
