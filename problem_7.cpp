#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls = 0, cows = 0;
        vector<int> sFreq(10, 0), gFreq(10, 0);
        for (int i = 0; i < secret.length(); i++) {
            if (secret[i] == guess[i]) {
                bulls++;
            } else {
                sFreq[secret[i] - '0']++;
                gFreq[guess[i] - '0']++;
            }
        }

        for (int i = 0; i < 10; i++) {
            cows += min(sFreq[i], gFreq[i]);
        }
        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};

int main(){
    Solution s;
    cout<<s.getHint("1807","7810")<<endl;

    return 0;
}