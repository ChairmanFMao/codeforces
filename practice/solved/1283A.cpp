#include <iostream>
#include <vector>
using namespace std;

void solution() {
    int h, m;
    cin >> h >> m;
    int mins = (23 - h) * 60 + 60 - m;
    cout << mins << "\n";
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