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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1) {
      TreeNode* newHead = new TreeNode(val);
      newHead->left = root;
      return newHead;
    } else if (!root) {
      return nullptr;
    }

    vector<TreeNode*> currentLevel = {root};
    int level = 2;

    while (!currentLevel.empty()) {
      if (level == depth) {
        for (TreeNode* node : currentLevel) {
          TreeNode* newLeft = new TreeNode(val, node->left, nullptr);
          node->left = newLeft;
          TreeNode* newRight = new TreeNode(val, nullptr, node->right);
          node->right = newRight;
        }
        break;
      }

      vector<TreeNode*> nextLevel;
      for (TreeNode* node : currentLevel) {
        if (node->left) nextLevel.push_back(node->left);
        if (node->right) nextLevel.push_back(node->right);
      }
      currentLevel = nextLevel;
      level++;
    }

    return root;
    }
};