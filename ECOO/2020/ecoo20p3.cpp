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

bool padding(string s){
    for (int i = 0; i < s.length(); i++){
        if (s[i] == '*') return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        for (int i = 0; i < n; i++){
            int h, w;
            cin >> h >> w;
            string cap[h];
            bool seg[8];
            memset(seg, false, sizeof(seg));
            for (int j = 0; j < h; j++){
                cin >> cap[j];
            }
            int topH = 0, midH = 0, botH = 0, L = -1, R = -1;
            // Find horizontal edges
            for (int j = 0; j < h; j++){
                // Make sure not padding
                if (padding(cap[j])) continue;
                int l = 0, r = 0;
                // Find first occurrence of *
                for (int k = 0; k < w; k++){
                    if (cap[j][k] == '*'){
                        l = k;
                        break;
                    }
                }
                // Find last occurrence of *
                for (int k = w-1; k >= 0; k--){
                    if (cap[j][k] == '*'){
                        r = k;
                        break;
                    }
                }
                // Detect horizontal edge
                bool horizontal, top = false, bottom = false, tl = false, tr = false, bl = false, br = false;
                if (l == 0 && r == w-1) continue;
                if (j != 0 && l != 0 && cap[j-1][l-1] == '*') tl = true;
                if (j != 0 && r != w-1 && cap[j-1][r+1] == '*') tr = true;
                if (j != h-1 && l != 0 && cap[j+1][l-1] == '*') bl = true;
                if (j != h-1 && r != w-1 && cap[j+1][r+1] == '*') br = true;
                top = tl || tr, bottom = bl || br;
                horizontal = top || bottom;

                // Determine placement of horizontal edge
                // Make sure this edge has the same alignment as other horizontal edges
                // Use first encountered horizontal edge as reference
                if (horizontal && ((l == L && r == R) || (L == -1 && R == -1))){
                    L = l, R = r;
                    if (top && bottom){
                        seg[4] = true;
                        midH = j;
                    }
                    else if (top){
                        seg[7] = true;
                        botH = j;
                    }
                    else if (bottom){
                        seg[1] = true;
                        topH = j;
                    }
                }
            }
            if (seg[1] && seg[7] && !seg[4]){
                cout << 0;
                continue;
            }
            if (!seg[1] && !seg[4] && !seg[7]){
                cout << 1;
                continue;
            }
            if (!seg[1] && seg[4] && !seg[7]){
                cout << 4;
                continue;
            }
            if (seg[1] && !seg[4] && !seg[7]){
                cout << 7;
                continue;
            }
            // Find vertical edges
            // Guaranteed to have 3 horizontal edges because of filtering done above
            for (int j = topH; j <= midH; j++) {
                if (cap[j][L-1] == '*') seg[2] = true;
                if (cap[j][R+1] == '*') seg[3] = true;
            }
            for (int j = midH; j <= botH; j++){
                if (cap[j][L-1] == '*') seg[5] = true;
                if (cap[j][R+1] == '*') seg[6] = true;
            }
            //   1
            // 2   3
            //   4
            // 5   6
            //   7
            if (seg[1] && !seg[2] && seg[3] && seg[4] && seg[5] && !seg[6] && seg[7]) cout << 2;
            else if (seg[1] && !seg[2] && seg[3] && seg[4] && !seg[5] && seg[6] && seg[7]) cout << 3;
            else if (seg[1] && seg[2] && !seg[3] && seg[4] && !seg[5] && seg[6] && seg[7]) cout << 5;
            else if (seg[1] && seg[2] && !seg[3] && seg[4] && seg[5] && seg[6] && seg[7]) cout << 6;
            else if (seg[1] && seg[2] && seg[3] && seg[4] && seg[5] && seg[6] && seg[7]) cout << 8;
            else if (seg[1] && seg[2] && seg[3] && seg[4] && !seg[5] && seg[6] && seg[7]) cout << 9;
        }
        cout << '\n';
    }
}
