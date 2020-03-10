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

int arr[1000010];
int sorted[1000010];

ll binarySearch(ll lo, ll hi, ll val){
    while (lo < hi){
       ll m = (lo+hi)/2;
       if (abs(val+sorted[m]) < abs(val+sorted[m+1])){
            hi = m;
       }
       else if (lo == hi){
           return lo;
       }
       else {
           lo = m+1;
       }
    }
    return lo;
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    copy(arr, arr+n, sorted);
    sort(sorted,sorted+n);
    ll lowestDiff = LONG_LONG_MAX;
    ll lowestI = inf, lowestJ = inf;
    // Finds lowest diff and the values its obtained from
    // Uses binary search in NlogN + logN
    for (ll i = 0; i < n; i++){
        ll lowestIndex = binarySearch(i+1, n-1, sorted[i]);
        if (abs(sorted[i] + sorted[lowestIndex]) <= lowestDiff){
            if (min(i, lowestIndex)*10000000 + max(i, lowestIndex) <
                min(lowestI, lowestJ)*10000000 + max(lowestI, lowestJ)){
                lowestI = sorted[i];
                lowestJ = sorted[lowestIndex];
                lowestDiff = abs(sorted[i] + sorted[lowestIndex]);
            }
        }
    }
    // Linear search to locate the indices of the elements in the unsorted array
    int indexI = 0, indexJ = 0;
    for (int i = 0; i < n; i++){
        if (arr[i] == lowestI){
            indexI = i+1;
            lowestI = LONG_LONG_MIN;
        }
        else if (arr[i] == lowestJ){
            indexJ = i+1;
            lowestJ = LONG_LONG_MIN;
        }
    }
    cout << lowestDiff << endl;
    cout << min(indexI, indexJ) << " " << max(indexI, indexJ);
}