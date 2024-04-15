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
    int sum =0;
    void solve(TreeNode* root,int ans)
    {
        if(root == NULL)
        {
            return;
        }
        ans = ans*10 + root->val;
        if(!root->left && !root->right)
        {
            sum += ans;
        }
        solve(root->left,ans);
        solve(root->right,ans);
    }
    int sumNumbers(TreeNode* root) {
        solve(root,0);
        return sum;
    }
};