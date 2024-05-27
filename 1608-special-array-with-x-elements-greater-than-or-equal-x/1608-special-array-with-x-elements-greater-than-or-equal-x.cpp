class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(nums.rbegin(),nums.rend());
        int count = 0;
        for(int i = 0;i<nums.size();i++)
        {
            if(nums[i] >= count)
            {
                count++;
                if(count > nums[i]) return -1;
            }
            else
            {
                return count;
            }
        }
        return nums.size();
    }
};