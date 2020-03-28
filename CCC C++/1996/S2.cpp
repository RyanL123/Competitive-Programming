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

string subtract(string s, int n){
    if (s.length() == 2){
        int ones = s[s.length()-1]-48;
        int tens = (s[s.length()-2]-48)*10;
        int ans = tens + ones - n;
        string result;
        if (ans >= 10){
            ones = ans%10;
            tens = (ans%100-ones)/10;
            result += (char)(tens+48);
            result += (char)(ones+48);
            return result;
        }
        else {
            result += (char)(ans+48);
            return result;
        }
    }
    int ones = s[s.length()-1]-48;
    int tens = (s[s.length()-2]-48)*10;
    int hundreds = (s[s.length()-3]-48)*100;
    int ans = hundreds + tens + ones - n;
    if (ans >= 100){
        ones = ans%10;
        tens = (ans%100-ones)/10;
        hundreds = (ans%1000-tens-ones)/100;
        string result;
        result += (char)(hundreds+48);
        result += (char)(tens+48);
        result += (char)(ones+48);
        return s.substr(0,s.length()-3)+result;
    }
    else if (ans >= 10){
        ones = ans%10;
        tens = (ans%100-ones)/10;
        string result;
        result += (char)(tens+48);
        result += (char)(ones+48);
        return s.substr(0,s.length()-3) + "0" + result;
    }
    else {
        ones = ans%10;
        string result;
        result += (char)(ones+48);
        return s.substr(0,s.length()-3) + "00" +result;
    }
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    string s;
    cin >> n;
    while (n--){
        cin >> s;
        string original = s;
        cout << s << endl;
        int lastDigit = s[s.length()-1]-48;
        s = s.substr(0, s.length()-1);
        while (s.length() > 2){
            s = subtract(s, lastDigit);
            cout << s << endl;
            lastDigit = s[s.length()-1]-48;
            s = s.substr(0, s.length()-1);
        }
        s = subtract(s, lastDigit);
        cout << s << endl;
        if (s == "11"){
            cout << "The number " + original + " is divisible by 11." << endl;
        }
        else {
            cout << "The number " + original + " is not divisible by 11." << endl;
        }
    }
}
