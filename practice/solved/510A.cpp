#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int n, m;
    cin >> n >> m;
    char snake[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            snake[i][j] = '.';
        }
    }
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            for (int j = 0; j < m; j++) {
                snake[i][j] = '#';
            }
        } else {
            int num = (i / 2) % 2;
            if (num == 0) {
                snake[i][m-1] = '#';
            } else {
                snake[i][0] = '#';
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << snake[i][j];
        }
        cout << endl;
    }
}