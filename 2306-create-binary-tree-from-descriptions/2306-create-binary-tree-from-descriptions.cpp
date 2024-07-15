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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int,TreeNode*> mp;
        unordered_map<int,bool> hasparent;

        for(auto description : descriptions ){
            int parent = description[0],child = description[1],isleft  = description[2];
            TreeNode* parentNode = NULL,*childNode = NULL;
            if(mp.find(parent) == mp.end()) parentNode = new TreeNode(parent);
            else parentNode = mp[parent];
            if(mp.find(child) == mp.end()) childNode = new TreeNode(child);
            else childNode = mp[child];

            if(isleft) parentNode->left = childNode;
            else parentNode->right = childNode;

            hasparent[child] = true;
            mp[child] = childNode;
            mp[parent] = parentNode;
        }

        TreeNode* root = NULL;
        for(auto & [value,node] : mp){
            if(!hasparent[value]) root= node;
        }
        return root;
    }
};