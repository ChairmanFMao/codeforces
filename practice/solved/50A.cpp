#include <iostream>
using namespace std;

int main(void) {
    int n, m;
    cin >> n >> m;
    int dominos = n * m;
    cout << dominos / 2 << "\n";
    return 0;
}