#include <iostream>
#include <climits>
#include <cstdio>

typedef long long ll;

using namespace std;

void buildMin(int node, int tl, int tr, ll tree[], int arr[]){
    if (tl == tr){
        tree[node] = arr[tl];
    }
    else {
        int mid = (tl + tr)/2;
        buildMin(node*2, tl, mid, tree, arr);
        buildMin(node*2+1, mid+1, tr, tree, arr);
        tree[node] = min(tree[2*node], tree[2*node+1]);
    }
}

ll queryMin(int node, int tl, int tr, int l, int r, ll tree[], pair<ll, ll> lazy[]){
    // Not in range
    if (tl > r || tr < l || l > r){
        return LONG_LONG_MAX;
    }
    // Val not up to date
    if (lazy[node].first != 0){
        tree[node] += lazy[node].first;
        // Not leaf
        if (tl != tr){
            // No set val
            if (lazy[node*2].second == 0){
                lazy[node*2].first += lazy[node].first;
            }
            else {
                lazy[node*2].second += lazy[node].first;
            }
            if (lazy[node*2+1].second == 0){
                lazy[node*2+1].first += lazy[node].first;
            }
            else {
                lazy[node*2+1].second += lazy[node].first;
            }
        }
        lazy[node].first = 0;
    }
    else if (lazy[node].second != 0){
        tree[node] = lazy[node].second;
        // Not leaf
        if (tl != tr){
            lazy[node*2].second = lazy[node].second;
            lazy[node*2].first = 0;
            lazy[node*2+1].second = lazy[node].second;
            lazy[node*2+1].first = 0;
        }
        lazy[node].second = 0;
    }
    // Fully in range
    if (tl >= l && tr <= r){
        return tree[node];
    }
        // Partially in range
    else{
        int mid = (tl + tr)/2;
        ll leftNode = queryMin(node*2, tl, mid, l, min(r, mid), tree, lazy);
        ll rightNode = queryMin(node*2+1, mid+1, tr, max(mid+1, l), r, tree, lazy);
        return min(leftNode, rightNode);
    }
}

void incrementRange(int node, int tl, int tr, int l, int r, int x, ll tree[], pair<ll, ll> lazy[]){
    // Val not up to date
    if (lazy[node].first != 0){
        tree[node] += lazy[node].first;
        // Not leaf
        if (tl != tr){
            // No set val
            if (lazy[node*2].second == 0){
                lazy[node*2].first += lazy[node].first;
            }
            else {
                lazy[node*2].second += lazy[node].first;
            }
            if (lazy[node*2+1].second == 0){
                lazy[node*2+1].first += lazy[node].first;
            }
            else {
                lazy[node*2+1].second += lazy[node].first;
            }
        }
        lazy[node].first = 0;
    }
    else if (lazy[node].second != 0){
        tree[node] = lazy[node].second;
        // Not leaf
        if (tl != tr){
            lazy[node*2].second = lazy[node].second;
            lazy[node*2].first = 0;
            lazy[node*2+1].second = lazy[node].second;
            lazy[node*2+1].first = 0;
        }
        lazy[node].second = 0;
    }
    // Not in range
    if (tl > r || tr < l || l > r) return;
    // Fully in range
    if (tl >= l && tr <= r){
        // Add value, propagate to children
        tree[node] += x;
        // Not leaf node
        if (tl != tr){
            if (lazy[node*2].second == 0){
                lazy[node*2].first += x;
            }
            else {
                lazy[node*2].second += x;
            }
            if (lazy[node*2+1].second == 0){
                lazy[node*2+1].first += x;
            }
            else {
                lazy[node*2+1].second += x;
            }
        }
        return;
    }
        // Partially in range
    else {
        int mid = (tl + tr)/2;
        incrementRange(node*2, tl, mid, l, min(r, mid), x, tree, lazy);
        incrementRange(node*2+1, mid+1, tr, max(mid+1, l), r, x, tree, lazy);
        tree[node] = min(tree[node*2], tree[node*2+1]);
    }
}

void setRange(int node, int tl, int tr, int l, int r, int x, ll tree[], pair<ll, ll>lazy[]){
    if (lazy[node].first != 0){
        tree[node] += lazy[node].first;
        // Not leaf
        if (tl != tr){
            // No set val
            if (lazy[node*2].second == 0){
                lazy[node*2].first += lazy[node].first;
            }
            else {
                lazy[node*2].second += lazy[node].first;
            }
            if (lazy[node*2+1].second == 0){
                lazy[node*2+1].first += lazy[node].first;
            }
            else {
                lazy[node*2+1].second += lazy[node].first;
            }
        }
        lazy[node].first = 0;
    }
    else if (lazy[node].second != 0){
        tree[node] = lazy[node].second;
        // Not leaf
        if (tl != tr){
            lazy[node*2].second = lazy[node].second;
            lazy[node*2].first = 0;
            lazy[node*2+1].second = lazy[node].second;
            lazy[node*2+1].first = 0;
        }
        lazy[node].second = 0;
    }
    // Not in range
    if (tl > r || tr < l || l > r) return;
    // Fully in range
    if (tl >= l && tr <= r){
        // Add value, propagate to children
        tree[node] = x;
        // Not leaf node
        if (tl != tr){
            lazy[node*2].second = x;
            lazy[node*2].first = 0;
            lazy[node*2+1].second = x;
            lazy[node*2+1].first = 0;
        }
        return;
    }
        // Partially in range
    else {
        int mid = (tl + tr)/2;
        setRange(node*2, tl, mid, l, min(r, mid), x, tree, lazy);
        setRange(node*2+1, mid+1, tr, max(mid+1, l), r, x, tree, lazy);
        tree[node] = min(tree[node*2], tree[node*2+1]);
    }
}
int arr[100010];
ll tree[400010];
pair<ll, ll> lazy[400010];
int main() {
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    // Initialize lazy tree
    for (int i = 0; i < 4*n; i++){
        lazy[i].first = 0;
        lazy[i].second = 0;
        tree[i] = -1;
    }
    buildMin(1, 0, n-1, tree, arr);
    for (int i = 0; i < q; i++){
        int instruction;
        scanf("%d", &instruction);
        if (instruction == 1){
            int l, r, v;
            scanf("%d%d%d", &l, &r, &v);
            incrementRange(1, 0, n-1, l-1, r-1, v, tree, lazy);
        }
        else if (instruction == 2){
            int l, r, v;
            scanf("%d%d%d", &l, &r, &v);
            setRange(1, 0, n-1, l-1, r-1, v, tree, lazy);
        }
        else if (instruction == 3){
            int l, r;
            scanf("%d%d", &l, &r);
            printf("%lli\n", queryMin(1, 0, n-1, l-1, r-1, tree, lazy));
        }
    }
}