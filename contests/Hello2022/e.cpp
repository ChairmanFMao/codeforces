#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Strategy:
// Assign teachers in descending order of their age to the groups in descending order of age

// Decided to have a go at this instead of d because it looked terrible and I thought of something for this
// I found it quite fun :)

// WA pretest 2
// Potential error due to double numbers precision, don't think it's the issue after some debugging
// With some more debugging it now used more memory on pretest 2, but still failed

struct Group {
    vector<ll> students;
    ll size;
    ll sum;
};

bool groupAverage(Group first, Group second) {
    return ((double) first.sum / first.size) < ((double) second.sum / second.size);
}

const ll mxN = 1e5, mxM = 1e5;
vector<ll> teachers(mxN);
vector<Group> groups(mxM);
ll n, m;

bool startLesson() {
    ll tptr = n-1, gptr = m-1;
    while (gptr >= 0 && tptr >= 0) {
        if (1e-9 < teachers[tptr] - ((double) groups[gptr].sum / groups[gptr].size)) {
            tptr--;
            gptr--;
        } else {
            return 0;
        }
    }
    return gptr == -1;
}

void solve() {
    teachers.clear();
    groups.clear();
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> teachers[i];
    sort(teachers.begin(),teachers.begin() + n);

    ll totalStudents = 0;
    for (int i = 0; i < m; i++) {
        int k;
        cin >> k;
        Group current;
        current.sum = 0;
        vector<ll> students(k);
        for (int j = 0; j < k; j++) {
            cin >> students[j];
            current.sum += students[j];
            totalStudents++;
        }
        current.students = students;
        current.size = students.size();
        groups[i] = current;
    }

    string out = "";
    int gptr = 0, absent = 0;
    for (int i = 0; i < totalStudents; i++) {
        if (absent >= groups[gptr].students.size()) {
            absent = -1;
            gptr++;
            i--;
        } else {
            groups[gptr].sum -= groups[gptr].students[absent];
            groups[gptr].size--;
            sort(groups.begin(),groups.begin() + m, groupAverage);
            out += startLesson() ? "1" : "0";
            groups[gptr].sum += groups[gptr].students[absent];
            groups[gptr].size++;
        }
        absent++;
    }
    cout << out << "\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i)
        solve();
}