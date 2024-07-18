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
    int numberOfGoodPairs = 0;
    vector<int> solve(TreeNode* root, int distance) {
        if (root == NULL) {
            return {};
        }

        if (root->left == NULL && root->right == NULL) {
            return {1};
        }

        vector<int> left = solve(root->left, distance);
        vector<int> right = solve(root->right, distance);

        for (auto first : left) {
            for (auto second : right) {
                if (first + second <= distance) {
                    numberOfGoodPairs++;
                }
            }
        }

        vector<int> parent;

        for (auto first : left) {
            if (first + 1 < distance) {
                parent.push_back(first + 1);
            }
        }
        for (auto first : right) {
            if (first + 1 < distance) {
                parent.push_back(first + 1);
            }
        }

        return parent;
    }
    int countPairs(TreeNode* root, int distance) {
        solve(root, distance);
        return numberOfGoodPairs;
    }
};