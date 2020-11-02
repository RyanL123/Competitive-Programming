#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef vector<pair<int, int>> vii;
typedef vector<int> vi;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
#define eb emplace_back
#define pb push_back
#define mp make_pair
#define srt(x) sort(x.begin(), x.end())
#define all(x) x.begin(), x.end()
#define inf 0x3f3f3f3f

int dis[10][10];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    vii move = {{1, 2}, {1, -2}, {-1, 2}, {-1, -2}, {2, 1}, {2, -1}, {-2, 1}, {-2, -1}};
    queue<pii> q;
    memset(dis, 0x3f, sizeof(dis));
    dis[x1][y1] = 0;
    q.push({x1, y1});
    while (!q.empty()) {
        int x = q.front().first, y = q.front().second;
        q.pop();
        for (pii p : move) {
            if (x+p.first <= 8 && x+p.first >= 1 && y+p.second <= 8 && y+p.second >= 1) {
                if (dis[x+p.first][y+p.second] > dis[x][y]+1) {
                    dis[x+p.first][y+p.second] = dis[x][y]+1;
                    q.push({x+p.first, y+p.second});
                }
            }
        }
    }
    cout << dis[x2][y2] << '\n';
}