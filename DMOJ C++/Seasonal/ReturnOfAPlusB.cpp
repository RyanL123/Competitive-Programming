#include <iostream>

using namespace std;

int number(string a){
    if (a == "one"){
        return 1;
    }
    else if (a == "two"){
        return 2;
    }
    else if (a == "three"){
        return 3;
    }
    else if (a == "four"){
        return 4;
    }
    else if (a == "five"){
        return 5;
    }
    else if (a == "six"){
        return 6;
    }
    else if (a == "seven"){
        return 7;
    }
    else if (a == "eight"){
        return 8;
    }
    else if (a == "nine"){
        return 9;
    }
}

int main(){
    int n;
    string a,b;
    cin >> n;

    for (int i = 0; i < n; i++){
        cin >> a >> b;
        cout << number(a)+number(b) << endl;
    }

}
