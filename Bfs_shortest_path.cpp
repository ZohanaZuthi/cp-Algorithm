#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<queue>
using namespace std;
// https://www.spoj.com/problems/NAKANJ/
const int INF = 1e9;
vector<pair<int, int>> moves = {
    {1, 2}, {-1, 2}, {1, -2}, {-1, -2},
    {2, 1}, {-2, 1}, {2, -1}, {-2, -1}
};

bool isValid(int x, int y) { 
    return x >= 0 && y >= 0 && x < 8 && y < 8; 
}

int getX(string s) { return s[0] - 'a'; }
int getY(string s) { return s[1] - '1'; }

int bfs(string s1, string s2) {
    int s_x = getX(s1);
    int s_y = getY(s1);
    int d_x = getX(s2);
    int d_y = getY(s2);

    // Initialize vis and level as 8x8 grids
    vector<vector<int>> vis(8, vector<int>(8, 0));
    vector<vector<int>> level(8, vector<int>(8, INF));

    queue<pair<int, int>> q;
    q.push({s_x, s_y});
    vis[s_x][s_y] = 1;
    level[s_x][s_y] = 0;

    while (!q.empty()) {
        pair<int, int> v = q.front();
        q.pop();
        int x = v.first, y = v.second;

        for (auto mov : moves) {
            int childx = mov.first + x;
            int childy = mov.second + y;

            if (isValid(childx, childy) && !vis[childx][childy]) {
                q.push({childx, childy});
                level[childx][childy] = level[x][y] + 1;
                vis[childx][childy] = 1;

                // Stop early if destination is reached
                if (childx == d_x && childy == d_y) {
                    return level[childx][childy];
                }
            }
        }
    }

    return level[d_x][d_y];
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        string s1, s2;
        cin >> s1 >> s2;
        cout << bfs(s1, s2) << endl;
    }
    return 0;
}
