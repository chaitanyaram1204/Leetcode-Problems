class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long int ans = 0;
        int i = 0;
        int size = nums.size();
        long int maxNum = 0;
        while(maxNum < n)
        {
            if(i < size && maxNum+1 >= nums[i])
            {
                maxNum += nums[i];
                i++;
            }
            else
            {
                ans++;
                maxNum += maxNum + 1;
            }
        }

        return ans;
    }
};