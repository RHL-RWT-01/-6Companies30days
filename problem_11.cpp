#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isStrictlyIncreasing(const vector<int>& nums) {
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] <= nums[i-1]) {
                return false;
            }
        }
        return true;
    }

    int incremovableSubarrayCount(vector<int>& nums) {
        int n = nums.size();
        int result = 0;

        // Iterate over all possible subarrays
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                // Create a new array excluding the subarray nums[i..j]
                vector<int> remaining;
                
                // Add the prefix part
                for (int k = 0; k < i; ++k) {
                    remaining.push_back(nums[k]);
                }

                // Add the suffix part
                for (int k = j + 1; k < n; ++k) {
                    remaining.push_back(nums[k]);
                }

                // Check if the remaining array is strictly increasing
                if (isStrictlyIncreasing(remaining)) {
                    result++;
                }
            }
        }

        return result;
    }
    
};

int main(){
    Solution s;
    vector<int> nums = {1,2,3,4};
    cout << s.incremovableSubarrayCount(nums) << endl; // Output: 6
    return 0;
}