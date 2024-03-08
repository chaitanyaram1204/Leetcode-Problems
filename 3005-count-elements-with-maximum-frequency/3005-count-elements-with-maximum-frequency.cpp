class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int>mp;
        int maxi = 0;
        for(int i =0;i<nums.size();i++)
        {
            maxi = max(maxi,++mp[nums[i]]);
        }
        int ans = 0;
        for(auto &i : mp)
        {
            if(i.second == maxi)
            {
                ans+=maxi;
            }
        }
        return ans;
    }
};