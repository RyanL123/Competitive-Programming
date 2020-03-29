#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef vector<pair<int, int>> vii;
typedef vector<int> vi;
typedef long long ll;
typedef unsigned long long ull;
#define pb(x) push_back(x)
#define mp(a, b) make_pair(a, b)
#define inf 0x3f3f3f3f

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    deque<char> dq;
    for (int i = 0; i < n; i++){
        char c;
        cin >> c;
        dq.push_back(c);
    }
    while (!dq.empty()){
        if (dq.size() == 1){
            cout << dq.front();
            dq.pop_front();
        }
        else if (dq.front() < dq.back()){
            cout << dq.front();
            dq.pop_front();
        }
        else if (dq.front() > dq.back()){
            cout << dq.back();
            dq.pop_back();
        }
        else {
            bool flag = false;
            for (int i = 1; i < dq.size()-1; i++){
                if (dq[i] < dq[dq.size()-i-1]){
                    cout << dq.front();
                    dq.pop_front();
                    flag = true;
                    break;
                }
                else if (dq[i] > dq[dq.size()-i-1]){
                    cout << dq.back();
                    dq.pop_back();
                    flag = true;
                    break;
                }
            }
            if (!flag) {
                cout << dq.front();
                dq.pop_front();
            }
        }
    }
}