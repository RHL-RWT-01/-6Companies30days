#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
       unordered_map<char,int> mp;
       
       // First pass: Count the frequencies of each character
       for(char ch : s) {
           mp[ch]++;
       }

       // Second pass: Find the first character with frequency 1
       for(int i = 0; i < s.size(); i++) {
           if(mp[s[i]] == 1) {
               return i;  // Return the index of the first unique character
           }
       }

       return -1;  // No unique character found
    }
};

int main(){
    Solution s;
    string str = "Engineering";
    cout << s.firstUniqChar(str);  // Output: 7 (index of 'r')
    return 0;
}
