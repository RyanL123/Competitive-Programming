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

bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
    int n = pushed.size();
    stack<int> s;
    int ptr1 = 0, ptr2 = 0;
    while (true) {
        if (ptr1 <= n-1) {
            s.push(pushed[ptr1++]);
        }
        while (!s.empty() && ptr2 <= n-1 && s.top() == popped[ptr2]) {
            s.pop();
            ptr2++;
        }
        if (ptr1 >= n && (ptr2 >= n || (!s.empty() && s.top() != popped[ptr2]))) {
            break;
        }
    }
    return s.empty();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vi pushed = {1,2,3,4,5}, popped = {4,5,3,2,1};
    cout << validateStackSequences(pushed, popped);
}