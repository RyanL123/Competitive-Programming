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

map<string, int> standings;
map<string, int> standings2;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<pair<string, int>> rounds;
    for (int i = 0; i < n; i++){
        int score;
        string s;
        cin >> s >> score;
        standings[s] += score;
        rounds.eb(s, score);
    }
    int mx = 0;
    for (pair<string, int> p : standings){
        mx = max(mx, p.second);
    }
    for (int i = 0; i < n; i++){
        string name = rounds[i].first;
        standings2[name] += rounds[i].second;
        if (standings2[name] >= mx && standings[name] == mx){
            cout << name << '\n';
            return 0;
        }
    }
}