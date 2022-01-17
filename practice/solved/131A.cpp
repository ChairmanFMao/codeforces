#include <iostream>
using namespace std;

int main(void) {
    string word, out = "";
    cin >> word;
    for (int i = 0; i < word.length(); i++) {
        bool lower = islower(word[i]);
        if (lower && i > 0) {
            cout << word << endl;
            return 0;
        }
        out += lower ? toupper(word[i]) : tolower(word[i]);
    }
    cout << out << endl;
    return 0;
}