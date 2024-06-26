#ifndef DATABASE_H
#define DATABASE_H

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include "Person.h"
#include <iomanip>

class Database
{
public:
	// Adds the given person to the database.
	void add(Person person);

	// Removes all persons from the database.
	void clear();

	// Saves all persons in the database to the given file.
	void save(std::string_view filename) const;

	// Loads all persons from the given file and stores them in the database.
	void load(std::string_view filename);

	// Outputs all persons to the given stream.
	void outputAll(std::ostream& output) const;

private:
	std::vector<Person> m_persons;
};

#endif // DATABASE_H