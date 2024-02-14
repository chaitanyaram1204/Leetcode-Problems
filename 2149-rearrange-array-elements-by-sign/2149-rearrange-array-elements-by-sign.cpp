class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int>nums1,nums2,ans;
        for(int i = 0;i<nums.size();i++)
        {
            if(nums[i] < 0) nums2.push_back(nums[i]);
            else nums1.push_back(nums[i]);
        }
        for(int i =0;i<nums.size()/2;i++)
        {
            ans.push_back(nums1[i]);
            ans.push_back(nums2[i]);
        }
        return ans;
    }
};