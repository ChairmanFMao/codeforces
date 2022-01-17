#include <iostream>
#include <vector>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    int s = 0, d = 0;
    vector<int> cards;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        cards.push_back(a);
    }
    bool turn = 1;
    while (cards.size() > 0) {
        if (turn) {
            if (cards.front() > cards.back()) {
                s += cards.front();
                cards.erase(cards.begin());
            } else {
                s += cards.back();
                cards.pop_back();
            }
        } else {
            if (cards.front() > cards.back()) {
                d += cards.front();
                cards.erase(cards.begin());
            } else {
                d += cards.back();
                cards.pop_back();
            }
        }
        turn = !turn;
    }
    cout << s << " " << d;
}