#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef vector<pair<int, int>> vii;
typedef vector<int> vi;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
#define pb push_back
#define mp make_pair
#define srt(x) sort(x.begin(), x.end())
#define inf 0x3f3f3f3f

bool isPrime(int x){
    for (int i = 2; i <= sqrt(x)+1; i++){
        if (x%i==0) return false;
    }
    return true;
}
// N-a = a*b
// (N-a)/a = b
// N/a - a/a = b
// N/a - 1 = b
// N/(b+1) = a
// Greedily minimize b
// If prime pay huge cost to subtract 1
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, cost = 0;
    cin >> N;
    while (N != 1){
        if (isPrime(N)){
            N--;
            cost += N;
            continue;
        }
        for (int i = 1; i <= sqrt(N); i++){
            if (N%(i+1) == 0){
                cost += i;
                N = N-(N/(i+1));
                break;
            }
        }
    }
    cout << cost << "\n";
}