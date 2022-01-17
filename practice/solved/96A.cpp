using namespace std;

// Took 6 attempts to get accepted ;-;

void solve() {
    string players;
    cin >> players;
    if (players.length() < 7) {
        cout << "NO" << "\n";
        return;
    }
    bool bad = 0;
    for (int i = 0; i < players.length() - 6; i++) {
        bool one = 1, zero = 1;
        for (int j = i; j < i+7; j++) {
            if (players[j] == '0')
                one = 0;
            if (players[j] == '1')
                zero = 0;
        }
        if (one || zero)
            bad = 1;
    }
    string out = bad ? "YES" : "NO";
    cout << out << "\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cout << "\n";
    int t = 1;
    for (int i = 1; i <= t; ++i)
        solve();
}