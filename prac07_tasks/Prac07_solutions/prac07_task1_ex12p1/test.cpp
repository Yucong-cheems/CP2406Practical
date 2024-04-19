#include "KeyValuePair.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	KeyValuePair<int, double> kv1{ 11, 2.33 };
    cout << kv1.getKey() << " = " << kv1.getValue() << endl;

    KeyValuePair<string, int> kv2{ "John Doe", 123456 };
    cout << kv2.getKey() << " = " << kv2.getValue() << endl;
}
