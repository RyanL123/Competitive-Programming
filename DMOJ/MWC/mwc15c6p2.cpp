#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef vector<pair<int, int>> vii;
typedef long long ll;
typedef unsigned long long ull;
#define pb(a, b) push_back(a, b)
#define eb(a, b) emplace_back(a, b)
#define inf INT_MAX

bool prime[10010];
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    for (int i = 0; i <= 10000; i++){
        prime[i] = true;
    }
    for (int i = 2; i <= 10000; i++){
        if (prime[i]){
            for (int j = i*i; j <= 10000; j+=i){
                prime[j] = false;
            }
        }
    }
    for (int i = 0; i < n; i++){
        int it = arr[i]-1;
        while (!prime[it] && it >= 2){
            it--;
        }
        if (it < 2){
            cout << "no can do" << endl;
        }
        else {
            cout << it << endl;
        }
    }
}
