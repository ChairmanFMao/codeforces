#include <bits/stdc++.h>
using namespace std;

int main(void) {
    vector<int> numbers;
    for (int i = 0; i < 4; i++) {
        int x;
        cin >> x;
        numbers.push_back(x);
    }
    sort(numbers.begin(), numbers.end());
    int a = numbers[3] - numbers[0], b = numbers[3] - numbers[1], c = numbers[3] - numbers[2];
    cout << a << " " << b << " " << c << endl;
}