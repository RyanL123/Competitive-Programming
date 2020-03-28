#include <iostream>

using namespace std;

int main() {
    while (true){
        int count = 0;
        int r;
        cin >> r;
        if (r==0){
            break;
        }
        for (int i = 0; i <= r; i++){
            for (int j = 0; j <= r; j++){
                if ((i*i)+(j*j) <= (r*r)){
                    count++;
                }
            }
        }
        count = ((count*4)-((r+1)*3))-r;
        cout << count << endl;
    }
}
