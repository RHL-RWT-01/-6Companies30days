#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string>ans;
        if(s.length()<10)return ans;

        unordered_map<string,int>mp;
        for(int i=0; i<=s.length()-10;i++){
            string str=s.substr(i,10);
            mp[str]++;
        }
        
        for(auto it: mp){
            if(it.second>1){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};

int main(){
    Solution s;
    string str="AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
    vector<string>res=s.findRepeatedDnaSequences(str);
    for(auto& i: res){
        cout<<i<<endl;
    }
    return 0;
}