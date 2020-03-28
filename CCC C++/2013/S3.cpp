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

vector<vi> games = {{inf, inf, inf, inf, inf},
                    {inf, inf, inf, inf, inf},
                    {inf, inf, inf, inf, inf},
                    {inf, inf, inf, inf, inf},
                    {inf, inf, inf, inf, inf}};
int t, g, points[5];

void check(vector<vi> vec, int a, int b, bool tie){
    int t1 = 0, t2 = 0, t3 = 0, t4 = 0;
    if (tie) vec[a][b] = vec[b][a] = 1;
    else {
        vec[a][b] = 3;
        vec[b][a] = 0;
    }
    for (int i = 1; i <= 4; i++){
        for (int j = i+1; j <= 4; j++){
            if (vec[i][j] == inf) {
                check(vec, i, j, false);
                check(vec, j, i, false);
                check(vec, j, i, true);
                goto skip;
            }
        }
    }
    skip:
    for (int i = 1; i <= 4; i++){
        for (int j = 1; j <= 4; j++){
            if (i == j) continue;
            else if (vec[i][j] == inf) return;
            else if (i == 1) t1 += vec[i][j];
            else if (i == 2) t2 += vec[i][j];
            else if (i == 3) t3 += vec[i][j];
            else if (i == 4) t4 += vec[i][j];
        }
    }
    if (t1 > t2 && t1 > t3 && t1 > t4) points[1]++;
    else if (t2 > t1 && t2 > t3 && t2 > t4) points[2]++;
    else if (t3 > t1 && t3 > t2 && t3 > t4) points[3]++;
    else if (t4 > t1 && t4 > t2 && t4 > t3) points[4]++;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t >> g;
    for (int i = 0; i < g; i++){
        int a, b, sa, sb;
        cin >> a >> b >> sa >> sb;
        if (sa > sb){
            games[a][b] = 3;
            games[b][a] = 0;
        }
        else if (sa < sb){
            games[b][a] = 3;
            games[a][b] = 0;
        }
        else {
            games[a][b] = games[b][a] = 1;
        }
    }
    for (int i = 1; i <= 4; i++){
        for (int j = i+1; j <= 4; j++){
            if (games[i][j] == inf){
                check(games, i, j, false);
                check(games, j, i, false);
                check(games, j, i, true);
                if (t == 1) cout << points[1] << endl;
                if (t == 2) cout << points[2] << endl;
                if (t == 3) cout << points[3] << endl;
                if (t == 4) cout << points[4] << endl;
                return 0;
            }
        }
    }
}
