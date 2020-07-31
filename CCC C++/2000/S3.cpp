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

void cross(string from, string to) {
    cout << "Link from " << from << " to " << to << '\n';
}

map<string, vector<string>> adj;

bool bfs(string from, string to) {
    map<string, bool> visited;
    queue<string> q;
    q.push(from);
    visited[from] = true;
    while (!q.empty()) {
        string page = q.front();
        q.pop();
        for (string s : adj[page]) {
            if (!visited[s]) {
                visited[s] = true;
                q.push(s);
            }
        }
    }
    return visited[to];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string url, page, s;
        cin >> url;
        while (true) {
            getline(cin, s);
            if (s == "</HTML>") break;
            page += s;
        }
        bool href = false;
        int j = 0;
        while (j < page.size()) {
            if (href) {
                string to = "";
                while (page[j] != '\"') {
                    to += page[j];
                    j++;
                }
                href = false;
                adj[url].pb(to);
                cross(url, to);
            }
            else if (page.substr(j, 5) == "HREF=") {
                href = true;
                j += 6;
            }
            else j++;
        }
    }
    string from, to;
    while (true) {
        cin >> from;
        if (from == "The") break;
        cin >> to;
        if (bfs(from, to)) {
            cout << "Can surf from " << from << " to " << to << ".\n";
        }
        else cout << "Can't surf from " << from << " to " << to << ".\n";
    }
}