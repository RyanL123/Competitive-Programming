#include <bits/stdc++.h>

using namespace std;

int needle[27];
int haystack[27];
unordered_set<long long> used;
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    string n, h;
    cin >> n >> h;
    if (n.length() > h.length()){
        cout << 0 << endl;
        return 0;
    }
    for (int i = 0; i < n.length(); i++){
        needle[n[i]-97]++;
        haystack[h[i]-97]++;
    }
    hash<string> rhash;
    int lPtr = 0, rPtr = n.length()-1;
    while (rPtr < h.length()){
        bool sub = true;
        for (int a = 0; a < 27; a++){
            if (needle[a] != haystack[a]){
                sub = false;
                break;
            }
        }
        if (sub) used.insert(rhash(h.substr(lPtr, n.length())));
        haystack[h[lPtr]-97]--;
        lPtr++;
        rPtr++;
        if (rPtr < h.length()) haystack[h[rPtr]-97]++;
    }
    cout << used.size() << endl;
}
