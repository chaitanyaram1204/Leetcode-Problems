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
    bool isEvenOddTree(TreeNode* root) {
        if(!root) return true;
         queue<TreeNode*> q;
        bool checker = true; // Use bool instead of int for clarity
        q.push(root);
        
        while (!q.empty()) {
            int prev = checker ? INT_MIN : INT_MAX; // Initialize prev according to checker
            int n = q.size();
            
            for (int i = 0; i < n; i++) {
                TreeNode* node = q.front();
                q.pop();
                
                if ((checker && (node->val <= prev || node->val % 2 == 0)) || (!checker && (node->val >= prev || node->val % 2 == 1))) {
                    return false;
                }
                
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
                
                prev = node->val;
            }
            checker = !checker; 
        }
        return true;
    }
};