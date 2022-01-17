#include <iostream>
#include <vector>
using namespace std;

void solution() {
    int n;
    cin >> n;
    string out = n % 4 == 0 ? "YES" : "NO";
    cout << out << "\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cout << "\n";
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
        solution();
}