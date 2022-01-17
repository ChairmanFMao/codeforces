#include <bits/stdc++.h>
#include <sstream>
#include <vector>
using namespace std;

int main(void) {
    string s;
    cin >> s;
    vector<int> numbers;
    stringstream ss(s);
    for (int i; ss >> i;) {
        numbers.push_back(i);
        if (ss.peek() == '+')
            ss.ignore();
    }
    sort(numbers.begin(), numbers.end());
    string extra = "+";
    for (int i = 0; i < numbers.size(); i++) {
        if (i == numbers.size() - 1)
            extra = "";
        cout << numbers[i] << extra; 
    }
    return 0;
}