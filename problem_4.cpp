#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int m = img.size(), n = img[0].size();
        vector<vector<int>> result(m, vector<int>(n, 0));

        // Directions for moving in the 3x3 grid
        vector<int> dx = {-1, -1, -1, 0, 0, 0, 1, 1, 1};
        vector<int> dy = {-1, 0, 1, -1, 0, 1, -1, 0, 1};

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int sum = 0, count = 0;

                // Explore the 3x3 grid around (i, j)
                for (int k = 0; k < 9; k++) {
                    int x = i + dx[k];
                    int y = j + dy[k];

                    // Check if (x, y) is within bounds
                    if (x >= 0 && x < m && y >= 0 && y < n) {
                        sum += img[x][y];
                        count++;
                    }
                }

                result[i][j] = sum / count;
            }
        }

        return result;
    }
};

int main(){
    vector<vector<int>> img = {{1,1,1},{1,0,1},{1,1,1}};
    Solution s;
    vector<vector<int>> result = s.imageSmoother(img);
    cout << "Smoothened image is: " << endl;
    for (auto row : result) {
        for (int pixel : row) {
            cout << pixel << " ";
        }
        cout << endl;
    }
    return 0;
}