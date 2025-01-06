#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string matrixChainOrder(vector<int>& arr) {
        int n = arr.size() - 1;  // Number of matrices
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
        vector<vector<int>> brackets(n, vector<int>(n, -1));
        
        // Base case: cost is zero for single matrices
        for (int i = 0; i < n; i++) dp[i][i] = 0;
        
        for (int len = 2; len <= n; len++) { // len is chain length
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1;
                for (int k = i; k < j; k++) {
                    int cost = dp[i][k] + dp[k+1][j] + arr[i] * arr[k+1] * arr[j+1];
                    if (cost < dp[i][j]) {
                        dp[i][j] = cost;
                        brackets[i][j] = k;
                    }
                }
            }
        }
        
        return buildOrder(brackets, 0, n-1);
    }
    
    string buildOrder(vector<vector<int>>& brackets, int i, int j) {
        if (i == j) {
            return string(1, 'A' + i);  
        }
        int k = brackets[i][j];
        return "(" + buildOrder(brackets, i, k) + buildOrder(brackets, k+1, j) + ")";
    }
};

int main(){
    Solution s;
    vector<int> arr = {40, 20, 30, 10, 30};
    cout << s.matrixChainOrder(arr);  // Output: ((A(BC))D)
    return 0;
}