#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        string n;
        cin >> n;
        int count = 0;
        for (int j = 0; j < n.length(); j++)
            count += n[j] == '0' ? 0 : 1;
        cout << count << "\n";
        string out[count];
        int pointer = 0;
        for (int j = 0; j < n.length(); j++) {
            if (n[j] != '0') {
                out[pointer] = n[j];
                for (int k = 0; k < n.length() - j - 1; k++)
                    out[pointer] += '0';
                pointer++;
            }
        }
        string extra = " ";
        for (int j = 0; j < count; j++) {
            if (j == count - 1)
                extra = "";
            cout << out[j] << extra;
        }
        cout << endl;
    }
}