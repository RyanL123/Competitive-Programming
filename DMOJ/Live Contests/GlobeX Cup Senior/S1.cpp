#include <iostream>
#include <map>

using namespace std;

int main() {
    int n, k, planetsSize;
    cin >> n >> k;
    map<int, int> planets;
    for (int i = 0; i < n; i++){
        int a;
        cin >> a;
        cout << planets[a] << endl;
        planets[a]++;
    }
    planetsSize = planets.size();
    cout << planetsSize;
}