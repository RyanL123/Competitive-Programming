#include <iostream>

using namespace std;

long fact(int n){
    if (n == 0 || n == 1){
        return 1;
    }
    else{
        return n*fact(n-1);
    }
}
int charCount[26];
int main() {
    int n, k;
    string s;
    cin >> n >> k;
    cin >> s;
    long long result = 0;
    long long factN = fact(n);
    for (int i = 0; i < n; i++){
        if (s[i] == 42){
            continue;
        }
        else{
            charCount[s[i]-97]++;
        }
    }
    if (k == 1){
        for (int i = 0; i < 26; i++){
            long long denominator = 1;
            for (int j = 0; j < 26; j++){
                if (j == i){
                    denominator *= fact(charCount[j]+1);
                }
                else{
                    denominator *= fact(charCount[j]);
                }
            }
            result += factN/denominator;
        }
    }
    else if (k == 2){
        for (int i = 0; i < 26; i++){
            for (int j = 0; j < 26; j++) {
                long long denominator = 1;
                charCount[j] += 1;
                for (int l = 0; l < 26; l++){
                    if (l == j || l == i){
                        denominator *= fact(charCount[l]+1);
                    }
                    else{
                        denominator *= fact(charCount[l]);
                    }
                }
                charCount[j] -= 1;
                result += factN / denominator;
            }
        }
    }
    else {
        long long denominator = 1;
        for (int i = 0; i < 26; i++){
            denominator *= fact(charCount[i]);
        }
        result = factN/denominator;
    }
    cout << result;
}