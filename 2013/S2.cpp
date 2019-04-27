#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main() {
    int w,n,truck,count = 0;
    cin >> w >> n;
    vector<int> bridge;
    for (int i = 0; i < n; i++){
        cin >> truck;
        if (bridge.size() < 4){
            bridge.push_back(truck);
        }
        else{
            bridge.erase(bridge.begin());
            bridge.push_back(truck);
        }
        if (accumulate(bridge.begin(),bridge.end(), 0) <= w){
            count++;
        }
        else{
            break;
        }
    }
    cout << count;
}