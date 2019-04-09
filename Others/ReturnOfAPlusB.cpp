#include <iostream>
#include <vector>

using namespace std;
int main(){
    int a,b,n;
    cin >> n;
    vector<int> output{};

    for (int i = 0; i < n; i++){
        cin >> a >> b;
        output.push_back(a+b);
    }

    for (int i = 0; i < n; i++){
        cout << output[i] << endl;
    }
}
