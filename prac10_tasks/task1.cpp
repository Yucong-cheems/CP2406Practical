#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> values{ 2, 5 };

    // Insert numbers 3 and 4 at correct positions
    values.insert(begin(values) + 1, 3);
    values.insert(begin(values) + 2, 4);

    // Initialize second vector with 0 and 1
    vector<int> value2{ 0, 1 };
    values.insert(begin(values), cbegin(value2), cend(value2));

    // Creating a reverse copy of the vector
    vector<int> v3;
    for (auto riter{ crbegin(values) }; riter != crend(values); ++riter) {
        v3.push_back(*riter);
    }

    // Printing the contents of the reversed vector
    for (const auto& element : v3) {
        cout << element << " ";
    }
    cout << endl;

    return 0;
}
