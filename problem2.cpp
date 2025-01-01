#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int find(int n,int k){
        int ans = 0;
        for(int i=1; i<=n; i++){
            ans = (ans + k) % i;
        }
        return ans;
    }
    int findTheWinner(int n, int k) {
        return find(n,k)+1;
    }
};
int main(){
    Solution s;
    cout<<s.findTheWinner(3, 6)<<endl;
    return 0;
}