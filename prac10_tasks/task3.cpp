#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <tuple>

using namespace std;

const int MAX_P = 1000;
const int MAX_N = MAX_P / 2;

int main() 
{
    map<int, vector<tuple<int, int, double>>> res;
    int best_len = 1;
    int best_p = 0;

    for (int a = 1; a <= MAX_N; ++a) {
        for (int b = a; b <= MAX_N; ++b) {
            double c = sqrt(a * a + b * b);
            int ic = static_cast<int>(c);
            if (c == ic) {  
                int p = a + b + ic;
                if (p > MAX_P) {
                    continue;
                }
                res[p].push_back(make_tuple(a, b, c));
                int new_len = res[p].size();
                if (new_len > best_len) {
                    best_len = new_len;
                    best_p = p;
                }
            }
        }
    }

    cout << "Best p = " << best_p << " with " << best_len << " solutions:" << endl;
    for (const auto& triple : res[best_p]) {
        cout << "(" << get<0>(triple) << ", " << get<1>(triple) << ", " << get<2>(triple) << "), ";
    }
    cout << endl;

    return 0;
}