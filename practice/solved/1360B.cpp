#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        vector<int> numbers;
        for (int j = 0; j < n; j++) {
            int s;
            cin >> s;
            numbers.push_back(s);
        }
        sort(numbers.begin(), numbers.end());
        int smallestGap = numbers[1] - numbers[0];
        for (int j = 1; j < n - 1; j++) {
            if (numbers[j+1] - numbers[j] < smallestGap)
                smallestGap = numbers[j+1] - numbers[j];
        }
        cout << smallestGap << "\n";
    }
}