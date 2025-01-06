#include<bits/stdc++.h>
using namespace std;

struct TrieNode {
    map<char, TrieNode*> children;
    set<string> words;  // Store unique contacts that share this prefix
    bool isEndOfWord = false;
};

class Solution {
private:
    TrieNode* root;

    // Function to insert a contact into the Trie
    void insert(string contact) {
        TrieNode* node = root;
        for (char c : contact) {
            if (!node->children.count(c)) {
                node->children[c] = new TrieNode();
            }
            node = node->children[c];
            node->words.insert(contact);  // Store all words for current prefix
        }
        node->isEndOfWord = true;
    }

    // Function to find matching contacts for a given prefix
    vector<string> search(string prefix) {
        TrieNode* node = root;
        for (char c : prefix) {
            if (!node->children.count(c)) {
                return {"0"};  // Return "0" if prefix not found
            }
            node = node->children[c];
        }
        vector<string> result(node->words.begin(), node->words.end());
        return result;
    }

public:
    Solution() {
        root = new TrieNode();
    }

    vector<vector<string>> displayContacts(int n, string contact[], string s) {
        // Insert all contacts into the Trie
        for (int i = 0; i < n; i++) {
            insert(contact[i]);
        }
        
        vector<vector<string>> result;
        string prefix = "";
        
        // Query for each prefix of 's'
        for (char c : s) {
            prefix += c;
            vector<string> matches = search(prefix);
            result.push_back(matches);
        }
        
        return result;
    }
};

int main(){
    Solution s;
    int n = 5;
    string contact[] = {"All", "Alaska", "Alto", "Alsy", "Albert"};
    string str = "AlS";
    vector<vector<string>> result = s.displayContacts(n, contact, str);
    for (auto row : result) {
        for (string contact : row) {
            cout << contact << " ";
        }
        cout << endl;
    }
    return 0;
}