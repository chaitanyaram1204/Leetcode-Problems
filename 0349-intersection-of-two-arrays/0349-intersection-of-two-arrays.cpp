class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans;
        unordered_map<int,int>mp;
        for(auto &i :nums1)
        {
            mp[i]++;
        }
        for(int i = 0;i<nums2.size();i++)
        {
            if(mp.find(nums2[i]) != mp.end())
            {
                ans.push_back(nums2[i]);
                mp.erase(nums2[i]);
            }
        }
        return ans;
    }
};