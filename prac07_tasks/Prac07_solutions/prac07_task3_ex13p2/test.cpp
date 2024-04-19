#include <iostream>
#include <sstream>
#include <fstream>
#include "Person.h"

using namespace std;

int main()
{
	Person person{ "John", "Doe" };

	// Write person to standard output console.
	cout << person.output() << endl;

	// Write person to a string stream.
	ostringstream oss;
	oss << person.output();
	// Verify the contents of the string stream.
	cout << oss.str() << endl;

	// Write person to a file.
	ofstream outFile{ "person.txt" };
	outFile << person.output();
}
