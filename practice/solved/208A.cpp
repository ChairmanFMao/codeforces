#include <bits/stdc++.h>
using namespace std;

// In cpp the substring works differently to python and java
// string.substr(starting position, length)
// rather than string[starting position : ending position]

void solve() {
    string dubstep;
    cin >> dubstep;
    vector<string> words;
    string word = "";
    for (int i = 0; i < dubstep.length(); i++) {
        if (dubstep[i] == 'W' && dubstep[i+1] == 'U' && dubstep[i+2] == 'B') {
            i += 2;
            if (word != "") {
                words.push_back(word);
            }
            word = "";
        } else {
            word += dubstep[i];
        }
    }
    if (word != "")
        words.push_back(word);
    for (int i = 0; i < words.size(); i++)
        cout << words[i] << " ";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cout << "\n";
    solve();
}