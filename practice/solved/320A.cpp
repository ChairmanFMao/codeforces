#include <bits/stdc++.h>
using namespace std;

void solve() {
    string n;
    cin >> n;
    // This takes care of strings that are 3 characters or shorter
    if (n.length() <= 3) {
        if (n == "1" || n == "11" || n == "14" || n == "114" || n == "141" || n == "144" || n == "111") {
            cout << "YES" << "\n";
            return;
        } else {
            cout << "NO" << "\n";
            return;
        }
    }
    // If the first character of the string is 4 then the number is invalid
    if (n[0] == '4') {
        cout << "NO" << "\n";
        return;
    }
    int end = 0;
    // This iterates over the string checking for substrings of the numbers
    // The variable end is used to keep track of the last digit checked by this part
    for (int i = 0; i < n.length() - 2; i++) {
        if (n[i] != '1' && n[i] != '4') {
            cout << "NO";
            return;
        }
        if (n[i] == '1' && n[i+1] == '1') {
            end = i + 1;
            continue;
        }
        if (n[i] == '1' && n[i+1] == '4' && n[i+2] == '1') {
            i++;
            end = i + 1;
            continue;
        }
        if (n[i] == '1' && n[i+1] == '4' && n[i+2] == '4') {
            i+=2;
            end = i + 1;
            continue;
        }
    }
    // Using the value of end we can make get the last up to 3 characters  that weren't checked by the main algorithm and see if they are valid
    string ending = n.substr(end);
    if (ending == "" || ending == "1" || ending == "11" || ending == "14" || ending == "114" || ending == "141" || ending == "144" || ending == "111") {
        cout << "YES" << "\n";
        return;
    } else {
        cout << "NO" << "\n";
        return;
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cout << "\n";
    solve();
}