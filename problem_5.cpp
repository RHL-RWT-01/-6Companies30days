#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int med=nums[n/2];
        int moves=0;
        for(int num: nums){
            moves+=abs(med-num);
        }
        return moves;
    }
};
int main(){
    Solution s;
    vector<int> nums={1,2,3,4,5};
    cout<<s.minMoves2(nums)<<endl;
    return 0;
}