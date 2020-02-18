#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef vector<pair<int, int>> vii;
typedef long long ll;
typedef unsigned long long ull;
#define pb(x) push_back(x)
#define eb(x) emplace_back(x)
#define inf INT_MAX

int inDeg[8];
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    vector<int> todo[8];
    int x, y;
    inDeg[1] = 1;
    inDeg[4] = 2;
    inDeg[5] = 1;
    inDeg[7] = 1;
    todo[1].pb(7);
    todo[1].pb(4);
    todo[2].pb(1);
    todo[3].pb(4);
    todo[3].pb(5);
    while (true){
        cin >> x >> y;
        if (x == 0 && y == 0){
            break;
        }
        inDeg[y]++;
        todo[x].pb(y);
    }
    int count = 0;
    queue<int> q;
    while (true){
        bool flag = false;
        for (int i = 1; i < 8; i++){
            if (inDeg[i] == 0){
                flag = true;
                count++;
                inDeg[i]--;
                q.push(i);
                for (int j = 0; j < todo[i].size(); j++){
                    inDeg[todo[i][j]]--;
                }
                break;
            }
        }
        if (!flag){
            break;
        }
    }
    if (count != 7){
        cout << "Cannot complete these tasks. Going to bed.\n";
    }
    else {
        while (!q.empty()){
            cout << q.front() << " ";
            q.pop();
        }
    }
}