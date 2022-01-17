#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Time limit exceeds on test 13
// Unsure on how I would make the algorithm more efficient
// Maybe try and identify cycles, idk
// With my "improved" algorithm I got WA on test 5
// With further improvements all I get is TLE on test 13
// Still TLE on test 13 even with all the cycle identification done
// Even with pre-caching of 5 locations ahead, I get TLE on test 13
// I think that there might just be loads of inserts that would be slowing down the execution but idk
// If there are just loads of traversal queries, they should execute very quickly
// I made it intelligently decide which numbers to recalcuate but it still ended up in timeout on test 13
// Very interested to actually see what test case 13 contained

struct Number {
    int value = 0;
    int fiveAhead = 0;
};

void solve() {
    int n, q;
    cin >> n >> q;
    Number numbers[n+1];
    for (int i = 1; i <= n; i++)
        cin >> numbers[i].value;
    
    for (int i = 1; i <= n; i++) {
        int ptr = numbers[i].value;
        for (int j = 0; j < 5; j++)
            ptr = numbers[ptr].value;
        numbers[i].fiveAhead = ptr;
    }
    
    int type, first, second;
    for (int i = 0; i < q; i++) {
        cin >> type >> first >> second;
        if (type == 1) {
            swap(numbers[first],numbers[second]);
            set<int> reCalc;
            int ptr1 = numbers[first].value, ptr2 = numbers[second].value;
            for (int j = 0; j < 5; j++) {
                reCalc.insert(ptr1);
                reCalc.insert(ptr2);
                ptr1 = numbers[ptr1].value;
                ptr2 = numbers[ptr2].value;
            }
            for (int j = 1; j <= n; j++) {
                if (reCalc.count(numbers[j].value) || reCalc.count(numbers[j].fiveAhead)) {
                    int ptr = numbers[j].value;
                    for (int k = 0; k < 5; k++)
                        ptr = numbers[ptr].value;
                    numbers[j].fiveAhead = ptr;
                }
            }
        } else {
            int ptr = first;
            for (int j = 0; j < second; j++) {
                if (j - second > 5) {
                    ptr = numbers[ptr].fiveAhead;
                    j += 4;
                } else
                    ptr = numbers[ptr].value;
            }
            cout << ptr << "\n";
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
}