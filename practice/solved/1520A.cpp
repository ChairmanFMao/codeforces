#include <iostream>
#include <set>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        string word;
        cin >> n >> word;
        set<char> letters = {};
        char previous = ' ';
        char current = ' ';
        bool suspicious = 0;
        for (int j = 0; j < n; j++) {
            current = word[j];
            if (previous != current && letters.count(current)) {
                suspicious = 1;
                break;
            }
            letters.insert(current);
            previous = current;
        }
        string out = suspicious ? "NO" : "YES";
        cout << out << "\n";
    }
}