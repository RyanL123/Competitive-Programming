#include <iostream>
#include <vector>

using namespace std;

int main(){
    string a;
    vector<string> input{};
    while (true){
        cin >> a;
        input.push_back(a);
        if (a.compare("TTYL") == 0){
            break;
        }
    }

    for (int i = 0; i < input.size(); i++){
        if (input[i].compare("CU") == 0){
            cout << "see you" << endl;
        }
        else if (input[i].compare(":-)") == 0){
            cout << "I'm happy" << endl;
        }
        else if (input[i].compare(":-(") == 0){
            cout << "I'm unhappy" << endl;
        }
        else if (input[i].compare(";-)") == 0){
            cout << "wink" << endl;
        }
        else if (input[i].compare(":-P") == 0){
            cout << "stick out my tongue" << endl;
        }
        else if (input[i].compare("(~.~)") == 0){
            cout << "sleepy" << endl;
        }
        else if (input[i].compare("TA") == 0){
            cout << "totally awesome" << endl;
        }
        else if (input[i].compare("CCC") == 0){
            cout << "Canadian Computing Competition" << endl;
        }
        else if (input[i].compare("CUZ") == 0){
            cout << "because" << endl;
        }
        else if (input[i].compare("TY") == 0){
            cout << "TY" << endl;
        }
        else if (input[i].compare("YW") == 0){
            cout << "you're welcome" << endl;
        }
        else if (input[i].compare("TTYL") == 0){
            cout << "talk to you later" << endl;
            break;
        }
        else{
            cout << input[i] << endl;
        }
    }
}
