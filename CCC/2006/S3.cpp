#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

bool intersect(double x1, double x2, double y1, double y2,
                double slope, double b, double lowerX, double upperX,
                double lowerY, double upperY){
    // Vertical line
    if (x1 == x2){
        // Not in range of x
        if (x1 < lowerX || x1 > upperX){
            return false;
        }
        else {
            double intersectY = slope*x1+b;
            return intersectY <= max(y1, y2) && intersectY >= min(y1, y2) && intersectY <= upperY &&
                   intersectY >= lowerY;
            // Not in range of Y
        }
    }
    double slope2 = (y1-y2)/(x1-x2);
    double b2 = y1-(slope2*x1);
    // Parallel with no intersections
    if (slope == slope2 && b != b2){
        return false;
    }
    // Parallel with infinite intersections
    else if (slope == slope2 && b == b2 && min(x1,x2) >= lowerX && max(x1,x2) <= upperX){
        return true;
    }
    // If intersection is within overlap
    double intersectX = (b2 - b)/(slope-slope2);
    return intersectX <= max(x1, x2) && intersectX >= min(x1,x2) && intersectX <= upperX && intersectX >= lowerX;
}

int main() {
    double x1, y1, x2, y2;
    int n, overlap = 0;
    cin >> x1 >> y1 >> x2 >> y2 >> n;
    double slope = (y1-y2)/(x1-x2);
    double b = y1-(slope*x1);
    double lowerX, upperX;
    upperX = max(x1, x2);
    lowerX = min(x1, x2);
    double upperY, lowerY;
    upperY = max(y1, y2);
    lowerY = min(y1, y2);
    while (n--){
        int corner;
        cin >> corner;
        double prevX, prevY, initialX, initialY;
        cin >> initialX >> initialY;
        prevX = initialX;
        prevY = initialY;
        corner--;
        bool cross = false;
        while (corner--){
            double x, y;
            cin >> x >> y;
            if (x1 == x2){
                if (prevX <= x1 && x >= x1 && y <= max(y1, y2) && y >= min(y1,y2)){
                    cross = true;
                }
            }
            if (intersect(prevX, x, prevY, y, slope, b, lowerX, upperX, lowerY, upperY)){
                cross = true;
            }
            prevX = x;
            prevY = y;
        }
        if (prevX <= x1 && initialX >= x1 && initialY <= max(y1, y2) && initialY >= min(y1,y2)){
            cross = true;
        }
        if (intersect(prevX, initialX, prevY, initialY, slope, b, lowerX, upperX, lowerY, upperY)){
            cross = true;
        }
        if (cross){
            overlap++;
        }
    }
    cout << overlap;
}
