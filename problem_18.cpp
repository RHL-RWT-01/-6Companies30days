#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long sum = 0;      // to store the maximum sum
        long long curr = 0;     // to store the sum of the current window
        unordered_set<int> set; // to track distinct elements
        int i = 0;              // the left pointer of the window

        for (int j = 0; j < nums.size(); j++) {
            if(set.find(nums[j])==set.end()){
                curr+=nums[j];
                set.insert(nums[j]);
                
                if(j-i+1 == k){
                    sum=max(sum,curr);
                    curr-=nums[i];
                    set.erase(nums[i]);
                    i++;
                }
            }else{
                while(nums[i]!=nums[j]){
                    curr-=nums[i];
                    set.erase(nums[i]);
                    i++;
                }
                i++;
            }
        }

        return sum;
    }
};


int main(){
    Solution s;
    vector<int> nums = {1,-1,5,-2,3};
    int k = 3;
    cout << s.maximumSubarraySum(nums, k) << endl; // Output: 6
    
    return 0;
}