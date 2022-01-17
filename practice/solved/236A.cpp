#include <bits/stdc++.h>
#include <set>
using namespace std;

int main(void) {
    string username;
    cin >> username;
    set<char> distinct;
    for (int i = 0; i < username.length(); i++) {
        distinct.insert((char) username[i]);
    }
    string out = distinct.size() % 2 == 0 ? "CHAT WITH HER!" : "IGNORE HIM!";
    cout << out << endl;
}