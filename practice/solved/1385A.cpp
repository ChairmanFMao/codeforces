#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void solution() {
    vector<int> numbers;
    int x, y, z;
    cin >> x >> y >> z;
    numbers.push_back(x);
    numbers.push_back(y);
    numbers.push_back(z);
    sort(numbers.begin(), numbers.end());
    if (numbers[1] == numbers[2])
        cout << "YES" << "\n" << numbers[2] << " " << numbers[0] << " " << numbers[0] << "\n";
    else
        cout << "NO" << "\n";
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