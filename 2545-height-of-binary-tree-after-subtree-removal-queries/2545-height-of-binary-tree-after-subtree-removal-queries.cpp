class Solution {
public:
    vector<int> level, depth, d1, d2;

    Solution() : level(100001, 0), depth(100001, 0), d1(100001, 0), d2(100001, 0) {}

    int dfs(TreeNode* root, int currentLevel) {
        if (root == nullptr) return 0;

        level[root->val] = currentLevel;
        int leftDepth = dfs(root->left, currentLevel + 1);
        int rightDepth = dfs(root->right, currentLevel + 1);

        depth[root->val] = 1 + max(leftDepth, rightDepth);

        if (depth[root->val] > d1[currentLevel]) {
            d2[currentLevel] = d1[currentLevel];
            d1[currentLevel] = depth[root->val];
        } else if (depth[root->val] > d2[currentLevel]) {
            d2[currentLevel] = depth[root->val];
        }

        return depth[root->val];
    }

    vector<int> treeQueries(TreeNode* root, vector<int>& query) {
        dfs(root, 0);
        vector<int> result;

        for (int i : query) {
            if (depth[i] == d1[level[i]]) {
                result.push_back(level[i] + d2[level[i]] - 1);
            } else {
                result.push_back(level[i] + d1[level[i]] - 1);
            }
        }
        
        return result;
    }
};
