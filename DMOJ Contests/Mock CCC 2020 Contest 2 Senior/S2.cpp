#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <climits>
#include <deque>

using namespace std;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    deque<char> d;
    for (int i = 0; i < n; i++){
        char c;
        cin >> c;
        if (c <= d.front()){
            d.push_front(c);
        }
        else {
            d.push_back(c);
        }
    }
    for (int i = 0; i < n; i++){
        cout << d.front();
        d.pop_front();
    }
}