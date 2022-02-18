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

int lengthOfLongestSubstring(string s) {
    int n = s.size();
    int r = 0;
    int freq[200];
    memset(freq, 0, sizeof(freq));
    int ret = 0;
    for (int l = 0, r = 0; r < n; r++) {
        if (++freq[s[r]] > 1) {
            while (l <= r && freq[s[r]] > 1) {
                freq[s[l++]]--;
            }
        }
        ret = max(ret, r-l+1);
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << lengthOfLongestSubstring("abcabcbb") << endl;
}