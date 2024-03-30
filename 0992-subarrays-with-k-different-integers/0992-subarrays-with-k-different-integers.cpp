class Solution {
public:
     int solve(vector<int>& nums, int k) {
        int start = 0,end = 0,count = 0;
        unordered_map<int,int>mpp;
        while(end < nums.size())
        {
            mpp[nums[end]]++;
            while(mpp.size()>k && start<=end)
            {
                mpp[nums[start]]--;
                if(mpp[nums[start]] == 0)
                mpp.erase(nums[start]);
                start++;
            }
            count += (end-start +1);
            end++;
        }
        return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return solve(nums,k) - solve(nums,k-1);
    }
};