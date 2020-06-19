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

bool check(ll k, vector<ll> &v){
    ll ret = 1;
    for (int i : v){
        ret *= i;
    }
    return ret >= k;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll k;
    cin >> k;
    string c = "codeforces";
    vector<ll> v (10, 1);
    int ptr = 0;
    while (!check(k, v)){
        v[ptr]++;
        ptr++;
        if (ptr == 10) ptr = 0;
    }
    for (int i = 0; i < 10; i++){
        cout << string(v[i], c[i]);
    }
}