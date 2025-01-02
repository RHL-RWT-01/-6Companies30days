#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(),envelopes.end(),[](const vector<int>&a, const vector<int>&b){
            return a[0]<b[0] || (a[0]==b[0] && a[1]>b[1]);
        });

        vector<int>heights;
        for(auto& envelop: envelopes){
            heights.push_back(envelop[1]);
        }

        vector<int>lis;

        for(int height: heights){
            auto it=lower_bound(lis.begin(),lis.end(),height);
            if(it==lis.end())lis.push_back(height);
            else *it=height;
        }
        return lis.size();
    }
};

int main(){
    Solution s;
    vector<vector<int>>envelopes={{5,4},{6,4},{6,7},{2,3}};
    cout<<s.maxEnvelopes(envelopes)<<endl;
   
    return 0;
}