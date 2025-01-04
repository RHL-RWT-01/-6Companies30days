#include<bits/stdc++.h>
using namespace std;

struct VectorHash {
    size_t operator()(const vector<int>& vec) const {
        size_t hash = 0;
        for (int num : vec) {
            hash = hash * 31 + num;  // Using 31 as a multiplier (common in hash functions)
        }
        return hash;
    }
};

class Solution {
public:
    unordered_map<vector<int>, int, VectorHash> memo;  // Use custom hash

    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        return minCost(price, special, needs);
    }

private:
    int minCost(vector<int>& price, vector<vector<int>>& special, vector<int> needs) {
        if (memo.count(needs)) return memo[needs];  // Return cached result if available

        int cost = 0;
        for (int i = 0; i < needs.size(); ++i) {
            cost += needs[i] * price[i];  // Cost without any offers
        }

        for (const auto& offer : special) {
            vector<int> remaining = needs;
            bool valid = true;

            for (int i = 0; i < needs.size(); ++i) {
                remaining[i] -= offer[i];
                if (remaining[i] < 0) {
                    valid = false;
                    break;
                }
            }

            if (valid) {
                cost = min(cost, offer.back() + minCost(price, special, remaining));
            }
        }

        memo[needs] = cost;  
        return cost;
    }
};

int main(){
    Solution s;
    vector<int> price = {2,5};
    vector<vector<int>> special = {{3,0,5},{1,2,10}};
    vector<int> needs = {3,0,5};
    cout << s.shoppingOffers(price, special, needs) << endl;  // Output: 14
    return 0;
    
}