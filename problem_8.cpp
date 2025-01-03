#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(vector<int>& nums, int k) {
        if (k < 0) {
            return 0;
        }
        int l = 0;
        int r = 0;
        int n = nums.size();
        int count = 0;
        int subcount = 0;
        while (r < n) {
            if (nums[r] % 2 != 0) {
                count++;
            }
            while (count > k) {
                if (nums[l] % 2 != 0) {
                    count--;
                }
                l++;
            }
            subcount += (r - l + 1);
            r++;
        }
        return subcount;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return solve(nums, k) - solve(nums, k - 1);
    }
};

int main(){
    Solution s;
    vector<int> nums = {1,1,2,1,1};
    int k = 3;
    cout << s.numberOfSubarrays(nums, k) << endl; // Output: 10
    return 0;
}