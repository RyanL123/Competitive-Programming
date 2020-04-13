#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef vector<pair<int, int>> vii;
typedef long long ll;
typedef unsigned long long ull;
#define pb(x) push_back(x)
#define mp(a, b) make_pair(a, b)
#define inf INT_MAX

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    for (int i = 0; i < 10; i++){
        int n;
        cin >> n;
        unordered_set<string> set;
        for (int j = 0; j < n; j++){
            string s;
            cin >> s;
            string output;
            int pointer = 0;
            bool flag = false;
            while (pointer < s.length()){
                if (s[pointer] == '@'){
                    flag = true;
                }
                if (s[pointer] == '.' && !flag){
                    pointer++;
                }
                else if (s[pointer] == '+'){
                    while (s[pointer] != '@'){
                        pointer++;
                    }
                    output += s[pointer];
                    pointer++;
                    flag = true;
                }
                else {
                    output += tolower(s[pointer]);
                    pointer++;
                }
            }
            set.insert(output);
        }
        cout << set.size() << endl;
    }
}