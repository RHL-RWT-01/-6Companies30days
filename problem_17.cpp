#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int ans=0;
        int n=arr.size();
        if(arr.size()<3)return ans;

        for(int i=1;i<n-1;i++){
            if(arr[i]>arr[i-1] && arr[i]>arr[i+1]){
                int left=i-1;
                while(left>0 && arr[left]>arr[left-1]){
                    left--;
                }
                int right=i+1;
                while(right<n-1 && arr[right]>arr[right+1]){
                    right++;
                }
                ans=max(ans,right-left+1);
                i=right-1;
            }
        }
        return ans;
    }
};

int main(){
    Solution s;
    vector<int> arr={2,1,4,7,3,2,5};
    cout<<s.longestMountain(arr)<<endl; // Output: 5

    return 0;
}