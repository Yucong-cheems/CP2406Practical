module;
#include <iostream>
export module Database;
import Database;
import person_database;

using namespace std;

int main()
{
	// Fill a database.
	Database db;
    try {
        // Fill a database.
        db.add(Person{ "John", "Doe" });
        db.add(Person{ "Marc", "Gregoire", "Mg" });
        db.add(Person{ "Peter", "Van Weert", "PVW" });

        // Output all persons in the database to standard output.
        cout << "Initial database contents:" << endl;
        db.outputAll(cout);

        // Save the database to a file.
        db.save("person.db");
        cout << "Database saved successfully." << endl;

        // Clear the database.
        db.clear();
        cout << "\nDatabase contents after clearing:" << endl;
        db.outputAll(cout);
        
        // Load database from file.
        cout << "\nLoading database from file..." << endl;
        db.load("person.db");
        cout << "\nDatabase contents after loading from file:" << endl;
        db.outputAll(cout);
    } catch (const std::exception& e) {
        cerr << "An error occurred: " << e.what() << endl;
    }
}
