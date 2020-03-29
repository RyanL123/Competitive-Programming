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

int h[10010];
bool used[10010][10010];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, I, H, M;
    cin >> N >> I >> H >> M;
    for (int i = 1; i <= N; i++) h[i] = H;
    for (int x = 1; x <= M; x++){
        int i, j;
        cin >> i >> j;
        if (!used[i][j] && !used[j][i]){
            used[i][j] = true;
            used[j][i] = true;
            for (int y = min(i, j)+1; y <= max(i, j)-1; y++){
                h[y]--;
            }
        }
    }
    for (int i = 1; i <= N; i++){
        cout << h[i] << endl;
    }
}