/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void solve(vector<TreeNode*>nodes){
        if(nodes.empty()) return;

        int sum = 0;
        for(auto node : nodes){
            //if(!node) continue;
            if(node->left) sum += node->left->val;
            if(node->right) sum += node->right->val;
        }

        vector<TreeNode*>childNodes;

        for(auto node : nodes){
            int cursum = 0;
            if(node->left) cursum += node->left->val;
            if(node->right) cursum += node->right->val;

            if(node->left){
                node->left->val = sum - cursum;
                childNodes.push_back(node->left);
            }
            if(node->right){
                node->right->val = sum - cursum;
                childNodes.push_back(node->right);
            }
        }

        solve(childNodes);
    }
    TreeNode* replaceValueInTree(TreeNode* root) {
        root->val = 0;
        vector<TreeNode*>nodes{root};
        solve(nodes);
        return root;
    }
};