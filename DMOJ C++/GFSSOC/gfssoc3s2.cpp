#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef vector<pair<int, int>> vii;
typedef vector<int> vi;
typedef long long ll;
typedef unsigned long long ull;
#define pb(x) push_back(x)
#define mp(a, b) make_pair(a, b)
#define inf 0x3f3f3f3f

int steps[35][35][35][35];
char game[35][35];

struct state {
    int r1, c1, r2, c2;
};

int r, c;

bool valid(int r1, int c1, int r2, int c2){
    return r1 <= r && r1 >= 1 && r2 <= r && r2 >= 1 && c1 <= c && c1 >= 1 && c2 <= c && c2 >= 1
    && !(r1 == r2 && c1 == c2) && game[r1][c1] != '#' && game[r2][c2] != '#' && steps[r1][c1][r2][c2] == -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int r1 = 0, c1 = 0, r2 = 0, c2 = 0, r3 = -1, c3 = -1;
    cin >> r >> c;
    for (int i = 1; i <= r; i++){
        for (int j = 1; j <= c; j++){
            cin >> game[i][j];
            if (game[i][j] == 'P') r1 = i, c1 = j;
            if (game[i][j] == 'B') r2 = i, c2 = j;
            if (game[i][j] == 'X') r3 = i, c3 = j;
        }
    }
    memset(steps, -1, sizeof(steps));
    steps[r1][c1][r2][c2] = 0;
    queue<state> q;
    q.push({r1, c1, r2, c2});
    while (!q.empty()){
        state s = q.front();
        q.pop();
        int dis = steps[s.r1][s.c1][s.r2][s.c2];
        if (s.r1+1 == s.r2 && s.c1 == s.c2 && valid(s.r1+1, s.c1, s.r2+1, s.c2)){
            q.push({s.r1+1, s.c1, s.r2+1, s.c2});
            steps[s.r1+1][s.c1][s.r2+1][s.c2] = dis+1;
        }
        if (valid(s.r1+1, s.c1, s.r2, s.c2)){
            q.push({s.r1+1,s.c1,s.r2,s.c2});
            steps[s.r1+1][s.c1][s.r2][s.c2] = dis+1;
        }
        if (s.r1-1 == s.r2 && s.c1 == s.c2 && valid(s.r1-1, s.c1, s.r2-1, s.c2)){
            q.push({s.r1-1, s.c1, s.r2-1, s.c2});
            steps[s.r1-1][s.c1][s.r2-1][s.c2] = dis+1;
        }
        if (valid(s.r1-1, s.c1, s.r2, s.c2)){
            q.push({s.r1-1,s.c1,s.r2,s.c2});
            steps[s.r1-1][s.c1][s.r2][s.c2] = dis+1;
        }
        if (s.r1 == s.r2 && s.c1+1 == s.c2 && valid(s.r1, s.c1+1, s.r2, s.c2+1)){
            q.push({s.r1, s.c1+1, s.r2, s.c2+1});
            steps[s.r1][s.c1+1][s.r2][s.c2+1] = dis+1;
        }
        if (valid(s.r1, s.c1+1, s.r2, s.c2)){
            q.push({s.r1,s.c1+1,s.r2,s.c2});
            steps[s.r1][s.c1+1][s.r2][s.c2] = dis+1;
        }
        if (s.r1 == s.r2 && s.c1-1 == s.c2 && valid(s.r1, s.c1-1, s.r2, s.c2-1)){
            q.push({s.r1, s.c1-1, s.r2, s.c2-1});
            steps[s.r1][s.c1-1][s.r2][s.c2-1] = dis+1;
        }
        if (valid(s.r1, s.c1-1, s.r2, s.c2)){
            q.push({s.r1,s.c1-1,s.r2,s.c2});
            steps[s.r1][s.c1-1][s.r2][s.c2] = dis+1;
        }
    }
    if (r3 == -1 || c3 == -1){
        cout << -1;
        return 0;
    }
    int ans = inf;
    for (int i = 1; i <= r; i++){
        for (int j = 1; j <= c; j++){
            if (steps[i][j][r3][c3] != -1) ans = min(ans, steps[i][j][r3][c3]);
        }
    }
    if (ans == inf) cout << -1;
    else cout << ans;
}
