#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main(void) {
    string guest, host, letters;
    cin >> guest >> host >> letters;
    vector<char> guestHost;
    vector<char> lettersVector;
    for (int i = 0; i < guest.length(); i++)
        guestHost.push_back((char) guest[i]);
    for (int i = 0; i < host.length(); i++)
        guestHost.push_back((char) host[i]);
    for (int i = 0; i < letters.length(); i++)
        lettersVector.push_back((char) letters[i]);
    sort(guestHost.begin(), guestHost.end());
    sort(lettersVector.begin(), lettersVector.end());
    string out = guestHost == lettersVector ? "YES" : "NO";
    cout << out << endl;
}