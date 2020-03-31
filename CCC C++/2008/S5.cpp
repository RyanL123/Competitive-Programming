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

bool state[31][31][31][31];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    state[2][1][0][2] = true;
	state[1][1][1][1] = true;
	state[0][0][2][1] = true;
	state[0][3][0][0] = true;
	state[1][0][0][1] = true;
	for (int a = 0; a <= 30; a++){
		for (int b = 0; b <= 30; b++){
			for (int c = 0; c <= 30; c++){
				for (int d = 0; d <= 30; d++){
					bool canWin = false;
					if (a >= 2 && b >= 1 && d >= 2){
						canWin |= !state[a-2][b-1][c][d-2];
					}
					if (a >= 1 && b >= 1 && c >= 1 && d >= 1){
						canWin |= !state[a-1][b-1][c-1][d-1];
					}
					if (c >= 2 && d >= 1){
						canWin |= !state[a][b][c-2][d-1];
					}
					if (b >= 3){
						canWin |= !state[a][b-3][c][d];
					}
					if (a >= 1 && d >= 1){
						canWin |= !state[a-1][b][c][d-1];
					}
					state[a][b][c][d] = canWin;
				}
			}
		}
	}
    for (int i = 0; i < n; i++){
    	int A, B, C, D;
    	cin >> A >> B >> C >> D;    	
 		if (state[A][B][C][D]){
 			cout << "Patrick\n";
 		}
 		else cout << "Roland\n";
    }
}
	