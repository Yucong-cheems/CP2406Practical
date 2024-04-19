#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

vector<int> sieveOfEratosthenes(int limit) 
{
    // hold the prime status of each number up to 'limit'.
    vector<bool> prime(limit + 1, true);
    vector<int> primes;
    prime[0] = prime[1] = false;
    // mark the non-prime numbers
    for (int p = 2; p * p <= limit; p++) {
        if (prime[p]) {
            for (int i = p * p; i <= limit; i += p) 
            {
                prime[i] = false;
            }
        }
    }
    // Collect all prime numbers
    for (int p = 2; p <= limit; p++) {
        if (prime[p]) {
            primes.push_back(p);
        }
    }

    return primes;
}
// check if a number is a circular prime
bool isCircularPrime(int n, const set<int>& primes_set) 
{
    string s = to_string(n);
    int len = s.length();

    for (int i = 1; i < len; i++) {
        rotate(s.begin(), s.begin() + 1, s.end());
        int rotated = stoi(s);
        if (primes_set.find(rotated) == primes_set.end()) {
            return false;
        }
    }

    return true;
}

int main() 
{
    const int MAX_N = 1'000'000;// Maximum number
    vector<int> primes = sieveOfEratosthenes(MAX_N);
    set<int> primes_set(primes.begin(), primes.end());

    int res = 0;
    for (int n : primes) {
        if (isCircularPrime(n, primes_set)) {
            res++;
            cout << "n = " << n << ", res = " << res << endl;
        }
    }

    cout << "DONE\n";
    return 0;
}

/*
n = 2, res = 1
n = 3, res = 2
n = 5, res = 3
n = 7, res = 4
n = 11, res = 5
n = 13, res = 6
n = 17, res = 7
n = 31, res = 8
n = 37, res = 9
n = 71, res = 10
n = 73, res = 11
n = 79, res = 12
n = 97, res = 13
n = 113, res = 14
n = 131, res = 15
n = 197, res = 16
n = 199, res = 17
n = 311, res = 18
n = 337, res = 19
n = 373, res = 20
n = 719, res = 21
n = 733, res = 22
n = 919, res = 23
n = 971, res = 24
n = 991, res = 25
n = 1193, res = 26
n = 1931, res = 27
n = 3119, res = 28
n = 3779, res = 29
n = 7793, res = 30
n = 7937, res = 31
n = 9311, res = 32
n = 9377, res = 33
n = 11939, res = 34
n = 19391, res = 35
n = 19937, res = 36
n = 37199, res = 37
n = 39119, res = 38
n = 71993, res = 39
n = 91193, res = 40
n = 93719, res = 41
n = 93911, res = 42
n = 99371, res = 43
n = 193939, res = 44
n = 199933, res = 45
n = 319993, res = 46
n = 331999, res = 47
n = 391939, res = 48
n = 393919, res = 49
n = 919393, res = 50
n = 933199, res = 51
n = 939193, res = 52
n = 939391, res = 53
n = 993319, res = 54
n = 999331, res = 55
DONE*/