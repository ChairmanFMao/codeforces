#include <bits/stdc++.h>
#include <set>
using namespace std;

int main(void) {
    int year;
    cin >> year;
    while (true) {
        year++;
        string digits = to_string(year);
        set<int> allDigits(digits.begin(), digits.end());
        if (allDigits.size() == digits.size()) {
            cout << year << endl;
            return 0;
        }
    }
}