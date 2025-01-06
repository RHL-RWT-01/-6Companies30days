#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> maxOfSubarrays(vector<int>& nums, int k) {
       deque<int> dq;  // Stores indices of elements in the current window
        vector<int> result;
        
        for (int i = 0; i < nums.size(); i++) {
            if (!dq.empty() && dq.front() == i - k) {
                dq.pop_front();
            }
            
            while (!dq.empty() && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }
            
            dq.push_back(i);
            
            if (i >= k - 1) {
                result.push_back(nums[dq.front()]);
            }
        }
        
        return result;
    }
    
};
int main(){
    Solution s;
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
    vector<int> res = s.maxOfSubarrays(nums, k);
    for(int i: res) cout<<i<<" ";
    return 0;
}