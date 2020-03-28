#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef vector<pair<int, int>> vii;
typedef long long ll;
typedef unsigned long long ull;
#define pb(a, b) push_back(a, b)
#define eb(a, b) emplace_back(a, b)
#define inf INT_MAX

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    int arr[4];
    cin >> arr[0];
    cin >> arr[1];
    cin >> arr[3];
    cin >> arr[2];
    for (int j = 0; j < 2; j++){
        int highest = 0;
        for (int i = 0; i < 4; i++){
            if (arr[i] > arr[highest]){
                highest = i;
            }
        }
        arr[highest] = -1;
    }
    if (arr[0] == -1 && arr[3] == -1){
        cout << "trans";
    }
    else if (arr[1] == -1 && arr[2] == -1){
        cout << "trans";
    }
    else {
        cout << "cis";
    }
}
