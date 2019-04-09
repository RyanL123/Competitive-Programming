#include <iostream>
#include <vector>

using namespace std;

int main(){

    int a,b,c;
    cin >> a >> b >> c;
    int sum = 0;

    vector<int> numbers{9,7,8,0,9,2,1,4,1,8};

    numbers.push_back(a);
    numbers.push_back(b);
    numbers.push_back(c);

    for (int i = 0; i < numbers.size(); i++){
        if(i%2 == 0){
           sum += numbers[i];
        }
        else{
            sum += numbers[i]*3;
        }
    }

    cout << "The 1-3-sum is " << sum;
}
