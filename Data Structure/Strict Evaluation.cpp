#include <iostream>
#include <climits>
#include <cstdio>

using namespace std;

// Lazy tree stored as <increment val, set val>
// If a set val is pushed after increment val, increment val will be overridden to 0
// If a set value is pushed before increment val, increment val will increment the set val instead
void pushIncrement(int node, int tree[], pair<int, int> lazy[]){
    // There is a Set value
    if (lazy[node].second != -1){
        // Update value in seg tree
        tree[node*2] += lazy[node].first + lazy[node].second;
        tree[node*2+1] += lazy[node].first + lazy[node].second;
        // Propagate children
        // Takes into account value of Set
        lazy[node*2].first += lazy[node].first + lazy[node].second;
        lazy[node*2+1].first += lazy[node].first + lazy[node].second;
        lazy[node*2].second = -1;
        lazy[node*2+1].second = -1;
    }
    // There is not a Set value
    else {
        tree[node*2] += lazy[node].first;
        tree[node*2+1] += lazy[node].first;
        lazy[node*2].first += lazy[node].first;
        lazy[node*2].first += lazy[node].first;
    }
    // Clear value in lazy after propagation
    lazy[node].first = 0;
}

void pushSet(int node, int tree[], pair<int, int> lazy[]){
    // Update to set value
    if (lazy[node].second != -1){
        // Update value in seg tree
        tree[node*2] = lazy[node].second;
        tree[node*2+1] = lazy[node].second;
        // Propagate children
        // Overrides value of increment
        lazy[node*2].first = 0;
        lazy[node*2+1].first = 0;
        lazy[node*2].second = lazy[node].second;
        lazy[node*2+1].second = lazy[node].second;
    }
    else {
        return;
    }
}

void buildMin(int node, int tl, int tr, int tree[], int arr[]){
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

int queryMin(int node, int tl, int tr, int l, int r, int tree[], int arr[], pair<int, int> lazy[]){
    if (l > r){
        return INT_MAX;
    }
    if (tl == l && tr == r){
        return tree[node];
    }
    else{
        int mid = (tl + tr)/2;
        int leftNode = queryMin(node*2, tl, mid, l, min(r, mid), tree, arr, lazy);
        int rightNode = queryMin(node*2+1, mid+1, tr, max(mid+1, l), r, tree, arr, lazy);
        return min(leftNode, rightNode);
    }
}

void incrementRange(int node, int tl, int tr, int l, int r, int x, int tree[], pair<int, int> lazy[]){
    // No overlap, skip
    if (l > r){
        return;
    }
    if (tl == l && tr == r){
        // Complete overlap, only one update is needed for each tree
        tree[node] += x;
        lazy[node].first += x;
    }
    else {
        // Partial overlap, propagate children recursively
        pushIncrement(node, tree, lazy);
        int mid = (tl + tr)/2;
        incrementRange(node*2, tl, mid, l, min(r, mid), x, tree, lazy);
        incrementRange(node*2+1, mid+1, tr, max(mid+1, l), r, x, tree, lazy);
    }
}

void setRange(int node, int tl, int tr, int l, int r, int x, int tree[], pair<int, int> lazy[]){
    if (l > r){
        return;
    }
    if (tl == l && tr == r){
        tree[node] = x;
        lazy[node].second = -1;
    }
    else {
        pushSet(node, tree, lazy);
        int mid = (tl + tr)/2;
        setRange(node*2, tl, mid, l, min(mid, r), x, tree, lazy);
        setRange(node*2+1, mid+1, tr, max(mid+1, l), r, x, tree, lazy);
    }
}

int main() {
    int n, q;
    cin >> n >> q;
    int arr[n], tree[4*n];
    pair<int, int> lazy[4*n];
    for (int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    // Initialize lazy tree
    for (int i = 0; i < 4*n; i++){
        lazy[i] = make_pair(0, -1);
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
            cout << queryMin(1, 0, n-1, l-1, r-1, tree, arr, lazy) << endl;
        }
    }
}