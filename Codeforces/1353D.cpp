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

struct seg{
    int l, r, sz;
};

struct cmp{
    bool operator()(seg const &a, seg const &b){
        return a.sz < b.sz || (a.sz == b.sz && a.l > b.l);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        int cur = 1;
        int a[n+1];
        priority_queue<seg, vector<seg>, cmp> pq;
        pq.push({1, n, n});
        while (cur <= n){
            seg s = pq.top();
            pq.pop();
            if ((s.r-s.l+1)%2){
                int m = (s.r+s.l)/2;
                a[m] = cur;
                pq.push(seg{s.l, m-1, s.sz/2});
                pq.push(seg{m+1, s.r, s.sz/2});
            }
            else {
                int m = (s.r+s.l-1)/2;
                a[m] = cur;
                pq.push(seg{s.l, m-1, s.sz/2-1});
                pq.push(seg{m+1, s.r, s.sz/2});
            }
            cur++;
        }
        for (int i = 1; i <= n; i++){
            cout << a[i] << ' ';
        }
        cout << '\n';
    }
}