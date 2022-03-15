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

string minRemoveToMakeValid(string s) {
    int n = s.size();
    int count = 0;
    string ret = "";
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            count++;
        }
        else if (s[i] == ')') {
            count--;
        }
        if (count < 0) {
            s[i] = '!';
            count++;
        }
    }
    if (count > 0) {
        for (int i = n-1; i >= 0; i--) {
            if (count <= 0) break;
            if (s[i] == '(') {
                s[i] = '!';
                count--;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (s[i] != '!') ret += s[i];
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << minRemoveToMakeValid("lee(t(c)o)de)");
}