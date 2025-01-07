#include <string>
#include <queue>
#include <sstream>
#include <vector>
#include <iostream>
using namespace std;


//   Definition for a binary tree node.
  struct TreeNode {
      int val;
     TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 };
 

class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return "";  // Handle null root

        string ans;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if (node) {
                ans += to_string(node->val) + ",";  // Serialize node value
                q.push(node->left);   // Add left child (can be null)
                q.push(node->right);  // Add right child (can be null)
            } else {
                ans += "null,";  // Mark null nodes explicitly
            }
        }

        // Remove trailing comma
        if (!ans.empty()) ans.pop_back();

        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty()) return nullptr;  // Handle empty string

        vector<string> nodes;
        stringstream ss(data);
        string token;

        // Split the serialized string into tokens
        while (getline(ss, token, ',')) {
            nodes.push_back(token);
        }

        // Create the root node from the first token
        TreeNode* root = new TreeNode(stoi(nodes[0]));
        queue<TreeNode*> q;
        q.push(root);

        int i = 1;  // Index to track position in nodes vector
        while (!q.empty() && i < nodes.size()) {
            TreeNode* curr = q.front();
            q.pop();

            // Process left child
            if (nodes[i] != "null") {
                curr->left = new TreeNode(stoi(nodes[i]));
                q.push(curr->left);
            }
            i++;

            // Process right child if within bounds
            if (i < nodes.size() && nodes[i] != "null") {
                curr->right = new TreeNode(stoi(nodes[i]));
                q.push(curr->right);
            }
            i++;
        }

        return root;
    }
};

// Main function to demonstrate usage
int main() {
    Codec codec;

    // Create a sample tree: 
    //     1
    //    / \
    //   2   3
    //      / \
    //     4   5
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);

    // Serialize the tree
    string serializedTree = codec.serialize(root);
    cout << "Serialized tree: " << serializedTree << endl;

    // Deserialize the tree
    TreeNode* deserializedRoot = codec.deserialize(serializedTree);

    // Serialize again to verify
    string verifySerializedTree = codec.serialize(deserializedRoot);
    cout << "Verified serialized tree: " << verifySerializedTree << endl;

    return 0;
}