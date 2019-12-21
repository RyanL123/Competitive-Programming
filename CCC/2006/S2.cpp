#include <iostream>

using namespace std;

int main() {
    string a,b,c;
    getline(cin , a);
    getline(cin , b);
    getline(cin, c);

    //initializes character array
    char dif[27];
    for (int i = 0; i < 27; i++){
        dif[i] = '!';
    }

    //stores ciphertext keys
    for (int i = 0; i < b.length(); i++){
        if (b[i] == ' '){
            dif[b[i]-65] = ' ';
        }
        else{
            dif[b[i]-65] = a[i];
        }
    }

    //uses keys to decode ciphertext into plaintext
    for (int i = 0; i < c.length(); i++){
        if (dif[c[i]-65] != '!'){
            cout << dif[c[i]-65];
        }
        else{
            cout << '.';
        }
    }

}