#include <iostream>
using namespace std;

int main(void) {
    int inputs, x = 0;
    cin >> inputs;
    for (int i = 0; i < inputs; i++) {
        string input;
        cin >> input;
        int start = 0;
        if (input[0] == 'X') 
            start++;
        x += input.substr(start, start+2) == "++" ? 1 : -1;
    }
    cout << x << "\n";
    return 0;
}