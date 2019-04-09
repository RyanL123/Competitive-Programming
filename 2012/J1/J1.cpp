#include <iostream>

using namespace std;

int main(){
    int a,b;
    cin >> a >> b;

    if(b > a){
        if (b-a <=20){
            cout << "You are speeding and your fine is $100.";
        }
        else if (b-a <= 30){
            cout << "You are speeding and your fine is $270.";
        }
        else{
            cout << "You are speeding and your fine is $500.";
        }

    }
    else{
        cout << "Congratulations, you are within the speed limit!";
    }
}
