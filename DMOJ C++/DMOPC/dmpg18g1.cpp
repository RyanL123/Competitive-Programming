#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef vector<pair<int, int>> vii;
typedef vector<int> vi;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
#define eb emplace_back
#define pb push_back
#define mp make_pair
#define srt(x) sort(x.begin(), x.end())
#define all(x) x.begin(), x.end()
#define inf 0x3f3f3f3f

const int MM = 1e6+5;
bool empty[MM];
int student[MM];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    stack<int> s;
    for (int i = 0, x; i < k; i++) {
        cin >> x;
        empty[x] = true;
    }
    int placed = 0, ptr = 1;
    for (int i = 1, x; i <= k+1; i++) {
        cin >> x;
        if (empty[x]) {
            empty[x] = false;
            placed++;
        }
        else student[x] = i;
    }
    while (placed < k) {
        if (ptr > n) ptr = 1;
        if (!s.empty() && empty[ptr]) {
            empty[ptr] = false;
            placed++;
            s.pop();
        }
        else if (student[ptr]) {
            s.push(student[ptr]);
            student[ptr] = 0;
        }
        ptr++;
    }
    cout << s.top() << '\n';
}