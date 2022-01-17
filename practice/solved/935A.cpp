#include <iostream>
#include <vector>
using namespace std;

void solution() {
    int n;
    cin >> n;
    int possible = 0;
    for (int i = 1; i < n; i++) {
        if ((n-i)%i == 0)
            possible++;
    }
    cout << possible << "\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cout << "\n";
    solution();
}