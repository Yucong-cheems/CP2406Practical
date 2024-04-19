#include <string>
#include <sstream>

class Person
{
public:
	// Two-parameter constructor automatically creates initials and
	// delegates the work to the three-parameter constructor.
	Person::Person(std::string firstName, std::string lastName)
    : Person(std::move(firstName), std::move(lastName),
             std::string(1, firstName[0]) + std::string(1, lastName[0])) {}

	Person() = default;

	Person(std::string firstName, std::string lastName, std::string initials)
		: m_firstName{ std::move(firstName) }
		, m_lastName{ std::move(lastName) }
		, m_initials{ std::move(initials) }
	{
	}

	const std::string& getFirstName() const { return m_firstName; }
	void setFirstName(std::string firstName) { m_firstName = std::move(firstName); }

	const std::string& getLastName() const { return m_lastName; }
	void setLastName(std::string lastName) { m_lastName = std::move(lastName); }

	const std::string& getInitials() const { return m_initials; }
	void setInitials(std::string initials) { m_initials = std::move(initials); }

	std::string Person::output() const {
		std::ostringstream oss;
		oss << m_firstName << " " << m_lastName << " (" << m_initials << ")";
		return oss.str();
	}

private:
	std::string m_firstName;
	std::string m_lastName;
	std::string m_initials;
};
