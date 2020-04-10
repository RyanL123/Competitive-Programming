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

int solve(vector<int> num){
    if (num.size() == 1) return num[0];
    int best = 0, ans;
    for (int i = 0; i < num.size()-1; i++){
        vi vec = num;
        vec[i] = vec[i]+vec[i+1];
        vec.erase(vec.begin()+i+1);
        ans = solve(vec);
        if (ans <= 24) best = max(best, ans);
        vec = num;
        vec[i] = vec[i]-vec[i+1];
        vec.erase(vec.begin()+i+1);
        ans = solve(vec);
        if (ans <= 24) best = max(best, ans);
        vec = num;
        vec[i] = vec[i]*vec[i+1];
        vec.erase(vec.begin()+i+1);
        ans = solve(vec);
        if (ans <= 24) best = max(best, ans);
        vec = num;
        if (vec[i+1] != 0 && vec[i]%vec[i+1] == 0){
            vec[i] = vec[i]/vec[i+1];
            vec.erase(vec.begin()+i+1);
            ans = solve(vec);
            if (ans <= 24) best = max(best, ans);
        }
    }
    return best;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
    	vi vec;
    	for (int j = 0; j < 4; j++){
    		int x;
    		cin >> x;
    		vec.pb(x);
    	}
    	int ans = 0;
    	for (int j = 0; j < 24; j++){
            ans = max(ans, solve(vec));
    	    next_permutation(vec.begin(), vec.end());
    	}
    	cout << ans << "\n";
    }
}