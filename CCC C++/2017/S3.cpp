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

int freq[4010];
int num[4010];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, highest = 0;
    cin >> n;
    for (int i = 0; i < n; i++){
    	int x;
    	cin >> x;
    	highest = max(highest, x);
    	freq[x]++;
    }
    int maxL = 0;
    for (int i = 2; i <= 2*highest; i++){
    	for (int j = 1; j <= i/2; j++){
    		int x = j, y = i-x;
    		if (x == y){
    			num[i] += freq[x]/2;
    		}
    		else {
    			num[i] += min(freq[x], freq[y]);
    		}
    	}
    	maxL = max(maxL, num[i]);
    }
    int count = 0;
    for (int i = 0; i <= 4000; i++){
    	if (num[i] == maxL) count++;
    }
    cout << maxL << " " << count << endl;
}
	