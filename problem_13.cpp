#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        vector<int> sorted(nums);
        sort(sorted.begin(), sorted.end());
        int n = nums.size();

        int j = (n - 1) / 2; // Midpoint for smaller half
        int k = n - 1;       // End for larger half

        // Place small elements at even indices and large elements at odd
        // indices
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                nums[i] = sorted[j--];
            } else {
                nums[i] = sorted[k--];
            }
        }
    }
};

int main(){
    Solution s;
    vector<int> nums = {3, 5, 2, 1, 6, 4};
    s.wiggleSort(nums);
    for(int num : nums) cout << num << " "; // Output: 3 5 1 6 2 4
    return 0;
}