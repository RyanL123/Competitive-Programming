#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>
#include <utility>

using namespace std;

double dis[200010];
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    double speed = 0;
    vector<pair<int, int>> dis;
    for (int i = 0; i < n; i++){
        double a, b;
        cin >> a >> b;
        dis.push_back(make_pair(a, b));
    }
    sort(dis.begin(), dis.end());
    for (int i = 1; i < dis.size(); i++){
        double speed1 = (double)abs(dis[i].second - dis[i-1].second)/abs(dis[i].first-dis[i-1].first);
        if (speed1 > speed){
            speed = speed1;
        }
    }
    cout << speed << endl;
}
