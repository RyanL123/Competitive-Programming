#include <iostream>
#include <map>

using namespace std;

int main() {
    for (int a = 0; a < 10; a++){
        int n, m;
        cin >> n >> m;
        char tower[m+1][n], c;
        string s;
        map<string, char> rules;
        for (int i = 0; i < 4; i++){
            cin >> s >> c;
            rules[s] = c;
        }
        for (int i = 0; i < n; i++){
            cin >> c;
            tower[0][i] = c;
        }
        cin >> c;
        for (int i = 0; i < m; i++){
            string left, right;
            for (int j = 0; j < n; j++){
                if (j == 0){
                    left = tower[i][n-1];
                    right = tower[i][1];
                }
                else if (j == n-1){
                    left = tower[i][n-2];
                    right = tower[i][0];
                }
                else {
                    left = tower[i][j-1];
                    right = tower[i][j+1];
                }
                tower[i+1][j] = rules[left+right];
            }
        }
        for (int i = 0; i < n; i++){
            cout << tower[m-1][i];
        }
        cout << endl;
    }
}
