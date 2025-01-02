#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> rects;   // Store the rectangles
    vector<int> cumulative_area; // Store the cumulative area of rectangles
    int total_area;              // Store the total area of all rectangles

    Solution(vector<vector<int>>& rects):rects(rects) {
        total_area = 0;

        for (auto& rect : rects) {
            int x1 = rect[0], y1 = rect[1], x2 = rect[2], y2 = rect[3];
            int area =
                (x2 - x1 + 1) *
                (y2 - y1 + 1);  //area of current rectangle
            total_area += area; //the total area
            cumulative_area.push_back(
                total_area); // Add it to cumulative list
        }
    }

    vector<int> pick() {
        int target = rand() % total_area;
        int low = 0, high = cumulative_area.size() - 1;
        while (low < high) {
            int mid = (low + high) / 2;
            if (cumulative_area[mid] <= target) {
                low = mid + 1;
            } else {
                high = mid; 
            }
        }

        int x1 = rects[low][0], y1 = rects[low][1], x2 = rects[low][2],
            y2 = rects[low][3];

        int prev_area = (low > 0) ? cumulative_area[low - 1] : 0;
        int point_index =
            target -
            prev_area; 
        int width = x2 - x1 + 1;
        int u = x1 + point_index % width;
        int v = y1 + point_index / width;

        return {u, v}; 
    }
};


int main(){
    vector<vector<int>> rects = {{1,1,3,3},{3,1,4,2},{3,2,4,4},{1,3,2,4},{2,3,3,4}};
    Solution solution(rects);
    vector<int> pick = solution.pick();
    cout << pick[0] << " " << pick[1] << endl;
    return 0;
}