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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        queue<TreeNode*>q;
        vector<long long int>sumes;
        //sumes.push_back(root->val);
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            long long int temp = 0;
            for(int i = 0; i < size; i++){
                root = q.front();
                q.pop();
                temp += root->val;
                if(root->left) q.push(root->left);
                if(root->right) q.push(root->right);
            }
            sumes.push_back(temp);
        }
        if(k > sumes.size()) return -1;
        sort(sumes.begin(),sumes.end(),greater<long long int>());
        return sumes[k-1];
    }
};