#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef vector<pair<int, int>> vii;
typedef vector<int> vi;
typedef long long ll;
typedef unsigned long long ull;
#define pb(x) push_back(x)
#define mp(a, b) make_pair(a, b)
#define inf INT_MAX

struct node{
    ll prefixSum = LONG_LONG_MIN;
    ll suffixSum = LONG_LONG_MIN;
    ll totalSum = LONG_LONG_MIN;
    ll maxSubSum = LONG_LONG_MIN;
};

node segTree[400010];
ll arr[100010];

void combine(int node){
    segTree[node].totalSum = segTree[node*2].totalSum + segTree[node*2+1].totalSum;
    segTree[node].prefixSum = max(segTree[node*2].prefixSum, segTree[node*2].totalSum + segTree[node*2+1].prefixSum);
    segTree[node].suffixSum = max(segTree[node*2+1].suffixSum, segTree[node*2+1].totalSum + segTree[node*2].suffixSum);
    segTree[node].maxSubSum = max(segTree[node*2].suffixSum + segTree[node*2+1].prefixSum, max(segTree[node*2].maxSubSum, segTree[node*2+1].maxSubSum));
    segTree[node].maxSubSum = max(segTree[node].maxSubSum, max(segTree[node].prefixSum, segTree[node].suffixSum));
}

void build(int node, int l, int r){
    if (l == r){
        segTree[node].totalSum = arr[l];
        segTree[node].prefixSum = arr[l];
        segTree[node].suffixSum = arr[l];
        segTree[node].maxSubSum = arr[l];
    }
    else {
        int mid = (l+r)/2;
        build(node*2, l, mid);
        build (node*2+1, mid+1, r);
        combine(node);
    }
}

void update(int node, int l, int r, int pos, ll val){
    if (l == r){
        segTree[node].totalSum = val;
        segTree[node].suffixSum = val;
        segTree[node].prefixSum = val;
        segTree[node].maxSubSum = val;
    }
    else {
        int mid = (l+r)/2;
        if (pos <= mid){
            update(node*2, l, mid, pos, val);
        }
        else {
            update(node*2+1, mid+1, r, pos, val);
        }
        combine(node);
    }
}

node query(int index, int l, int r, int tl, int tr){
    node ans;
    ans.suffixSum = LONG_LONG_MIN;
    ans.prefixSum = LONG_LONG_MIN;
    ans.maxSubSum = LONG_LONG_MIN;
    ans.totalSum = LONG_LONG_MIN;
    if (r < tl || tr < l){
        return ans;
    }
    if (l <= tl && tr <= r){
        return segTree[index];
    }
    int mid = (tl+tr)/2;
    if (l > mid){
        return query(index*2+1, max(l, mid+1), r, mid+1, tr);
    }
    else if (r <= mid){
        return query(index*2, l, min(r, mid), tl, mid);
    }
    node left = query(index*2, l, min(r, mid), tl, mid);
    node right = query(index*2+1, max(l, mid+1), r, mid+1, tr);
    ans.totalSum = left.totalSum + right.totalSum;
    ans.prefixSum = max(left.totalSum + right.prefixSum, left.prefixSum);
    ans.suffixSum = max(right.totalSum + left.suffixSum, right.suffixSum);
    ans.maxSubSum = max(left.suffixSum + right.prefixSum, max(left.maxSubSum, right.maxSubSum));
    ans.maxSubSum = max(ans.maxSubSum, max(ans.prefixSum, ans.suffixSum));
    return ans;
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    build(1, 0, n-1);
    for (int k = 0; k < q; k++){
        char c;
        cin >> c;
        if (c == 'S'){
            int i;
            ll x;
            cin >> i >> x;
            update(1, 0, n-1, i-1, x);
        }
        else if (c == 'Q'){
            int l, r;
            cin >> l >> r;
            cout << query(1, l-1, r-1, 0, n-1).maxSubSum << endl;
        }
    }
}
