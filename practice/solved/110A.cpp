#include <bits/stdc++.h>
using namespace std;

int main(void) {
    string n;
    cin >> n;
    int lucky = 0;
    for (int i = 0; i < n.length(); i++) {
        if (n[i] == '4' || n[i] == '7')
            lucky++;
    }
    string out = lucky == 4 || lucky == 7 ? "YES" : "NO";
    cout << out << endl;
}