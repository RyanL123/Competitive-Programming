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


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        int ans = 0;
        stack<char> st;
        for (int i = 0; i < s.size(); i++){
            if (s[i] == '(') st.push(s[i]);
            else {
                if (st.empty() || st.top() == ')'){
                    ans++;
                }
                else st.pop();
            }
        }
        cout << ans << '\n';
    }
}