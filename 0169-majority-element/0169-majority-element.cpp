class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int major_index = 0;
        int count = 0;
        for(int i = 0;i<nums.size();i++)
        {
            if(nums[major_index] == nums[i])
            {
                count++;
            }
            else
            {
                count--;
                if(count == 0)
                {
                    major_index = i;
                    count = 1;
                }
            }
        }
        return nums[major_index];
    }
};