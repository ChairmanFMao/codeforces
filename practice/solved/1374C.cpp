#include <iostream>
using namespace std;

int main(void) {
    int repeats;
    cin >> repeats;
    for(int i = 0; i < repeats; i++) {
        int length;
        string brackets;
        cin >> length >> brackets;
        string removed = brackets;
        bool removing = true;
        while (removing) {
            brackets = removed;
            removed = "";
            removing = false;
            for (int j = 0; j < brackets.length(); j++) {
                if (j < brackets.length() - 1) {
                    if (brackets[j] == '(' && brackets[j + 1] == ')') {
                        removing = true;
                        j++;
                        continue;
                    } else removed += brackets[j];
                } else removed += brackets[j];
            }
        }
        int out = removed.length() / 2;
        cout << out << endl;
    }
    return 0;
}