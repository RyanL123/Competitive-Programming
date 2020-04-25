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

bool cmp(pii a, pii b){
    if (a.first != b.first) return a.first < b.first;
    return a.second < b.second;
}

int minL[100005], maxR[100005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vii particles;
    for (int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        particles.pb(mp(x, y));
    }
    sort(particles.begin(), particles.end(), cmp);
    minL[0] = particles[0].second;
    for (int i = 1; i < n; i++){
        minL[i] = min(minL[i-1], particles[i].second);
    }
    maxR[n-1] = particles[n-1].second;
    for (int i = n-2; i >= 0; i--){
        maxR[i] = max(maxR[i+1], particles[i].second);
    }
    int cnt = 1;
    for (int i = 0; i < n-1; i++){
        if (minL[i] > maxR[i+1]) cnt++;
    }
    cout << cnt;
}
