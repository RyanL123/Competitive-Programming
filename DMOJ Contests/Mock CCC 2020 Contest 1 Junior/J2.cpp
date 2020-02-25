#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    int k, u = 0, m = 0, cu, cm;
    cin >> cu >> cm >> k;
    while (k--){
        if ((u+1)*cu + (m*cm) > (u)*cu + ((m+1)*cm)){
            u++;
        }
        else {
            m++;
        }
    }
    cout << u*cu + m*cm << endl;
}