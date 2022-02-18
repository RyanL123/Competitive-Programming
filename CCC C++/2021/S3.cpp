#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MM = 4e5+5;
ll N, P[MM], W[MM], D[MM];
ll cofL[MM], cofR[MM], conL[MM], conR[MM];

struct e {
    ll dir, p, w;
};

bool cmp(e a, e b) {
    if (a.p == b.p) return a.dir < b.dir;
    else return a.p < b.p;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    vector<e> v;
    for (int i = 1; i <= N; i++) {
        cin >> P[i] >> W[i] >> D[i];
        // 1 left, 2 right
        v.push_back({1, max((ll)0, P[i]-D[i]), W[i]});
        v.push_back({2, min((ll)1e9, P[i]+D[i]), W[i]});
    }
    sort(v.begin(), v.end(), cmp);
    ll leftPos = 0, rightPos = 0;
    for (int i = 0; i < 2*N; i++) {
        if (v[i].dir == 2) {
            rightPos = v[i].p;
            break;
        }
    }
    for (int i = 2*N-1; i >= 0; i--) {
        if (v[i].dir == 1) {
            leftPos = v[i].p;
            break;
        }
    }
    ll cof = 0, con = 0;
    int ptr = 0;
    for (int i = 0; i < 2*N; i++) {
        int p = v[i].p;
        while (v[ptr].p < p) {
            cofR[i] = cof, conR[i] = con;
            if (v[ptr].dir == 2) {
                cof += v[ptr].w;
                con += v[ptr].w * (v[ptr].p - rightPos);
            }
            ptr++;
        }
        cofR[i] = cof, conR[i] = con;
    }
    ptr = 2*N-1, cof = 0, con = 0;
    for (int i = 2*N-1; i >= 0; i--) {
        int p = v[i].p;
        while (v[ptr].p > p) {
            cofL[i] = cof, conL[i] = con;
            if (v[ptr].dir == 1) {
                cof += v[ptr].w;
                con += v[ptr].w * (leftPos - v[ptr].p);
            }
            ptr--;
        }
        cofL[i] = cof, conL[i] = con;
    }
    ll ans = LONG_LONG_MAX;
    for (int i = 0; i < v.size(); i++) {
        ll cur = (v[i].p-rightPos)*cofR[i] - conR[i] + (leftPos-v[i].p)*cofL[i] - conL[i];
        ans = min(ans, cur);
    }
    cout << ans << '\n';
}