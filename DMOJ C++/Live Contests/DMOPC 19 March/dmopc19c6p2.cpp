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

bool sieve[1000010];
int factCnt[1000010];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a, b;
    cin >> a >> b;
    for (int i = 0; i <= 1000000; i++) sieve[i] = true;
    for (int i = 2; i*i <= 1000000; i++){
        if (sieve[i]){
            for (int j = i*i; j <= 1000000; j += i){
                sieve[j] = false;
            }
        }
    }
    int num = a;
    while (num % 2 == 0){
        num /= 2;
        factCnt[2]++;
    }
    for (int i = 3; i <= ceil(sqrt(num))+1; i++){
        while (num % i == 0){
            factCnt[i]++;
            num /= i;
        }
    }
    if (num > 2) factCnt[num]++;
    vi factor;
    for (int i = 1; i <= ceil(sqrt(a))+1; i++){
        if (a % i == 0 && sieve[i]){
            if (find(factor.begin(), factor.end(), i) == factor.end()){
                factor.pb(i);
            }
            if (sieve[a/i] && find(factor.begin(), factor.end(), a/i) == factor.end()){
                factor.pb(a/i);
            }
        }
    }
    ull d = LONG_LONG_MAX;
    for (int i = 0; i < factor.size(); i++){
        ull tot = 0;
        int fact = b;
        if (factor[i] == 1) continue;
        while (true){
            fact = floor(fact/factor[i]);
            tot += fact;
            if (fact < 1) break;
        }
        tot = floor(tot/factCnt[factor[i]]);
        d = min(tot, d);
    }
    cout << d << "\n";
}