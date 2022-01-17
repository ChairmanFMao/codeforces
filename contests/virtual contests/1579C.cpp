#include <iostream>
#include <vector>
using namespace std;

void solution() {
    int n, m, k;
    cin >> n >> m >> k;
    char cells[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> cells[i][j];
        }
    }
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