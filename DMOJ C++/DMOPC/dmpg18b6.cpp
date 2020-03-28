#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef vector<pair<int, int>> vii;
typedef long long ll;
typedef unsigned long long ull;
#define pb(x) push_back(x)
#define mp(a, b) make_pair(a, b)
#define inf INT_MAX

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> cards;
    for (int i = 0; i < n; i++){
        int card;
        cin >> card;
        cards.pb(-card);
    }
    sort(cards.begin(), cards.end());
    int count = 1;
    int prev = cards[0]+k;
    while (true){
        auto first_it = lower_bound(cards.begin(), cards.end(), prev);
        int first = distance(cards.begin(), first_it);
        if (first_it == cards.end()){
            break;
        }
        count++;
        prev = cards[first]+k;
    }
    cout << count;
}