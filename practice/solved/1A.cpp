#include <iostream>
#include <cmath>
using namespace std;

int main(void) {
    long long n, m, a;
    cin >> n >> m >> a;
    long long tiles = ((long long) ceil((double) n / a)) * ((long long) ceil((double) m / a));
    cout << tiles << endl;
}