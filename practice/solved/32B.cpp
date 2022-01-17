#include <iostream>
#include <vector>
using namespace std;

void solution(string number) {
    string out = "";
    for (int i = 0; i < number.length(); i++) {
        if (number[i] == '.')
            out += '0';
        else if (number[i] == '-' && number[i+1] == '.') {
            out += '1';
            i++;
        } else if (number[i] == '-' && number[i+1] == '-') {
            out += '2';
            i++;
        }
    }
    cout << out;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cout << "\n";
    string t;
    cin >> t;
    solution(t);
}