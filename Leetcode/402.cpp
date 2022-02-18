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

string removeKdigits(string num, int k) {
    int n = num.size();
    // remove all but one
    if (n <= k) return "0";
    // n > k
    int previous = 0;
    int remaining = n-k;
    string ans = "";
    while (remaining) {
        int min = 10, minIndex = 0;
        for (int i = previous; i <= n-remaining; i++) {
            if (num[i] - '0' < min) {
                min = num[i] - '0', minIndex = i;
            }
        }
        previous = minIndex+1;
        if (!(ans == "" && num[minIndex] == '0')) ans += num[minIndex];
        remaining--;
    }
    if (ans == "") return "0";
    return ans;
} 

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << removeKdigits("10200", 1) << endl;
}