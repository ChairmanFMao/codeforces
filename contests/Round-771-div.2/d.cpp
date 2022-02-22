
#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Had to read um_nik's solution and managed to make sense of it,
// algorithm cleverly checks only adjacent squares that are updated

const int mxN = 1000;
int n, m, currentMove = 0;
vector<vector<bool>> used(mxN+1, vector<bool> (mxN+1, 0));
vector<vector<int>> grid(mxN+1, vector<int> (mxN+1));
vector<vector<int>> moves((mxN*mxN)+1);

// This function checks if a square can start at the co-ords passed in
void check(int x, int y) {
    if (x < 0 || y < 0 || x >= n-1 || y >= m-1 || used[x][y])
        return;
    
    // Gets all of the colours of the squares in the 2x2
    set<int> around;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            if (grid[x+i][y+j] != -1) {
                around.insert(grid[x+i][y+j]);
            }
        }
    }
    // Deals with the addition of the new square to moves
    if ((int)around.size() != 1)
        return;
    vector<int> color(around.begin(),around.end());
    moves[currentMove++] = {x,y,color[0]};
    used[x][y] = 1;
}

void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> grid[i][j];

    // This get at least the first square in the moves
    for (int i = 0; i < n-1; i++)
        for (int j = 0; j < m-1; j++)
            check(i,j);

    // This goes through all of the moves setting squares to -1 when they are empty
    for (int i = 0; i < currentMove; i++) {
        vector<int> current(moves[i].begin(),moves[i].end());
        // Setting all the squares to -1
        grid[current[0]][current[1]] = grid[current[0]+1][current[1]] = grid[current[0]][current[1]+1] = grid[current[0]+1][current[1]+1] = -1;
        // Checking all of the squares that would be effected by this operation
        for (int j = -1; j < 2; j++)
            for (int k = -1; k < 2; k++)
                check(current[0]+j, current[1]+k);
    }
    
    bool good = 1;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            good &= grid[i][j] == -1;

    if (!good) {
        cout << -1 << "\n";
        return;
    }
    
    cout << currentMove << "\n";
    for (int i = currentMove-1; ~i; i--) {
        cout << moves[i][0]+1 << " " << moves[i][1]+1 << " " << moves[i][2] << "\n";
    }
}

int main(void) {
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    
    solve();
}
