#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

void solution() {
    string keyboard, s;
    cin >> keyboard >> s;
    vector<pair<char, int>> keys;
    for (int i = 0; i < keyboard.length(); i++)
        keys.push_back(make_pair(keyboard[i], i));
    int moves = 0, previous = 0;
    for (int i = 0; i < s.length(); i++) {
        for (int j = 0; j < keys.size(); j++) {
            if (s[i] == keys[j].first) {
                moves += i == 0 ? 0 : abs(previous - j);
                previous = j;
            }
        }
    }
    cout << moves << "\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cout << "\n";
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
        solution();
}