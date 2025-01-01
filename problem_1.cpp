#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1,
                      int x2, int y2) {
        int closestX = max(x1, min(xCenter, x2));
        int closestY = max(y1, min(yCenter, y2));

        int x = xCenter - closestX;
        int y = yCenter - closestY;
        int dis = x * x + y * y;

        return dis <= radius * radius;
    }
};

int main(){

    Solution s;
    cout << s.checkOverlap(1, 0, 0, 1, -1, 3, 1) << endl;

}