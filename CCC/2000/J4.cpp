#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>

using namespace std;

int main() {
    int n;
    vector<double> streams;
    cin >> n;
    while (n--){
        double a;
        cin >> a;
        streams.push_back(a);
    }
    int command;
    while (cin >> command){
        if (command == 77){
            break;
        }
        if (command == 99){
            int num;
            double percent;
            cin >> num >> percent;
            streams.insert(streams.begin()+num, streams[num-1]*(1-(percent/100)));
            streams[num-1] *= percent/100;
        }
        else {
            int num;
            cin >> num;
            streams[num-1] += streams[num];
            streams.erase(streams.begin()+num);
        }
    }
    for (int i = 0; i < streams.size(); i++){
        cout << round(streams[i]) << " ";
    }
}