#include <iostream>

using namespace std;

int main(){
    int a,b,c,d,s;
    int n = 0, y = 0;
    cin >> a >> b >> c >> d >> s;
    int a1 = a, b1 = b, c1 = c, d1 = d;

    for (int i = 0; i < s; i++){
        if (a1 != 0){
            n++;
            a1--;
        }
        else if (a1 == 0){
            n--;
            b1--;
            if (b1 == 0){
                a1 = a;
                b1 = b;
            }
        }
    }
    for (int i = 0; i < s; i++){
        if (c1 != 0){
            y++;
            c1--;
        }
        else if (c1 == 0){
            y--;
            d1--;
            if (d1 == 0){
                c1 = c;
                d1 = d;
            }
        }
    }

    if (n > y){
        cout << "Nikky";
    }
    else if(n < y){
        cout << "Byron";
    }
    else{
        cout << "Tied";
    }

}
