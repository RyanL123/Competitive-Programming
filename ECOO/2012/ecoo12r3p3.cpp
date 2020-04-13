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

bool num(char c){
    return c <= 57 && c >= 48;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for (int i = 0; i < 10; i++){
        string s;
        getline(cin, s);
        int n = s.length();
        deque<int> dq;
        for (int j = n-1; j >= 0; j--){
            if (num(s[j])){
                dq.push_front(s[j]-48);
            }
            else if (s[j] == '+'){
                int res = dq[0] + dq[1];
                dq.pop_front();
                dq.pop_front();
                dq.push_front(res);
            }
            else if (s[j] == '-'){
                int res = dq[0] - dq[1];
                dq.pop_front();
                dq.pop_front();
                dq.push_front(res);
            }
            else if (s[j] == '*'){
                int res = dq[0] * dq[1];
                dq.pop_front();
                dq.pop_front();
                dq.push_front(res);
            }
            else if (s[j] == 'q'){
                int res = dq[0] / dq[1];
                dq.pop_front();
                dq.pop_front();
                dq.push_front(res);
            }
            else if (s[j] == 'r'){
                int res = dq[0] % dq[1];
                dq.pop_front();
                dq.pop_front();
                dq.push_front(res);
            }
        }
        cout << dq[0] << "\n";
    }
}