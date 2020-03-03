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

string plan[410];
int charCount[410][3];

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++){
        cin >> plan[i];
        for (int j = 0; j < m; j++){
            if (plan[i][j] == '.') charCount[i][0]++;
            else if (plan[i][j] == 'X') charCount[i][1]++;
            else charCount[i][2]++;
        }
    }
    if (n == 1){
        cout << "YES" << endl;
        for (int i = 0; i < m; i++){
            if (plan[0][i] == '?') cout << "X";
            else cout << plan[0][i];
        }
    }
    else {
        if (charCount[0][2] == 0 && charCount[1][2] == 0 && plan[0] == plan[1]){
            cout << "NO" << endl;
        }
        else {
           cout << "YES" << endl;
           for (int i = 0; i < m; i++){
               if (plan[0][i] != '?') cout << plan[0][i];
               else {
                   if (plan[1][i] == '.') cout << "X";
                   else cout << ".";
               }
           }
           cout << endl;
            for (int i = 0; i < m; i++){
                if (plan[1][i] != '?') cout << plan[1][i];
                else {
                    if (plan[1][i] == '.') cout << "X";
                    else if (plan[1][i] == 'X') cout << ".";
                    else cout << "X";
                }
            }
        }
    }
}