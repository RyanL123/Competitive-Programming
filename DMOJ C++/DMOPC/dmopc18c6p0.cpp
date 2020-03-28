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
    int arr[3];
    cin >> arr[0];
    cin >> arr[1];
    cin >> arr[2];
    if (arr[0] + arr[1] + arr[2] == 0){
        cout << "YES";
    }
    else if (arr[0] != 0 && arr[1] != 0 && arr[2] != 0){
        cout << "NO";
    }
    else {
        int dependant = 0;
        for (int i = 0; i < 3; i++){
            if (arr[i]){
                dependant++;
            }
        }
        if (dependant <= 1){
            cout << "YES";
        }
        else {
            for (int i = 0; i < 3; i++){
                if (arr[i] != 0){
                    if (arr[arr[i]-1]-1 == i){
                        cout << "NO";
                        return 0;
                    }
                }
            }
            cout << "YES";
        }
    }
}
