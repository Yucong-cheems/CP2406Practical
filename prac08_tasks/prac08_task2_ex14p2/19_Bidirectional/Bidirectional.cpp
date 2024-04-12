#include <iostream>
#include <fstream>
#include <string>
#include <string_view>

using namespace std;

// Returns false on error
void changeNumberForID(string_view filename, int id, string_view newNumber);

int main()
{
	try {
        changeNumberForID("data.txt", 263, "415-555-3333");
    } 
	catch (const runtime_error& e) {
        cerr << "Runtime error: " << e.what() << endl;
    } 
	catch (const exception& e) {
        cerr << "Other error: " << e.what() << endl;
    }
}

void changeNumberForID(string_view filename, int id, string_view newNumber)
{
	fstream ioData{ filename.data(), ios::in | ios::out };
    if (!ioData) {
        throw runtime_error("Error while opening file");
    }

	bool found = false;
	// Loop until the end of file
	while (ioData) {
		// Read the next ID.
		int idRead;
		ioData >> idRead;
		if (!ioData)
			break;

		// Check to see if the current record is the one being changed.
		if (idRead == id) {
			// Seek the write position to the current read position.
			ioData.seekp(ioData.tellg());
			// Output a space, then the new number.
			ioData << " " << newNumber;
			break;
		}

		// Read the current number to advance the stream.
		string number;
		ioData >> number;
	}
	if (!found) {
        throw runtime_error("ID not found in file.");
    }
}