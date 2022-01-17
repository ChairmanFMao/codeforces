#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#define pb push_back
using namespace std;

void solution() {
    vector<int> skill;
    int s1, s2, s3, s4;
    cin >> s1 >> s2 >> s3 >> s4;
    skill.pb(s1);
    skill.pb(s2);
    skill.pb(s3);
    skill.pb(s4);
    sort(skill.begin(), skill.end());
    vector<int> winners;
    winners.pb(max(s1,s2));
    winners.pb(max(s3,s4));
    sort(winners.begin(), winners.end());
    if (skill[3] == winners[1] && skill[2] == winners[0])
        cout << "YES" << "\n";
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