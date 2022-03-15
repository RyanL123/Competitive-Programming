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

int maxArea(vector<int>& height) {
    int lo = 0, hi = height.size()-1;
    int ret = -1;
    while (lo < hi) {
        if (height[lo] < height[hi]) {
            ret = max(ret, height[lo]*(hi-lo));
            lo++;
        }
        else {
            ret = max(ret, height[hi]*(hi-lo));
            hi--;
        }
    } 
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
}