#include <iostream>
#include <vector>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        string s;
        cin >> s;
        int ac = 0, b = 0;
        for (int j = 0; j < s.length(); j++) {
            if (s[j] == 'B')
                b++;
            else
                ac++;
        }
        string out = ac == b ? "YES" : "NO";
        cout << out << "\n";
    }
}