#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    int k;
    string s;
    cin >> k >> s;
    string original = s;
    int letterCount[27], highest = 1;
    for (int i = 1; i <= 26; i++){
        letterCount[i] = 0;
    }
    for (int i = 0; i < k; i++){
        letterCount[original[i]-96]++;
    }
    for (int j = 1; j <= 26; j++){
        if (letterCount[j] > letterCount[highest]){
            highest = j;
        }
    }
    s[k] = (original[k]+highest-97)%26+97;
    for (int i = k+1; i < s.length(); i++){
        letterCount[original[i-1]-96]++;
        letterCount[original[i-1-k]-96]--;
        highest = 1;
        for (int j = 1; j <= 26; j++){
            if (letterCount[j] > letterCount[highest]){
                highest = j;
            }
        }
        s[i] = (original[i]+highest-97)%26+97;
    }
    cout << s;
}