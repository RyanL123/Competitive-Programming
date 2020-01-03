#include <iostream>

using namespace std;

void build(int node, int start, int end, int tree[], int arr[]){
    if (start == end){
        tree[node] = arr[start];
    }
    else {
        int mid = (start + end)/2;
        // Recurse for left child
        build(2*node, start, mid, tree, arr);
        // Recurse for right child
        build(2*node+1, mid+1, end, tree, arr);
        // Current node is the sum of its children
        tree[node] = tree[2*node] + tree[2*node+1];
    }
}

int sum(int node, int start, int end, int treeStart, int treeEnd, int tree[]){
    if (start > end){
        return 0;
    }
    if (start == treeStart && end == treeEnd){
        return tree[node];
    }
    int mid = (treeStart + treeEnd)/2;
    return sum(node*2, start, min(end, mid), treeStart, mid, tree) +
    sum(node*2+1, max(start, mid+1), treeEnd, mid+1, treeEnd, tree);
}

int main() {
    int n;
    cin >> n;
    int arr[n], tree[4*n];
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    // Root node stored at index 1
    build(1, 0, n-1, tree, arr);
    cout << sum(0, 1, 2, 0, n-1, tree);
}