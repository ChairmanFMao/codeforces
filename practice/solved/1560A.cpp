#include <iostream>
#include <vector>
using namespace std;

vector<int> calculate(int n) {
    vector<int> out;
    for (int i = 1; out.size() < 1000; i++) {
        if (i % 3 != 0 && i % 10 != 3)
            out.push_back(i);
    }
    return out;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> numbers = calculate(1000);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int k;
        cin >> k;
        cout << numbers[k-1] << "\n";
    }
}