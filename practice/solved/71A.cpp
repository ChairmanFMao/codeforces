#include <iostream>
#include <string>
using namespace std;

int main(void) {
    int repeats;
    cin >> repeats;
    for (int i = 0; i < repeats; i++) {
        string word;
        cin >> word;
        if (word.length() > 10) {
            cout << word[0] << word.length() - 2 << word[word.length() - 1] << endl;
        } else {
            cout << word << endl;
        }
    }
    return 0;
}