#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>
#include <utility>

using namespace std;

int main() {
    int n;
    cin >> n;
    long double speed = 0;
    vector<pair<long double, long double>> dis;
    for (int i = 0; i < n; i++){
        long double a, b;
        cin >> a >> b;
        dis.push_back(make_pair(a, b));
    }
    sort(dis.begin(), dis.end());
    for (int i = 1; i < n; i++){
        long double speed1 = abs((dis[i].second - dis[i-1].second)/(dis[i].first-dis[i-1].first));
        if (speed1 > speed){
            speed = speed1;
        }
    }
    printf("%Lf", speed);
}
