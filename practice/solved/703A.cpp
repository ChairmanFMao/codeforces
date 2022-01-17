#include <iostream>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    int m = 0, c = 0;
    for (int i = 0; i < n; i++) {
        int score1, score2;
        cin >> score1 >> score2;
        if (score1 > score2)
            m++;
        else if (score2 > score1)
            c++;
    }
    string out = m == c ? "Friendship is magic!^^" : m > c ? "Mishka" : "Chris";
    cout << out << "\n";
}