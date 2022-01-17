#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Didn't complete on pc, looked at solution but still timed out.

void solve() {
    int n;
    cin >> n;
    vector<int> numbers;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        numbers.push_back(a);
    }
    int points = 0, index = 0, length = numbers.size();
    while (length > 0) {
        index = 0;
        if (length == 1) {
            points += numbers[0];
            length = 0;
            break;
        }
        if (length == 2) {
            points += max(numbers[0],numbers[1]);
            numbers.clear();
            length = 0;
            break;
        }
        if (length == 3) {
            points += numbers[0] + numbers[2] > numbers[1] ? numbers[0] + numbers[2] : numbers[1];
            length = 0;
            break;
        }
        if (numbers[0] >= numbers[1]) {
            points += numbers[0];
            numbers.erase(numbers.begin(), numbers.begin()+1);
            length -= 2;
            continue;
        }
        for (int i = 0; i < numbers.size()-1; i++) {
            if (i == numbers.size()-2) {
                index = i;
                points += numbers[i+1];
                length -= 2;
                break;
            }
            if (numbers[i] < numbers[i+1] && numbers[i+1] >= numbers[i+2]) {
                points += numbers[i+1];
                index = i;
                length -= 3;
                break;
            }
        }
        if (index == numbers.size()-2)
            numbers.erase(numbers.begin()+index, numbers.begin()+index+1);
        else
            numbers.erase(numbers.begin()+index, numbers.begin()+index+2);
    }
    cout << points << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
}