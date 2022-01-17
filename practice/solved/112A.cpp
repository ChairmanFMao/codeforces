#include <iostream>
using namespace std;

int main(void) {
    string a, b;
    cin >> a >> b;
    for (int i = 0; i < a.length(); i++) {
        if ((int) tolower(a.at(i)) > (int) tolower(b.at(i))) {
            cout << 1 << "\n";
            return 0;
        } else if ((int) tolower(a.at(i)) < (int) tolower(b.at(i))) {
            cout << -1 << "\n";
            return 0;
        } 
    }
    cout << 0 << "\n";
    return 0;
}