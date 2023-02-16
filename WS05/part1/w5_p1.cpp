#include <iostream>
#include <iomanip>
#include <fstream>
#include "Book.h"
#include "Book.h"

using namespace sdds;

enum AppErrors
{
	CannotOpenFile = 1, // An input file cannot be opened
	BadArgumentCount = 2, // The application didn't receive enough parameters
};

// ws books.txt
int main(int argc, char** argv)
{
	std::cout << "Command Line:\n";
	std::cout << "--------------------------\n";
	for (int i = 0; i < argc; i++)
		std::cout << std::setw(3) << i + 1 << ": " << argv[i] << '\n';
	std::cout << "--------------------------\n\n";

	// get the books
	sdds::Book library[7];
	if (argc == 2) {
		// TODO: load the collection of books from the file "argv[1]".
		std::ifstream file(argv[1]);
		if (file) {
			std::string bookLine;
			size_t index = 0;
			while (std::getline(file, bookLine) && index < 7) { //       - read one line at a time, and pass it to the Book constructor
				if (bookLine[0] != '#') { //       - lines that start with "#" are considered comments and should be ignored
					library[index] = Book(bookLine); //       - store each book read into the array "library"
					index++;
				}
			}
			file.close();
		}
		else {
			std::cerr << "ERROR: Could not open file [" << argv[1] << "].\n"; //       - if the file cannot be open, print a message to standard error console and
			exit(AppErrors::CannotOpenFile); //                exit from application with error code "AppErrors::CannotOpenFile"
		}
	}
	else {
		std::cerr << "ERROR: Incorrect number of arguments.\n";
		exit(AppErrors::BadArgumentCount);
	}

	double usdToCadRate = 1.3;
	double gbpToCadRate = 1.5;
// TODO: create a lambda expression that fixes the price of a book accoding to the rules
	auto updatePrice = [&](Book& book) { //       - the expression should receive a single parameter of type "Book&"
		if (book.country() == "US") { //       - if the book was published in US, multiply the price with "usdToCadRate"
			book.price() *= usdToCadRate; //            and save the new price in the book object
		}
		else if (book.country() == "UK" && (book.year() >= 1990 && book.year() <= 1999)) { //       - if the book was published in UK between 1990 and 1999 (inclussive),
			book.price() *= gbpToCadRate; //            multiply the price with "gbpToCadRate" and save the new price in the book object
		}
		else if (book.country() == "UK") {
			book.price() *= usdToCadRate;
		}
	};

	std::cout << "-----------------------------------------\n";
	std::cout << "The library content\n";
	std::cout << "-----------------------------------------\n";
	// TODO: iterate over the library and update the price of each book
	//         using the lambda defined above.
	for (auto i = 0u; i < 7u; i++) {
		std::cout << library[i] << std::endl;
	}
	std::cout << "-----------------------------------------\n\n";

	for (auto i = 0u; i < 7u; i++) {
		updatePrice(library[i]);
	}

	std::cout << "-----------------------------------------\n";
	std::cout << "The library content (updated prices)\n";
	std::cout << "-----------------------------------------\n";
	// TODO: iterate over the library and print each book to the screen
	for (auto i = 0u; i < 7u; i++) {
		std::cout << library[i] << std::endl;
	}
	std::cout << "-----------------------------------------\n";

	return 0;
}