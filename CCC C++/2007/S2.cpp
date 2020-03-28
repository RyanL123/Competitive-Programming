#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <climits>
#include <tuple>

using namespace std;

int main() {
    int n, m;
    cin >> n;
    vector<tuple<int, int, int>> boxes;
    for (int i = 0; i < n; i++){
        int l, w, h;
        cin >> l >> w >> h;
        boxes.push_back(make_tuple(l, w, h));
    }
    cin >> m;
    for (int i = 0; i < m; i++){
        int l, w, h, lowest = INT_MAX;
        cin >> l >> w >> h;
        for (int j = 0; j < n; j++){
            int bl = get<0>(boxes[j]);
            int bw = get<1>(boxes[j]);
            int bh = get<2>(boxes[j]);
            if (l <= bl && w <= bw && h <= bh && bl*bw*bh < lowest){
                lowest = bl*bw*bh;
            }
            if (l <= bl && h <= bw && w <= bh && bl*bw*bh < lowest){
                lowest = bl*bw*bh;
            }
            if (w <= bl && l <= bw && h <= bh && bl*bw*bh < lowest){
                lowest = bl*bw*bh;
            }
            if (w <= bl && h <= bw && l <= bh && bl*bw*bh < lowest){
                lowest = bl*bw*bh;
            }
            if (h <= bl && w <= bw && l <= bh && bl*bw*bh < lowest){
                lowest = bl*bw*bh;
            }
            if (h <= bl && l <= bw && w <= bh && bl*bw*bh < lowest){
                lowest = bl*bw*bh;
            }
        }
        if (lowest == INT_MAX){
            cout << "Item does not fit." << endl;
        }
        else {
            cout << lowest << endl;
        }
    }
}