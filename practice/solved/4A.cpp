#include <iostream>
using namespace std;

int main(void) {
    int w;
    cin >> w;
    string output = w % 2 == 0 && w > 2 ? "YES" : "NO";
    cout << output << endl;
    return 0;
}