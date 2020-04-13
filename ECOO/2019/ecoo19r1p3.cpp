#include <iostream>

using namespace std;

int main() {
    for (int a = 0; a < 10; a++) {
        int j, w, h, startC, startR, endC, endR;
        string s;
        cin >> j >> w >> h;
        char game[h][w];
        bool failed = false;
        for (int i = 0; i < h; i++) {
            cin >> s;
            for (int k = 0; k < w; k++) {
                game[i][k] = s[k];
                if (s[k] == 'L') {
                    startC = k;
                    startR = i;
                } else if (s[k] == 'G') {
                    endC = k;
                    endR = i;
                }
            }
        }
        while (startC != endC) {
            int jumpCount = 0;
            bool jumped = false;
            // Needs to jump
            if (game[startR][startC+1] == '@'){
                while (game[startR][startC+1] != '.'){
                    startR--;
                    jumpCount++;
                    jumped = true;
                    if (game[startR][startC] == '@'){
                        failed = true;
                        cout << startC + 2 << endl;
                        goto end;
                    }
                    else if (jumpCount > j || startR < 0 ){
                        failed = true;
                        cout << startC + 2 << endl;
                        goto end;
                    }
                }
            }
            if (failed) break;
            // Can land
            if (jumped) {
                startC+=2;
                while (game[startR+1][startC] != '#') {
                    if (game[startR][startC] == '@' || game[startR+1][startC] == '@') {
                        cout << startC << endl;
                        failed = true;
                        goto end;
                    }
                    startR++;
                }
            }
            if (!jumped && !failed){
                startC++;
            }
        }
        end: if (failed) continue;
        else cout << "CLEAR" << endl;
    }
}