class Solution {
public:
    void solve(int i,vector<int>&ds,vector<int>&nums,vector<vector<int>>&res)
    {
        if(i == nums.size())
        {
            res.push_back(ds);
            return;
        }

        solve(i+1,ds,nums,res);
        ds.push_back(nums[i]);
        solve(i+1,ds,nums,res);
        ds.pop_back();

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>res;
        vector<int>ds;
        solve(0,ds,nums,res);
        return res;
    }
};