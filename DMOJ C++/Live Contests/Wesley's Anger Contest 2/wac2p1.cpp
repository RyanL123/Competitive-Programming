#include <iostream>

using namespace std;

int main() {
    string christmas;
    cin >> christmas;
    if (christmas == "Saturday"){
        cout << "Sunday" << endl;
    }
    else if (christmas == "Wednesday"){
        cout << "Thursday" << endl;
    }
    else if (christmas == "Tuesday"){
        cout << "Wednesday" << endl;
    }
    else if (christmas == "Monday"){
        cout << "Tuesday" << endl;
    }
    else if (christmas == "Sunday"){
        cout << "Monday" << endl;
    }
    else if (christmas == "Friday"){
        cout << "Saturday" << endl;
    }
    else if (christmas == "Thursday"){
        cout << "Friday" << endl;
    }

}