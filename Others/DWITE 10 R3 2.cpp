#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <climits>
#include <set>

using namespace std;

int main() {
    for (int i = 0; i < 5; i++){
        int a;
        cin >> a;
        int count = 0;
        vector<pair<int, int>> vec;
        for (int j = 1; j <= a; j++){
            for (int k = 1; k <= a; k++){
                if (k*j <= a){
                    if (find(vec.begin(), vec.end(), make_pair(k, j)) == vec.end() &&
                        find(vec.begin(), vec.end(), make_pair(j, k)) == vec.end()
                    ){
                        count++;
                    }
                    vec.push_back(make_pair(k, j));
                    vec.push_back(make_pair(j, k));
                }
            }
        }
        cout << count << endl;
    }
}