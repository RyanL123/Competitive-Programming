#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>

using namespace std;

int main() {
    string s;
    cin >> s;
    int distance = 240;
    int hour = (s[0]-48)*10 + (s[1]-48);
    int minutes = (s[3]-48)*10 + (s[4]-48);
    while (distance > 0){
        if (hour >= 7 && hour < 10){
            distance--;
        }
        else if (hour >= 15 && hour < 19){
            distance--;
        }
        else {
            distance-=2;
        }
        minutes++;
        if (minutes == 60){
            minutes = 0;
            hour++;
        }
    }
    while (minutes >= 60){
        minutes -= 60;
        hour++;
    }
    if (hour >= 24){
        hour -= 24;
    }
    printf("%02d:%02d", hour, minutes);
}