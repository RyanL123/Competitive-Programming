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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, first = 1;
    while (cin >> n) {
        if (!first) std::cout << endl;
        else first = 0;
        string names;
        cin.ignore();
        getline(cin, names, '\n');
        stringstream s(names);
        unordered_map<int, string> order;
        unordered_map<string, int> savings;
        string name;

        for (int i = 0; i < n; i++) {
            s >> name;
            order[i] = name;
        }
        
        int amount, m;
        for (int i = 0; i < n; i++) {
            cin >> name >> amount >> m;
            if (m != 0) savings[name] -= amount - amount % m;

            string p;
            for (int j = 0; j < m; j++) {
                cin >> p;
                savings[p] += amount/m;
            }
        }
        for (int i = 0; i < n; i++) {
            std::cout << order[i] << ' ' << savings[order[i]] << endl;
        }
    }
}