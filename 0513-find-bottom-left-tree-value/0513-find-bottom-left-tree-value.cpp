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
   
    void help(TreeNode* &root,pair<int,int>&ans,int level)
    {
        if(!root) return;
        if(level == ans.second){
        ans.first=root->val;
        ans.second++;
        }
        help(root->left,ans,level+1);
        help(root->right,ans,level+1);
    }
     int findBottomLeftValue(TreeNode* root) {
        pair<int,int>ans{0,0};
        if(!root) return 0;
        help(root,ans,0);
        return ans.first;
    }
};