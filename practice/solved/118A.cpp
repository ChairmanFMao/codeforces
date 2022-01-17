#include <iostream>
#include <string>
using namespace std;

int main(void) {
    string word, output = "";
    char c;
    cin >> word;
    for (int i = 0; i < word.length(); i++) {
        c = tolower(word[i]);
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y') continue;
        else {
            output += ".";
            output += c;
        }
    }
    cout << output << endl;
}