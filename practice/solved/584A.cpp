#include <iostream>
#include <string>
using namespace std;

int main(void) {
    int n, t;
    cin >> n >> t;
    if (n == 1 && t == 10) {
        cout << -1 << endl;
        return 0;
    }
    string out = "";
    char tString = to_string(t)[0];
    while (out.length() != n) out += tString;
    if (t == 10) {
        out[out.length() - 1] = '0';
    }
    cout << out << endl;
    return 0;
}