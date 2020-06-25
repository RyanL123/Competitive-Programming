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

struct state {
	int r1, c1, r2, c2;
};
int dis[20][20][20][20];
int d[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

bool valid(int r1, int c1, int r2, int c2, int n){
	return r1 <= n && r1 >= 1 && c1 <= n && r2 <= n && r2 >= 1 && c2 <= n && c2 >= 1 &&
	dis[r1][c1][r2][c2] == -1 && (r1 != r2 || c1 != c2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, rs, cs, re, ce, r1, c1;
    cin >> n >> rs >> cs >> re >> ce >> r1 >> c1;
    if (r1 == rs && c1 == cs) cin >> r1 >> c1;
    memset(dis, -1, sizeof(dis));
    queue<state> q;
    q.push(state{rs, cs, r1, c1});
    dis[rs][cs][r1][c1] = 0;
    while (!q.empty()){
    	state s = q.front();
    	int dd = dis[s.r1][s.c1][s.r2][s.c2];
    	q.pop();
    	for (int i = 0; i < 4; i++){
    		// Swap marble with adjacent empty cell
    		if (abs(s.r1 - s.r2) + abs(s.c1 - s.c2) == 1 && 
    			valid(s.r2, s.c2, s.r1, s.c1, n)){
    			q.push(state{s.r2, s.c2, s.r1, s.c1});
    			dis[s.r2][s.c2][s.r1][s.c1] = dd+1;
    		}
    		int r3 = s.r2 + d[i][0];
    		int c3 = s.c2 + d[i][1];
    		// Swap empty cell with adjacent occupied cell
    		if (valid(s.r1, s.c1, r3, c3, n)){
    			q.push(state{s.r1, s.c1, r3, c3});
    			dis[s.r1][s.c1][r3][c3] = dd+1;
    		}
    	}
    }
    int ans = inf;
    for (int i = 1; i <= n; i++){
    	for (int j = 1; j <= n; j++){
    		if (dis[re][ce][i][j] != -1) ans = min(ans, dis[re][ce][i][j]);
    	}
    }
    cout << ans;
}