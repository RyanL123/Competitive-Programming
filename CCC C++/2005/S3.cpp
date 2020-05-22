#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef vector<pair<int, int>> vii;
typedef vector<int> vi;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
#define pb push_back
#define mp make_pair
#define srt(x) sort(x.begin(), x.end())
#define inf 0x3f3f3f3f

vector<vi> solve(vector<vi> &pre, vector<vi> &cur){
    vector<vi> ans;
    ans.resize(cur.size()*pre.size(), vector<int>(cur[0].size()*pre[0].size()));
    for (int i = 0; i < pre.size(); i++){
        for (int j = 0; j < pre[0].size(); j++){
            for (int k = 0; k < cur.size(); k++){
                for (int l = 0; l < cur[0].size(); l++){
                    ans[cur.size()*i+k][cur[0].size()*j+l] = cur[k][l]*pre[i][j];
                }
            }
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, mx = -inf, mn = inf, mxr = -inf, mnr = inf, mxc = -inf, mnc = inf, r, c;
    cin >> n >> r >> c;
    vector<vi> pre(r, vector<int>(c));
    for (int j = 0; j < r; j++){
        for (int k = 0; k < c; k++){
            cin >> pre[j][k];
        }
    }
    for (int i = 1; i < n; i++){
        cin >> r >> c;
        vector<vi> cur(r, vector<int>(c));
        for (int j = 0; j < r; j++){
            for (int k = 0; k < c; k++){
                cin >> cur[j][k];
            }
        }
        pre = solve(pre, cur);
    }
    for (int i = 0; i < pre.size(); i++){
        int rtot = 0;
        for (int j = 0; j < pre[0].size(); j++){
            rtot += pre[i][j];
            mx = max(mx, pre[i][j]);
            mn = min(mn, pre[i][j]);
        }
        mxr = max(mxr, rtot);
        mnr = min(mnr, rtot);
    }
    for (int j = 0; j < pre[0].size(); j++){
        int ctot = 0;
        for (int i = 0; i < pre.size(); i++){
            ctot += pre[i][j];
        }
        mxc = max(mxc, ctot);
        mnc = min(mnc, ctot);
    }
    cout << mx << '\n';
    cout << mn << '\n';
    cout << mxr << '\n';
    cout << mnr << '\n';
    cout << mxc << '\n';
    cout << mnc << '\n';
}