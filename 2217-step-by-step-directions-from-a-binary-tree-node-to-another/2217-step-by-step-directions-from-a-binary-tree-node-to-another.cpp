/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* lcs(TreeNode* root, int startValue, int destValue) {
        if (root == NULL || root->val == startValue || root->val == destValue) {
            return root;
        }
        TreeNode* left = lcs(root->left, startValue, destValue);
        TreeNode* right = lcs(root->right, startValue, destValue);

        if (left == NULL)
            return right;
        if (right == NULL)
            return left;
        return root;
    }

    bool solve(TreeNode* root, int target, string& path, int result) {
        if (root == NULL)
            return 0;
        if (root->val == target)
            return 1;

        path += result ? 'U' : 'L';
        if (solve(root->left, target, path, result))
            return 1;
        path.pop_back();

        path += result ? 'U' : 'R';
        if (solve(root->right, target, path, result))
            return 1;
        path.pop_back();

        return 0;
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        root = lcs(root, startValue, destValue);
        string fromPath = "", toPath = "";
        solve(root, startValue, fromPath, 1);
        solve(root, destValue, toPath, 0);
        return fromPath + toPath;
    }
};