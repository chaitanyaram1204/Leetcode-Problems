class Solution {
public:
    int solve(vector<int>& nums, int goal)
    {
        int prefix = 0;
        int start = 0,cnt = 0,end = 0;
        while(end<nums.size())
        {
            prefix += nums[end++];
            while(start<end && prefix >goal)
            {
                prefix -= nums[start++];
            }
            cnt += end-start;
        }
        return cnt;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return solve(nums,goal)-solve(nums,goal-1);
    }
};