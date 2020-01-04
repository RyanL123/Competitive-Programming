#include <iostream>
#include <algorithm>
#include <cstdio>
#include <climits>

using namespace std;

pair<int, int> combineGCD(pair<int, int> a, pair<int, int> b){
    // First int is GCD, second int is number of times it appears
    int gcd = __gcd(a.first, b.first);
    // Left and right tree are equal to GCD, every node in left and right tree are equal
    if (a.first == b.first && b.first == gcd && a.first == gcd){
        return make_pair(gcd, a.second+b.second);
    }
    // Left tree is equal to gcd, every node in left tree is equal to gcd
    // And every right node is not
    else if (a.first == gcd){
        return make_pair(gcd, a.second);
    }
    // Right tree is equal to gcd, every node in right tree is equal to gcd
    // And every left node is not
    else if (b.first == gcd){
        return make_pair(gcd, b.second);
    }
    else{
        return make_pair(gcd, 0);
    }
}

void buildGCD(int node, int tl, int tr, pair<int, int> tree[], int arr[]){
    if (tl == tr){
        tree[node] = make_pair(arr[tl], 1);
    }
    else {
        int mid = (tl + tr)/2;
        // Recurse for left child
        buildGCD(2*node, tl, mid, tree, arr);
        // Recurse for right child
        buildGCD(2*node+1, mid+1, tr, tree, arr);
        // Current node is the sum of its children
        tree[node] = combineGCD(tree[2*node], tree[2*node+1]);
    }
}

pair<int, int> returnGCD(int node, int tl, int tr, int l, int r, pair<int, int> tree[]){
    // Unnecessary recursive call
    if (l > r){
        return make_pair(0, 0);
    }
    // Query is equal to a pre computed value in the tree
    if (tl == l && tr == r){
        return tree[node];
    }
    // Query falls partially within both left and right child
    int mid = (tl + tr)/2;
    pair<int, int> GCDLeft = returnGCD(node*2, tl, mid, l, min(r, mid), tree);
    pair<int, int> GCDRight = returnGCD(node*2+1, mid+1, tr, max(l, mid+1), r, tree);
    return combineGCD(GCDLeft, GCDRight);
}

void updateGCD(int node, int tl, int tr, int pos, int x, pair<int, int> tree[]){
    // Leaf node
    if (tl == tr){
        tree[node] = make_pair(x,1);
    }
    else {
        int mid = (tl + tr)/2;
        // Recurse for left and right child
        if (pos <= mid){
            updateGCD(node*2, tl, mid, pos, x, tree);
        }
        else {
            updateGCD(node*2+1, mid+1, tr, pos, x, tree);
        }
        // Update parent
        tree[node] = combineGCD(tree[node*2], tree[node*2+1]);
    }
}

void buildMin(int node, int tl, int tr, int tree[], int arr[]){
    // Leaf node
    if (tl == tr){
        tree[node] = arr[tl];
    }
    else {
        int mid = (tl + tr)/2;
        // Recurse for left child
        buildMin(2*node, tl, mid, tree, arr);
        // Recurse for right child
        buildMin(2*node+1, mid+1, tr, tree, arr);
        // Current node is the sum of its children
        tree[node] = min(tree[2*node], tree[2*node+1]);
    }
}

int returnMin(int node, int tl, int tr, int l, int r, int tree[]){
    // Unnecessary recursive call
    if (l > r){
        return INT_MAX;
    }
    // Query is equal to a pre computed value in the tree
    if (tl == l && tr == r){
        return tree[node];
    }
    // Query falls partially within both left and right child
    int mid = (tl + tr)/2;
    int minLeft = returnMin(node*2, tl, mid, l, min(r, mid), tree);
    int minRight = returnMin(node*2+1, mid+1, tr, max(l, mid+1), r, tree);
    return min(minLeft, minRight);
}

void updateMin(int node, int tl, int tr, int pos, int x, int tree[]){
    // Leaf node
    if (tl == tr){
        tree[node] = x;
    }
    else {
        int mid = (tl + tr)/2;
        // Recurse for left and right child
        if (pos <= mid){
            updateMin(node*2, tl, mid, pos, x, tree);
        }
        else {
            updateMin(node*2+1, mid+1, tr, pos, x, tree);
        }
        // Update parent
        tree[node] = min(tree[node*2], tree[node*2+1]);
    }
}

int main() {
    int n, q;
    char instruction;
    cin >> n >> q;
    int arr[n], minTree[4*n];
    pair<int, int> GCDTree[4*n];
    for (int i = 0; i < n; i++){
        scanf("%i", &arr[i]);
    }
    // Root node stored at index 1
    buildGCD(1, 0, n-1, GCDTree, arr);
    buildMin(1, 0, n-1, minTree, arr);
    for (int i = 0; i < q; i++){
        cin >> instruction;
        if (instruction == 'C'){
            int x, v;
            scanf("%i%i", &x, &v);
            updateGCD(1, 0, n-1, x-1, v, GCDTree);
            updateMin(1, 0, n-1, x-1, v, minTree);
        }
        else if (instruction == 'M'){
            int l, r;
            scanf("%i%i", &l, &r);
            printf("%i\n", returnMin(1, 0, n-1, l-1, r-1, minTree));
        }
        else if (instruction == 'G'){
            int l, r;
            scanf("%i%i", &l, &r);
            printf("%i\n", returnGCD(1, 0, n-1, l-1, r-1, GCDTree).first);
        }
        else if (instruction == 'Q'){
            int l, r;
            scanf("%i%i", &l, &r);
            printf("%i\n", returnGCD(1, 0, n-1, l-1, r-1, GCDTree).second);
        }
    }
}