class Solution {
public:
    int x(vector<int> &nums){
        int n = nums.size();
        int prev=nums[0];
        int prev2=0;
        for(int i = 0;i<n;i++)
        {
            int not_pick;
            int pick=nums[i];
            if(i>1)
            pick +=prev2;
            not_pick = prev;
            int curr = max(pick,not_pick);
            prev2=prev;
            prev = curr;
        }
        return prev;
    }
    int rob(vector<int>& nums) {
        return x(nums);
    }
};