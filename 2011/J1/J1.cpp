#include <iostream>

using namespace std;

int main(){
    int a, e;
    cin >> a >> e;

    bool t = false, v = false, g = false;
    if(a >= 3 && e <=4){
        t = !t;
    }
    if (a <= 6 && e >= 2){
        v = !v;
    }
    if (a <= 2 && e <=3){
        g = !g;
    }

    if (t){
        cout << "TroyMartian\n";
    }
    if (v){
        cout << "VladSaturnian\n";
    }
    if(g){
        cout << "GraemeMercurian\n";
    }
}
