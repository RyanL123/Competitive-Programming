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

struct node{
	int preSum;
	int sufSum;
	int totSum;
	int maxSum;
};

int A[1000010];
node t[4000010];

void combine(int n){
	node l = t[n*2], r = t[n*2+1];
	t[n].preSum = max(l.preSum, l.totSum + r.preSum);
	t[n].sufSum = max(r.sufSum, r.totSum + l.sufSum);
	t[n].totSum = l.totSum + r.totSum;
	t[n].maxSum = max(l.sufSum + r.preSum, max(l.maxSum, r.maxSum));
	t[n].maxSum = max(t[n].maxSum, max(t[n].preSum, t[n].sufSum));
}

void build(int n, int l, int r){
	if (l == r){
		t[n].preSum = A[l];
		t[n].sufSum = A[l];
		t[n].totSum = A[l];
		t[n].maxSum = A[l];
	}
	else {
		int m = (l+r)/2;
		build(n*2, l, m);
		build(n*2+1, m+1, r);
		combine(n);
	}
}

void update(int n, int l, int r, int pos, int v){
	if (l == r){
		t[n].preSum = v;
		t[n].sufSum = v;
		t[n].totSum = v;
		t[n].maxSum = v;
	}
	else {
		int m = (l+r)/2;
		if (pos <= m){
			update(n*2, l, m, pos, v);
		}
		else {
			update(n*2+1, m+1, r, pos, v);
		}
		combine(n);
	}
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n;
    for (int i = 0; i < n; i++){
    	cin >> A[i];
    }
    build(1, 0, n-1);
    cin >> m;
    cout << max(t[1].maxSum, 0) << "\n";
    for (int i = 0; i < m; i++){
    	int x, y;
    	cin >> x >> y;
    	update(1, 0, n-1, x, y);
    	cout << max(t[1].maxSum, 0) << "\n";
    }
}
	