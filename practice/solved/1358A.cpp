#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

void solution() {
    int n, m;
    cin >> n >> m;
    int lights = ceil((double) n * m / 2);
    cout << lights << "\n";
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