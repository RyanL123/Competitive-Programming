#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    int n;
    cin >> n;
    while (n--){
        string s;
        cin >> s;
        string phone;
        int count = 0;
        for (int i = 0; i < s.length(); i++){
            if (count >= 10){
                break;
            }
            else if (s[i] == '-'){
                continue;
            }
            else if (s[i] <= 57){
                phone += (char)s[i];
                count++;
            }
            else if (65 <= s[i] && s[i] <= 67){
                phone += '2';
                count++;
            }
            else if (68 <= s[i] && s[i] <= 70){
                phone += '3';
                count++;
            }
            else if (71 <= s[i] && s[i] <= 73){
                phone += '4';
                count++;
            }
            else if (74 <= s[i] && s[i] <= 76){
                phone += '5';
                count++;
            }
            else if (77 <= s[i] && s[i] <= 79){
                phone += '6';
                count++;
            }
            else if (80 <= s[i] && s[i] <= 83){
                phone += '7';
                count++;
            }
            else if (84 <= s[i] && s[i] <= 86){
                phone += '8';
                count++;
            }
            else if (87 <= s[i] && s[i] <= 90){
                phone += '9';
                count++;
            }
        }
        for (int i = 0; i < phone.length(); i++){
            if (i == 2 || i == 5){
                cout << phone[i] << "-";
            }
            else {
                cout << phone[i];
            }
        }
        cout << endl;
    }
}
