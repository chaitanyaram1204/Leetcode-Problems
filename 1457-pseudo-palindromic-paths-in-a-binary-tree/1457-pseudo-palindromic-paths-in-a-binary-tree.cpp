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
    int digits[10];
    bool isPalindrome()
    {
        int odd = 0;
        for(int i =0;i<=9;i++)
        {
            if(digits[i]%2 != 0)
            {
                odd++;
            }
        }
        if(odd > 1) return false;
        return true;
    }
    void dfs(TreeNode* root,int &res)
    {
        if(root == NULL) return;
        digits[root->val]++;
        if(!root->left && !root->right){
            if(isPalindrome()) res++;
        }
        else
        {
            dfs(root->left,res);
            dfs(root->right,res);
        }
        digits[root->val]--;
        
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        int result = 0;
        dfs(root,result);
        return result;
    }
};