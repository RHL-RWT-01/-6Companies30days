#include<bits/stdc++.h>
using namespace std;


  //Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 
class Solution {
public:
    TreeNode* find_infected(TreeNode* root, int data) {
        if (!root) return nullptr;
        if (root->val == data) return root;
        TreeNode* node = find_infected(root->left, data);
        if (node) return node;
        return find_infected(root->right, data);
    }

    void mark_parent(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parent) {
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if (node->left) {
                parent[node->left] = node;
                q.push(node->left);
            }
            if (node->right) {
                parent[node->right] = node;
                q.push(node->right);
            }
        }
    }

    int amountOfTime(TreeNode* root, int start) {
        if (!root) return 0;
        if (!root->left && !root->right) return 0; // Single-node tree case

        TreeNode* infected_node = find_infected(root, start);
        unordered_map<TreeNode*, TreeNode*> parent;
        mark_parent(root, parent);

        unordered_map<TreeNode*, bool> vis;
        queue<TreeNode*> q;
        q.push(infected_node);
        vis[infected_node] = true;

        int minutes = 0;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                if (node->left && !vis[node->left]) {
                    vis[node->left] = true;
                    q.push(node->left);
                }
                if (node->right && !vis[node->right]) {
                    vis[node->right] = true;
                    q.push(node->right);
                }
                if (parent.find(node) != parent.end() && !vis[parent[node]]) {
                    vis[parent[node]] = true;
                    q.push(parent[node]);
                }
            }
            minutes++;
        }

        return minutes - 1;
    }
};

int main(){
    // Create a binary tree
    Solution s;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    cout << s.amountOfTime(root, 2) << endl; // Output: 3
}