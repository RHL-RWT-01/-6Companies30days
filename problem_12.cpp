#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(const string &s, int mask) {
        string subseq = "";
        for (int i = 0; i < s.size(); i++) {
            if (mask & (1 << i)) {
                subseq += s[i];
            }
        }
        int left = 0, right = subseq.size() - 1;
        while (left < right) {
            if (subseq[left++] != subseq[right--]) return false;
        }
        return true;
    }
    
    int maxProduct(string s) {
        int n = s.size();
        int maxProduct = 0;
        unordered_map<int, int> palinLength;
        
        // Check all subsequences
        for (int mask = 1; mask < (1 << n); mask++) {
            if (isPalindrome(s, mask)) {
                int length = __builtin_popcount(mask); // Number of set bits = length of subsequence
                palinLength[mask] = length;
            }
        }
        
        // Compare all pairs of disjoint subsequences
        for (const auto &pair1 : palinLength) {
               int mask1=pair1.first;
                int len1=pair1.second;
            for (const auto &pair2 : palinLength) {
                 int mask2=pair2.first;
                int len2=pair2.second;
                if ((mask1 & mask2) == 0) { // Disjoint subsequences
                    maxProduct = max(maxProduct, len1 * len2);
                }
            }
        }
        
        return maxProduct;
    }
};

int main(){
    Solution s;
    string str = "leetcodecom";
    cout << s.maxProduct(str) << endl; // Output: 9
    return 0;
}