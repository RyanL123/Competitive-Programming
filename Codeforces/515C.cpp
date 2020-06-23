#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef vector<pair<int, int>> vii;
typedef vector<int> vi;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
#define eb emplace_back
#define pb push_back
#define mp make_pair
#define srt(x) sort(x.begin(), x.end())
#define all(x) x.begin(), x.end()
#define inf 0x3f3f3f3f

int frq[8];

void add(int x){
    if (x == 2) frq[2]++;
    else if (x == 3) frq[3]++;
    else if (x == 4) frq[2]+=2;
    else if (x == 5) frq[5]++;
    else if (x == 6) frq[2]++, frq[3]++;
    else if (x == 7) frq[7]++;
    else if (x == 8) frq[2]+=3;
    else if (x == 9) frq[3]+=2;
}

void sub(int x){
    if (x == 2) frq[2]--;
    else if (x == 3) frq[3]--;
    else if (x == 4) frq[2]-=2;
    else if (x == 5) frq[5]--;
    else if (x == 6) frq[2]--, frq[3]--;
    else if (x == 7) frq[7]--;
    else if (x == 8) frq[2]-=3;
    else if (x == 9) frq[3]-=2;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string a;
    int n;
    cin >> n >> a;
    for (int i = 0; i < n; i++){
        int x = a[i]-'0';
        while (x > 1){
            add(x);
            x--;
        }
    }
    for (int i = 7; i > 1; i--){
        while (frq[i] > 0){
            int x = i;
            while (x > 1) {
                sub(x);
                x--;
            }
            cout << (char)(i+'0');
        }
    }
}