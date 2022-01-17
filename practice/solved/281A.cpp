#include <bits/stdc++.h>
#include <string>
using namespace std;

int main(void) {
    string word;
    cin >> word;
    cout << (char) toupper(word[0]) << word.substr(1) << endl;
}