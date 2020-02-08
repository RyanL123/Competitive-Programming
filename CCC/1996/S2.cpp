#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>

using namespace std;

string subtract(string s, char c){
    if (s[s.length()-1] >= c){
        s[s.length()-1] = (s[s.length()-1]-c)+48;
        return s;
    }
    else {
        int remainder = abs(s[s.length()-1] - c);
        int lastZero = s.length()-1;
        if (s[s.length()-1] == '0'){
            while (s[lastZero] == '0'){
                lastZero--;
            }
            s[lastZero+1] = '0';
            if (s[lastZero] == '0'){
                s[lastZero] = '9';
            }
            else {
                s[lastZero]--;
            }
            s[s.length()-1] = (10-remainder)+48;
            return s;
        }
        s[s.length()-2]--;
        s[s.length()-1] = (10-remainder)+48;
        lastZero = 0;
        while (s[lastZero] == '0'){
            lastZero++;
        }
        return s.substr(lastZero, s.length()-lastZero);
    }
}

void divisible(string s, string original){
    if (s == "0"){
        cout << "The number " << original << " is divisible by 11.\n";
        return;
    }
    cout << s << "\n";
    if (s == "11" || s == "0"){
        cout << "The number " << original << " is divisible by 11.\n";
    }
    else if (s.length() == 1 || (s.length() == 2 && s[1] > s[0])){
        cout << "The number " << original << " is not divisible by 11.\n";
    }
    else {
        int end = s.length()-1;
        if (s[end] == '0'){
            divisible(s.substr(0, end), original);
        }
        else {
            s = subtract(s.substr(0, end), s[end]);
            divisible(s, original);
        }
    }
}
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        string s;
        cin >> s;
        divisible(s, s);
    }
}